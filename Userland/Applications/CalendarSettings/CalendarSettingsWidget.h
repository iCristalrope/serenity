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

    String m_first_day_of_week { "Sunday"sv };

    RefPtr<GUI::ComboBox> m_first_day_of_week_combobox;
};
