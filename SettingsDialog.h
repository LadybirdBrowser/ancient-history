/*
 * Copyright (c) 2022, Filiph Sandström <filiph.sandstrom@filfatstudios.com>
 * Copyright (c) 2022, yeppiidev <yedoxstudios@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <QFormLayout>
#include <QDialog>
#include <QMainWindow>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

#pragma once

class SettingsDialog : public QDialog {
    Q_OBJECT
public:
    explicit SettingsDialog(QMainWindow* window);
    
    void save();

    virtual void closeEvent(QCloseEvent*) override;

private:
    QFormLayout* m_layout;
    QPushButton* m_ok_button { nullptr };
    QLineEdit* m_homepage { nullptr };
    QLineEdit* m_new_tab_page { nullptr };
    QCheckBox* m_always_show_tabs { nullptr };
    QMainWindow* m_window { nullptr };
};
