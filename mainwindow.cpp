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

    //TODO
    ui->groupBox->show();
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startGame, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(ui->choose, SIGNAL(clicked()), this, SLOT(chooseDifficulty()));

    //TODO
    ui->groupBox->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    std::vector<std::vector<QPushButton>> buttons(mapLength, std::vector<QPushButton> (mapWidth));
    std::vector<std::vector<int>> field(mapLength, std::vector<int> (mapWidth));
    std::vector<std::pair<int, int>> mines;

    for(int i = 0; i < numberMines; i++)
    {
        int x = rand() % mapLength;
        int y = rand() % mapWidth;
        mines.push_back(std::make_pair(x, y));
        field[x][y] = -1;
        field[std::min(x - 1, 0)][std::min(y - 1, 0)]++;
        field[x + 1][std::min(y - 1, 0)]++;
        field[std::min(x - 1, 0)][y + 1]++;
        field[std::max(x + 1, mapLength)][y + 1]++;
        field[x + 1][y]++;
        field[std::min(x - 1, 0)][y]++;
        field[x][y + 1]++;
        field[x][std::min(y - 1, 0)]++;
    }

    for(int i = 0; i < mapLength; i++)
    {
        for(int j = 0; j < mapWidth; j++)
        {
            field[m][j]
        }
    }

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
            mapLength = mapWidth = 9;
            numberMines = 10;
        }
        if (qDialog.textValue() == "map 16x16, 40 mines")
        {
            mapLength = mapWidth = 16;
            numberMines = 40;
        }
        if (qDialog.textValue() == "map 30x16, 99 mines")
        {
            mapLength = 30;
            mapWidth = 16;
            numberMines = 99;
        }
    }


}


