#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <queue>

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

void MainWindow::gameOver(QString message)
{
    for (int i = 0; i < mapLength; i++) {
        for (int j = 0; j < mapWidth; j++) {
            if (buttons[i][j]->isEnabled()) {
                buttons[i][j]->setEnabled(false);
                if (field[i][j] == -1) {
                    buttons[i][j]->setIcon(QIcon("C:\\Qt\\projects\\minesweeper\\png-transparent-red-circle-minesweeper-minesweeper-deluxe-minesweeper-adfree-video-games-land-mine-naval-mine-android-thumbnail.png"));
                }
                else if (field[i][j] != 0) {
                    buttons[i][j]->setText(QString::number(field[i][j]));
                }
            }
        }
    }
    QMessageBox::information(this, "Game Over", message);

}

void MainWindow::ConnectButtons()
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

    ConnectButtons();

    for (int i = 0; i < mapLength; i++) {
        for (int j = 0; j < mapWidth; j++) {
            buttons[i][j]->setEnabled(false);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*)
{
}

bool MainWindow::eventFilter(QEvent* event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::RightButton)
            return true;
    }
    return false;
}


void MainWindow::Clicked(int x, int y) {
    buttons[x][y]->setEnabled(false);
    if (field[x][y] == -1) {
        buttons[x][y]->setIcon(QIcon("C:\\Qt\\projects\\minesweeper\\png-transparent-red-circle-minesweeper-minesweeper-deluxe-minesweeper-adfree-video-games-land-mine-naval-mine-android-thumbnail.png"));
        gameOver("You lose(");
    }
    else if (field[x][y] != 0) {
        buttons[x][y]->setText(QString::number(field[x][y]));
    }
    else {
        std::queue<std::pair<int, int>> q;
        q.push(std::make_pair(x, y));
        while (!q.empty()) {
            int ni = q.front().first;
            int nj = q.front().second;
            buttons[ni][nj]->setEnabled(false);
            q.pop();

            if (ni + 1 < 9 && buttons[ni + 1][nj]->isEnabled()) {
                if (field[ni + 1][nj] == 0) {
                    q.push(std::make_pair(ni + 1, nj));
                }
                else {
                    buttons[ni + 1][nj]->setText(QString::number(field[ni + 1][nj]));
                    buttons[ni + 1][nj]->setEnabled(false);
                }
            }

            if (ni - 1 >= 0 && buttons[ni - 1][nj]->isEnabled()) {
                if (field[ni - 1][nj] == 0) {
                    q.push(std::make_pair(ni - 1, nj));
                }
                else {
                    buttons[ni - 1][nj]->setText(QString::number(field[ni - 1][nj]));
                    buttons[ni - 1][nj]->setEnabled(false);
                }
            }

            if (nj + 1 < 9 && buttons[ni][nj + 1]->isEnabled()) {
                if (field[ni][nj + 1] == 0) {
                    q.push(std::make_pair(ni, nj + 1));
                }
                else {
                    buttons[ni][nj + 1]->setText(QString::number(field[ni][nj + 1]));
                    buttons[ni][nj + 1]->setEnabled(false);
                }
            }

            if (nj - 1 >= 0 && buttons[ni][nj - 1]->isEnabled()) {
                if (field[ni][nj - 1] == 0) {
                    q.push(std::make_pair(ni, nj - 1));
                }
                else {
                    buttons[ni][nj - 1]->setText(QString::number(field[ni][nj - 1]));
                    buttons[ni][nj - 1]->setEnabled(false);
                }
            }

            if (ni + 1 < 9 && nj + 1 < 9 && buttons[ni + 1][nj + 1]->isEnabled()) {
                if (field[ni + 1][nj + 1] == 0) {
                    q.push(std::make_pair(ni + 1, nj + 1));
                }
                else {
                    buttons[ni + 1][nj + 1]->setText(QString::number(field[ni + 1][nj + 1]));
                    buttons[ni + 1][nj + 1]->setEnabled(false);
                }
            }

            if (ni + 1 < 9 && nj - 1 >= 0 && buttons[ni + 1][nj - 1]->isEnabled()) {
                if (field[ni + 1][nj - 1] == 0) {
                    q.push(std::make_pair(ni + 1, nj - 1));
                }
                else {
                    buttons[ni + 1][nj - 1]->setText(QString::number(field[ni + 1][nj - 1]));
                    buttons[ni + 1][nj - 1]->setEnabled(false);
                }
            }

            if (ni - 1 >= 0 && nj + 1 < 9 && buttons[ni - 1][nj + 1]->isEnabled()) {
                if (field[ni - 1][nj + 1] == 0) {
                    q.push(std::make_pair(ni - 1, nj + 1));
                }
                else {
                    buttons[ni - 1][nj + 1]->setText(QString::number(field[ni - 1][nj + 1]));
                    buttons[ni - 1][nj + 1]->setEnabled(false);
                }
            }

            if (ni - 1 >= 0 && nj - 1 >= 0 && buttons[ni - 1][nj - 1]->isEnabled()) {
                if (field[ni - 1][nj - 1] == 0) {
                    q.push(std::make_pair(ni - 1, nj - 1));
                }
                else {
                    buttons[ni - 1][nj - 1]->setText(QString::number(field[ni - 1][nj - 1]));
                    buttons[ni - 1][nj - 1]->setEnabled(false);
                }
            }

        }

    }

    int k = 0;
    for (int i = 0; i < mapLength; i++) {
        for (int j = 0; j < mapWidth; j++) {
            if (buttons[i][j]->isEnabled()) {
                k++;
            }
        }
    }
    if (k == numberMines) {
        gameOver("You win!");
    }
}

