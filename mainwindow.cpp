#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::HideUnhideMenu(bool hide)
{
    if (hide)
    {
        ui->About->hide();
        ui->choose->hide();
        ui->label->hide();
        ui->startGame->hide();
    }
    else {
        ui->About->show();
        ui->choose->show();
        ui->label->show();
        ui->startGame->show();
    }
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startGame, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(ui->choose, SIGNAL(clicked()), this, SLOT(chooseDifficulty()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*)
{

}

void MainWindow::startGame()
{
    HideUnhideMenu(true);
}

void MainWindow::chooseDifficulty()
{
    QInputDialog qDialog;

    QStringList items;
    items << QString("map 9x9, 10 mines");
    items << QString("map 16x16, 40 mines");
    items << QString("map 30x16, 99 mines");

    qDialog.setOptions(QInputDialog::UseListViewForComboBoxItems);
    qDialog.setComboBoxItems(items);
    qDialog.setWindowTitle("Choose action");

    QObject::connect(&qDialog, SIGNAL(textValueSelect(const QString&)),
        this, SLOT(onCompute(const QString&)));

    if (qDialog.exec())
    {
        ui->choose->setText("Choose difficulty\n(" + qDialog.textValue() + ")");
        if (qDialog.textValue() == "map 9x9, 10 mines")
        {
            mapLenght = mapWidth = 9;
            numberMines = 10;
        }
        if (qDialog.textValue() == "map 16x16, 40 mines")
        {
            mapLenght = mapWidth = 16;
            numberMines = 40;
        }
        if (qDialog.textValue() == "map 30x16, 99 mines")
        {
            mapLenght = 30;
            mapWidth = 16;
            numberMines = 99;
        }
    }


}


