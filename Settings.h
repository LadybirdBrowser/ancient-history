/*
 * Copyright (c) 2022, Filiph Sandström <filiph.sandstrom@filfatstudios.com>
 * Copyright (c) 2022, yeppiidev <yedoxstudios@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#define AK_DONT_REPLACE_STD

#include <AK/String.h>
#include <QSettings>

namespace Browser {

class Settings {
public:
    Settings();

    QString homepage();
    void set_homepage(QString const& homepage);

    QString new_tab_page();
    void set_new_tab_page(QString const& new_tab_page);

    bool always_show_tabs();
    void set_always_show_tabs(bool const& always_show_tabs);

private:
    QSettings* m_qsettings;
};

}
