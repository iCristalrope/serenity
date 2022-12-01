/*
 * Copyright (c) 2019-2020, Ryan Grieb <ryan.m.grieb@gmail.com>
 * Copyright (c) 2022, the SerenityOS developers.
 * Copyright (c) 2022, Olivier De Cannière <olivier.decanniere96@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibGUI/Calendar.h>
#include <LibGUI/ColorInput.h>
#include <LibGUI/Dialog.h>
#include <LibGUI/Model.h>
#include <LibGUI/Window.h>
#include <LibSQL/SQLClient.h>

class EventDialog final : public GUI::Dialog {
    C_OBJECT(EventDialog)
public:
    virtual ~EventDialog() override = default;

    static void show(RefPtr<SQL::SQLClient>, Core::DateTime, Window* parent_window = nullptr);

private:
    EventDialog(Core::DateTime date_time, Window* parent_window = nullptr);

    void update_last_day_of_month() const;

    RefPtr<GUI::TextBox> m_title_textbox;
    RefPtr<GUI::TextEditor> m_description_editor;
    RefPtr<GUI::ColorInput> m_event_color_input;
    RefPtr<GUI::ComboBox> m_month_combobox;
    RefPtr<GUI::SpinBox> m_day_spinbox;
    RefPtr<GUI::SpinBox> m_year_spinbox;
    RefPtr<GUI::SpinBox> m_hour_spinbox;
    RefPtr<GUI::SpinBox> m_minute_spinbox;
    RefPtr<GUI::Button> m_ok_button;
    RefPtr<GUI::Button> m_cancel_button;
    RefPtr<GUI::Button> m_delete_button;
};
