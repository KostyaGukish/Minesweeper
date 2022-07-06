#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QInputDialog>
#include <QButtonGroup>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    int mainField[30][16];
    int mapLength = 9;
    int mapWidth = 9;
    int numberMines = 10;
    void HideUnhideMenu(bool);
    void ConnectButtons(QPushButton* buttons[9][9]);
private:
    Ui::MainWindow* ui;
protected:
    void paintEvent(QPaintEvent*) override;

private slots:
    void startGame();
    void chooseDifficulty();
};
#endif // MAINWINDOW_H