void MainWindow::startGame()
{
    //HideUnhideMenu(true);

    ui->startGame->setText("Restart Game");

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            field[i][j] = 0;
        }
    }

    for (int i = 0; i < mapLength; i++) {
        for (int j = 0; j < mapWidth; j++) {
            buttons[i][j]->setEnabled(true);
            buttons[i][j]->setText("");
            buttons[i][j]->setIcon(QIcon());
        }
    }

    for (int i = 0; i < numberMines; i++) {
        int x = rand() % 9;
        int y = rand() % 9;

        field[x][y] = -1;

        if (x - 1 >= 0 && y - 1 >= 0 && field[x - 1][y - 1] != -1) {
            field[x - 1][y - 1]++;
        }
        if (x + 1 < mapLength && y - 1 >= 0 && field[x + 1][y - 1] != -1) {
            field[x + 1][y - 1]++;
        }
        if (x - 1 >= 0 && y + 1 < mapWidth && field[x - 1][y + 1] != -1) {
            field[x - 1][y + 1]++;
        }
        if (x + 1 < mapLength && y + 1 < mapWidth && field[x + 1][y + 1] != -1) {
            field[x + 1][y + 1]++;
        }
        if (x + 1 < mapLength && field[x + 1][y] != -1) {
            field[x + 1][y]++;
        }
        if (x - 1 >= 0 && field[x - 1][y] != -1) {
            field[x - 1][y]++;
        }
        if (y + 1 < mapWidth && field[x][y + 1] != -1) {
            field[x][y + 1]++;
        }
        if (y - 1 >= 0 && field[x][y - 1] != -1) {
            field[x][y - 1]++;
        }
    }
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

void MainWindow::on_button_00_clicked()
{
    Clicked(0, 0);
}

void MainWindow::on_button_10_clicked()
{
    Clicked(1, 0);
}

void MainWindow::on_button_20_clicked()
{
    Clicked(2, 0);
}

void MainWindow::on_button_30_clicked()
{
    Clicked(3, 0);
}

void MainWindow::on_button_40_clicked()
{
    Clicked(4, 0);
}

void MainWindow::on_button_50_clicked()
{
    Clicked(5, 0);
}

void MainWindow::on_button_60_clicked()
{
    Clicked(6, 0);
}

void MainWindow::on_button_70_clicked()
{
    Clicked(7, 0);
}

void MainWindow::on_button_80_clicked()
{
    Clicked(8, 0);
}

void MainWindow::on_button_01_clicked()
{
    Clicked(0, 1);
}

void MainWindow::on_button_11_clicked()
{
    Clicked(1, 1);
}

void MainWindow::on_button_21_clicked()
{
    Clicked(2, 1);
}

void MainWindow::on_button_31_clicked()
{
    Clicked(3, 1);
}

void MainWindow::on_button_41_clicked()
{
    Clicked(4, 1);
}

void MainWindow::on_button_51_clicked()
{
    Clicked(5, 1);
}

void MainWindow::on_button_61_clicked()
{
    Clicked(6, 1);
}

void MainWindow::on_button_71_clicked()
{
    Clicked(7, 1);
}

void MainWindow::on_button_81_clicked()
{
    Clicked(8, 1);
}

void MainWindow::on_button_02_clicked()
{
    Clicked(0, 2);
}

void MainWindow::on_button_12_clicked()
{
    Clicked(1, 2);
}

void MainWindow::on_button_22_clicked()
{
    Clicked(2, 2);
}

void MainWindow::on_button_32_clicked()
{
    Clicked(3, 2);
}

void MainWindow::on_button_42_clicked()
{
    Clicked(4, 2);
}

void MainWindow::on_button_52_clicked()
{
    Clicked(5, 2);
}

void MainWindow::on_button_62_clicked()
{
    Clicked(6, 2);
}

