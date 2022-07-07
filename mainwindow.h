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

    int field[9][9];
//    std::vector<std::vector<QPushButton*>> buttons;
    QPushButton* buttons[9][9];
    int mapLength = 9;
    int mapWidth = 9;
    int numberMines = 10;
    void HideUnhideMenu(bool);
    void ConnectButtons();
    void Clicked(int, int);
private:
    Ui::MainWindow* ui;
protected:
    void paintEvent(QPaintEvent*) override;

private slots:
    void startGame();
    void chooseDifficulty();
    void on_button_00_clicked();
    void on_button_10_clicked();
    void on_button_20_clicked();
    void on_button_30_clicked();
    void on_button_40_clicked();
    void on_button_50_clicked();
    void on_button_60_clicked();
    void on_button_70_clicked();
    void on_button_80_clicked();
    void on_button_01_clicked();
    void on_button_11_clicked();
    void on_button_21_clicked();
    void on_button_31_clicked();
    void on_button_41_clicked();
    void on_button_51_clicked();
    void on_button_61_clicked();
    void on_button_71_clicked();
    void on_button_81_clicked();
    void on_button_02_clicked();
    void on_button_12_clicked();
    void on_button_22_clicked();
    void on_button_32_clicked();
    void on_button_42_clicked();
    void on_button_52_clicked();
    void on_button_62_clicked();
    void on_button_72_clicked();
    void on_button_82_clicked();
    void on_button_03_clicked();
    void on_button_13_clicked();
    void on_button_23_clicked();
    void on_button_33_clicked();
    void on_button_43_clicked();
    void on_button_53_clicked();
    void on_button_63_clicked();
    void on_button_73_clicked();
    void on_button_83_clicked();
    void on_button_04_clicked();
    void on_button_14_clicked();
    void on_button_24_clicked();
    void on_button_34_clicked();
    void on_button_44_clicked();
    void on_button_54_clicked();
    void on_button_64_clicked();
    void on_button_74_clicked();
    void on_button_84_clicked();
};
#endif // MAINWINDOW_H
