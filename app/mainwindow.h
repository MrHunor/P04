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