void MainWindow::on_button_72_clicked()
{
    Clicked(7, 2);
}

void MainWindow::on_button_82_clicked()
{
    Clicked(8, 2);
}


void MainWindow::on_button_03_clicked()
{
    Clicked(0, 3);
}


void MainWindow::on_button_13_clicked()
{
    Clicked(1, 3);
}


void MainWindow::on_button_23_clicked()
{
    Clicked(2, 3);
}


void MainWindow::on_button_33_clicked()
{
    Clicked(3, 3);
}


void MainWindow::on_button_43_clicked()
{
    Clicked(4, 3);
}


void MainWindow::on_button_53_clicked()
{
    Clicked(5, 3);
}


void MainWindow::on_button_63_clicked()
{
    Clicked(6, 3);
}


void MainWindow::on_button_73_clicked()
{
    Clicked(7, 3);
}


void MainWindow::on_button_83_clicked()
{
    Clicked(8, 3);
}


void MainWindow::on_button_04_clicked()
{
    Clicked(0, 4);
}


void MainWindow::on_button_14_clicked()
{
    Clicked(1, 4);
}


void MainWindow::on_button_24_clicked()
{
    Clicked(2, 4);
}


void MainWindow::on_button_34_clicked()
{
    Clicked(3, 4);
}


void MainWindow::on_button_44_clicked()
{
    Clicked(4, 4);
}


void MainWindow::on_button_54_clicked()
{
    Clicked(5, 4);
}


void MainWindow::on_button_64_clicked()
{
    Clicked(6, 4);
}


void MainWindow::on_button_74_clicked()
{
    Clicked(7, 4);
}


void MainWindow::on_button_84_clicked()
{
    Clicked(8, 4);
}


void MainWindow::on_button_05_clicked()
{
    Clicked(0, 5);
}


void MainWindow::on_button_15_clicked()
{
    Clicked(1, 5);
}


void MainWindow::on_button_25_clicked()
{
    Clicked(2, 5);
}


void MainWindow::on_button_35_clicked()
{
    Clicked(3, 5);
}


void MainWindow::on_button_45_clicked()
{
    Clicked(4, 5);
}


void MainWindow::on_button_55_clicked()
{
    Clicked(5, 5);
}


void MainWindow::on_button_65_clicked()
{
    Clicked(6, 5);
}


void MainWindow::on_button_75_clicked()
{
    Clicked(7, 5);
}


void MainWindow::on_button_85_clicked()
{
    Clicked(8, 5);
}


void MainWindow::on_button_06_clicked()
{
    Clicked(0, 6);
}


void MainWindow::on_button_16_clicked()
{
    Clicked(1, 6);
}


void MainWindow::on_button_26_clicked()
{
    Clicked(2, 6);
}


void MainWindow::on_button_36_clicked()
{
    Clicked(3, 6);
}


void MainWindow::on_button_46_clicked()
{
    Clicked(4, 6);
}


void MainWindow::on_button_56_clicked()
{
    Clicked(5, 6);
}


void MainWindow::on_button_66_clicked()
{
    Clicked(6, 6);
}


void MainWindow::on_button_76_clicked()
{
    Clicked(7, 6);
}


void MainWindow::on_button_86_clicked()
{
    Clicked(8, 6);
}


void MainWindow::on_button_07_clicked()
{
    Clicked(0, 7);
}


void MainWindow::on_button_17_clicked()
{
    Clicked(1, 7);
}


void MainWindow::on_button_27_clicked()
{
    Clicked(2, 7);
}


void MainWindow::on_button_37_clicked()
{
    Clicked(3, 7);
}


void MainWindow::on_button_47_clicked()
{
    Clicked(4, 7);
}


void MainWindow::on_button_57_clicked()
{
    Clicked(5, 7);
}


void MainWindow::on_button_67_clicked()
{
    Clicked(6, 7);
}


void MainWindow::on_button_77_clicked()
{
    Clicked(7, 7);
}


void MainWindow::on_button_87_clicked()
{
    Clicked(8, 7);
}


void MainWindow::on_button_08_clicked()
{
    Clicked(0, 8);
}


void MainWindow::on_button_18_clicked()
{
    Clicked(1, 8);
}


void MainWindow::on_button_28_clicked()
{
    Clicked(2, 8);
}


void MainWindow::on_button_38_clicked()
{
    Clicked(3, 8);
}


void MainWindow::on_button_48_clicked()
{
    Clicked(4, 8);
}


void MainWindow::on_button_58_clicked()
{
    Clicked(5, 8);
}


void MainWindow::on_button_68_clicked()
{
    Clicked(6, 8);
}


void MainWindow::on_button_78_clicked()
{
    Clicked(7, 8);
}


void MainWindow::on_button_88_clicked()
{
    Clicked(8, 8);
}
