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

void MainWindow::ConnectButtons(QPushButton* buttons[9][9])
{
    buttons[0][0] = ui->button_00;
    buttons[0][1] = ui->button_01;
    buttons[0][2] = ui->button_02;
    buttons[0][3] = ui->button_03;
    buttons[0][4] = ui->button_04;
    buttons[0][5] = ui->button_05;
    buttons[0][6] = ui->button_06;
    buttons[0][7] = ui->button_07;
    buttons[0][8] = ui->button_08;

    buttons[1][0] = ui->button_10;
    buttons[1][1] = ui->button_11;
    buttons[1][2] = ui->button_12;
    buttons[1][3] = ui->button_13;
    buttons[1][4] = ui->button_14;
    buttons[1][5] = ui->button_15;
    buttons[1][6] = ui->button_16;
    buttons[1][7] = ui->button_17;
    buttons[1][8] = ui->button_18;

    buttons[2][0] = ui->button_20;
    buttons[2][1] = ui->button_21;
    buttons[2][2] = ui->button_22;
    buttons[2][3] = ui->button_23;
    buttons[2][4] = ui->button_24;
    buttons[2][5] = ui->button_25;
    buttons[2][6] = ui->button_26;
    buttons[2][7] = ui->button_27;
    buttons[2][8] = ui->button_28;

    buttons[3][0] = ui->button_30;
    buttons[3][1] = ui->button_31;
    buttons[3][2] = ui->button_32;
    buttons[3][3] = ui->button_33;
    buttons[3][4] = ui->button_34;
    buttons[3][5] = ui->button_35;
    buttons[3][6] = ui->button_36;
    buttons[3][7] = ui->button_37;
    buttons[3][8] = ui->button_38;

    buttons[4][0] = ui->button_40;
    buttons[4][1] = ui->button_41;
    buttons[4][2] = ui->button_42;
    buttons[4][3] = ui->button_43;
    buttons[4][4] = ui->button_44;
    buttons[4][5] = ui->button_45;
    buttons[4][6] = ui->button_46;
    buttons[4][7] = ui->button_47;
    buttons[4][8] = ui->button_48;

    buttons[5][0] = ui->button_50;
    buttons[5][1] = ui->button_51;
    buttons[5][2] = ui->button_52;
    buttons[5][3] = ui->button_53;
    buttons[5][4] = ui->button_54;
    buttons[5][5] = ui->button_55;
    buttons[5][6] = ui->button_56;
    buttons[5][7] = ui->button_57;
    buttons[5][8] = ui->button_58;

    buttons[6][0] = ui->button_60;
    buttons[6][1] = ui->button_61;
    buttons[6][2] = ui->button_62;
    buttons[6][3] = ui->button_63;
    buttons[6][4] = ui->button_64;
    buttons[6][5] = ui->button_65;
    buttons[6][6] = ui->button_66;
    buttons[6][7] = ui->button_67;
    buttons[6][8] = ui->button_68;

    buttons[7][0] = ui->button_70;
    buttons[7][1] = ui->button_71;
    buttons[7][2] = ui->button_72;
    buttons[7][3] = ui->button_73;
    buttons[7][4] = ui->button_74;
    buttons[7][5] = ui->button_75;
    buttons[7][6] = ui->button_76;
    buttons[7][7] = ui->button_77;
    buttons[7][8] = ui->button_78;

    buttons[8][0] = ui->button_80;
    buttons[8][1] = ui->button_81;
    buttons[8][2] = ui->button_82;
    buttons[8][3] = ui->button_83;
    buttons[8][4] = ui->button_84;
    buttons[8][5] = ui->button_85;
    buttons[8][6] = ui->button_86;
    buttons[8][7] = ui->button_87;
    buttons[8][8] = ui->button_88;
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
    
    QPushButton* buttons[9][9];
    ConnectButtons(buttons);

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
    items << QString("map 9x9, 15 mines");
    items << QString("map 9x9, 20 mines");

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
        if (qDialog.textValue() == "map 9x9, 15 mines")
        {
            mapLength = mapWidth = 9;
            numberMines = 15;
        }
        if (qDialog.textValue() == "map 9x9, 20 mines")
        {
            mapLength = mapWidth = 9;
            numberMines = 20;
        }
    }


}


