/*
 *   DISCLAIMER: The following code is mostly AI-Written, if legislation in your country
 *   does not allow copyright claims of the prompter then all copyright claims are hereby
 *   waved. Otherwise the following licesne applies.
 *   
 *   P04 - A android party-game libary.
 *   Copyright (C) 2026  MrHunor
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.(root/LICENSE)  If not, see
 *   <https://www.gnu.org/licenses/>.
 */

#pragma once
#include <QMainWindow>
#include "imposter.h"

class QLineEdit;
class QListWidget;
class QListWidgetItem;
class QSpinBox;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void addPlayer();
    void startRound();
    void revealRole(QListWidgetItem *item);

private:
    ImposterGame m_game;
    QLineEdit   *m_nameEdit;
    QListWidget *m_playerList;
    QSpinBox    *m_imposterCount;
};