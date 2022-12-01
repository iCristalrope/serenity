/*
 * Copyright (c) 2019-2020, Ryan Grieb <ryan.m.grieb@gmail.com>
 * Copyright (c) 2022, the SerenityOS developers.
 * Copyright (c) 2022, Olivier De Cannière <olivier.decanniere96@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "EventDialog.h"
#include <AK/DateConstants.h>
#include <Applications/Calendar/CalendarEventGML.h>
#include <LibCore/DateTime.h>
#include <LibGUI/BoxLayout.h>
#include <LibGUI/Button.h>
#include <LibGUI/ComboBox.h>
#include <LibGUI/ItemListModel.h>
#include <LibGUI/Painter.h>
#include <LibGUI/SpinBox.h>
#include <LibGUI/TextBox.h>
#include <LibGUI/Widget.h>
#include <LibGUI/Window.h>
#include <LibGfx/Color.h>

void EventDialog::update_last_day_of_month() const
{
    auto date_time = Core::DateTime::create(m_year_spinbox->value(), m_month_combobox->selected_index() + 1);
    m_day_spinbox->set_max(date_time.days_in_month());
}

EventDialog::EventDialog(Core::DateTime date_time, Window* parent_window)
    : Dialog(parent_window)
{
    resize(350, 420);
    set_resizable(false);
    set_title("Add Event");
    set_icon(parent_window->icon());

    auto& main_widget = set_main_widget<GUI::Widget>();
    if (!main_widget.load_from_gml(calendar_event_gml))
        VERIFY_NOT_REACHED();

    m_title_textbox = *main_widget.find_descendant_of_type_named<GUI::TextBox>("title");
    m_description_editor = *main_widget.find_descendant_of_type_named<GUI::TextEditor>("description");
    m_event_color_input = *main_widget.find_descendant_of_type_named<GUI::ColorInput>("color");
    m_month_combobox = *main_widget.find_descendant_of_type_named<GUI::ComboBox>("month");
    m_day_spinbox = *main_widget.find_descendant_of_type_named<GUI::SpinBox>("day");
    m_year_spinbox = *main_widget.find_descendant_of_type_named<GUI::SpinBox>("year");
    m_hour_spinbox = *main_widget.find_descendant_of_type_named<GUI::SpinBox>("hour");
    m_minute_spinbox = *main_widget.find_descendant_of_type_named<GUI::SpinBox>("minute");
    m_ok_button = *main_widget.find_descendant_of_type_named<GUI::Button>("ok_button");
    m_cancel_button = *main_widget.find_descendant_of_type_named<GUI::Button>("cancel_button");
    m_delete_button = *main_widget.find_descendant_of_type_named<GUI::Button>("delete_button");

    m_month_combobox->set_model(*GUI::ItemListModel<StringView, Array<StringView, 12>>::create(AK::long_month_names));
    m_event_color_input->set_color_picker_title("Event Color");
    m_event_color_input->set_color(Color::MidBlue);
    m_month_combobox->set_selected_index(date_time.month() - 1);
    m_day_spinbox->set_value(date_time.day());
    m_year_spinbox->set_value(date_time.year());
    m_hour_spinbox->set_value(date_time.hour());
    m_minute_spinbox->set_value(date_time.minute());
    m_ok_button->set_enabled(false);
    m_delete_button->set_visible(false);

    m_year_spinbox->on_change = [this](auto) { update_last_day_of_month(); };
    m_month_combobox->on_change = [this](auto, auto) { update_last_day_of_month(); };
    m_day_spinbox->on_change = [this](auto) { update_last_day_of_month(); };
    m_title_textbox->on_change = [this]() { m_ok_button->set_enabled(!m_title_textbox->text().is_empty()); };

    m_ok_button->on_click = [this](auto) {
        // FIXME: Save created event
        auto title = m_title_textbox->text();
        auto date_time = Core::DateTime::create(m_year_spinbox->value(), m_month_combobox->selected_index() + 1, m_day_spinbox->value(), m_hour_spinbox->value(), m_minute_spinbox->value());
        dbgln("TODO save event '{}' at {}", title, date_time.to_string());
        done(GUI::Dialog::ExecResult::OK);
    };
    m_cancel_button->on_click = [this](auto) {
        done(GUI::Dialog::ExecResult::Cancel);
    };
}

void EventDialog::show(Core::DateTime date_time, GUI::Window* parent_window)
{
    auto dialog = EventDialog::construct(date_time, parent_window);
    dialog->exec();
}
