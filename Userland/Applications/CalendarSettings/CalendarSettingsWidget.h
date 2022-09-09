/*
 * Copyright (c) 2022-2022, Olivier De Cannière <olivier.decanniere96@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibGUI/ComboBox.h>
#include <LibGUI/SettingsWindow.h>

class CalendarSettingsWidget final : public GUI::SettingsWindow::Tab {
    C_OBJECT(CalendarSettingsWidget)

public:
    virtual void apply_settings() override;
    virtual void reset_default_values() override;

private:
    CalendarSettingsWidget();
    Vector<String> const m_weekday_names = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    Vector<String> const m_view_modes = { "Month", "Year" };

    String m_first_day_of_week { "Sunday"sv };
    String m_default_view { "Month"sv };

    RefPtr<GUI::ComboBox> m_first_day_of_week_combobox;
    RefPtr<GUI::ComboBox> m_default_view_combobox;
};
