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

#include "mainwindow.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QSpinBox>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    auto *central = new QWidget(this);
    auto *layout  = new QVBoxLayout(central);

    m_nameEdit = new QLineEdit;
    m_nameEdit->setPlaceholderText("Player name");
    auto *addBtn = new QPushButton("Add");
    auto *row = new QHBoxLayout;
    row->addWidget(m_nameEdit);
    row->addWidget(addBtn);

    m_playerList = new QListWidget;
    m_imposterCount = new QSpinBox;
    m_imposterCount->setRange(1, 10);
    auto *startBtn = new QPushButton("Start round");

    layout->addLayout(row);
    layout->addWidget(m_playerList);
    layout->addWidget(new QLabel("Imposters:"));
    layout->addWidget(m_imposterCount);
    layout->addWidget(startBtn);
    setCentralWidget(central);
    setWindowTitle("P04 Imposter");

    connect(addBtn,       &QPushButton::clicked,     this, &MainWindow::addPlayer);
    connect(m_nameEdit,   &QLineEdit::returnPressed, this, &MainWindow::addPlayer);
    connect(startBtn,     &QPushButton::clicked,     this, &MainWindow::startRound);
    connect(m_playerList, &QListWidget::itemClicked, this, &MainWindow::revealRole);
}

void MainWindow::addPlayer() {
    const QString name = m_nameEdit->text().trimmed();
    if (name.isEmpty()) return;
    m_playerList->addItem(name);
    m_nameEdit->clear();
}

void MainWindow::startRound() {
    m_game.players.clear();
    for (int i = 0; i < m_playerList->count(); ++i)
        m_game.players.push_back(m_playerList->item(i)->text().toStdString());

    if (m_game.players.size() <= static_cast<size_t>(m_imposterCount->value())) {
        QMessageBox::warning(this, "Not enough players",
                             "You need more players than imposters.");
        return;
    }
    m_game.nImposters = static_cast<uint8_t>(m_imposterCount->value());

    try {
        m_game.makeRound();
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
        return;
    }
    QMessageBox::information(this, "Round ready",
        "Pass the device around. Each player taps their own name to see their role.");
}

void MainWindow::revealRole(QListWidgetItem *item) {
    if (m_game.currentWord.empty()) return;  // round not started
    const auto idx = static_cast<uint8_t>(m_playerList->row(item));
    const bool isImposter = std::find(m_game.imposterIndex.begin(),
                                      m_game.imposterIndex.end(), idx)
                            != m_game.imposterIndex.end();
    if (isImposter)
        QMessageBox::information(this, item->text(),
            "You are the IMPOSTER.\nTip: " + QString::fromStdString(m_game.currentImposterTip));
    else
        QMessageBox::information(this, item->text(),
            "Your word: " + QString::fromStdString(m_game.currentWord));
}