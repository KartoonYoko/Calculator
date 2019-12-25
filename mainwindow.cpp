#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "../../Calculator/untitled/exprtk/exprtk.hpp"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setMaximumWidth(280);
    this->setMaximumHeight(580);
    this->setMinimumSize(280, 580);
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/image/calc.png")); // doesnt work
   // QTextCursor cursor;
   // ui->plainTextEdit_show->setTextCursor(cursor);
    ui->listWidget->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_1_clicked()
{
    calc.appendStr(1);
    ui->plainTextEdit_enter->insertPlainText("1");
}
void MainWindow::on_pushButton_2_clicked()
{
   calc.appendStr(2);
   ui->plainTextEdit_enter->insertPlainText("2");
}

void MainWindow::on_pushButton_3_clicked()
{
    calc.appendStr(3);
    ui->plainTextEdit_enter->insertPlainText("3");
}

void MainWindow::on_pushButton_4_clicked()
{
    calc.appendStr(4);
    ui->plainTextEdit_enter->insertPlainText("4");
}

void MainWindow::on_pushButton_5_clicked()
{
    calc.appendStr(5);
    ui->plainTextEdit_enter->insertPlainText("5");
}

void MainWindow::on_pushButton_6_clicked()
{
    calc.appendStr(6);
    ui->plainTextEdit_enter->insertPlainText("6");
}

void MainWindow::on_pushButton_7_clicked()
{
    calc.appendStr(7);
    ui->plainTextEdit_enter->insertPlainText("7");
}

void MainWindow::on_pushButton_8_clicked()
{
    calc.appendStr(8);
    ui->plainTextEdit_enter->insertPlainText("8");
}

void MainWindow::on_pushButton_9_clicked()
{
    calc.appendStr(9);
    ui->plainTextEdit_enter->insertPlainText("9");
}

void MainWindow::on_pushButton_point_clicked()
{
    if(calc.getStr().contains(".") == false)
    {   calc.appendStr(".");
        ui->plainTextEdit_enter->insertPlainText(".");
    }
}

void MainWindow::on_pushButton_0_clicked()
{
    calc.appendStr(0);
    ui->plainTextEdit_enter->insertPlainText("0");
}

void MainWindow::on_pushButton_clearAll_clicked()
{
    firstOperation = true;
    ui->plainTextEdit_show->clear();
    ui->plainTextEdit_enter->clear();
    calc.reset();
}





void MainWindow::on_pushButton_equal_clicked()
{ 
    exc = false; // для получения исключения

    if(calc.getStr() != ""){  // проверка на повторное нажатие
                                // если нажатие производилось, то str = "", иначе str хранит какое-то значение
        ui->plainTextEdit_show->insertPlainText(calc.getStr());
        calc.makeCalculation(exc);
        calc.resetStr();

       if(exc == true)  // если исключение получено
        {
            ui->plainTextEdit_enter->setPlainText("Неверное значение!");
            exc = false;
        }
        else{
            ui->plainTextEdit_enter->setPlainText(calc.resulToString());
            sHistory a;
            a.result = calc.getResult();
            a.str = ui->plainTextEdit_show->toPlainText();
            history.push_back(a);
            ui->listWidget->addItem(a.str + " = " + QString::number(a.result));
       }
    }

}


void MainWindow::on_pushButton_add_clicked()
{
    if(firstOperation == true){
        calc.setResult(calc.getStr().toDouble()); // т.к. это первое вычесление - сразу заносит введенное значение в результат
        ui->plainTextEdit_show->insertPlainText(calc.resulToString() + " + ");
        ui->plainTextEdit_enter->clear();
        firstOperation = false;
        calc.resetStr();
        calc.lastAction = PLUS;
    }
    else{                   // считает предыдущий ввод
        calc.makeCalculation(exc);
        if(exc == true)  // если исключение получено
        {
            ui->plainTextEdit_enter->setPlainText("Неверное значение!");
            exc = false;
        }
        else
            ui->plainTextEdit_show->insertPlainText(calc.getStr() + " + ");
        ui->plainTextEdit_enter->clear();
        calc.resetStr();
        calc.lastAction = PLUS;

    }
}

void MainWindow::on_pushButton_subtract_clicked()
{
    if(firstOperation == true){
        calc.setResult(calc.getStr().toDouble()); // т.к. это первое вычесление - сразу заносит введенное значение в результат
        ui->plainTextEdit_show->insertPlainText(calc.resulToString() + " - ");
        ui->plainTextEdit_enter->clear();
        firstOperation = false;
        calc.resetStr();
        calc.lastAction = MINUS;
    }
    else{                    // считает предыдущий ввод
        calc.makeCalculation(exc);
        if(exc == true)  // если исключение получено
        {
            ui->plainTextEdit_enter->setPlainText("Неверное значение!");
            exc = false;
        }
        else
            ui->plainTextEdit_show->insertPlainText(calc.getStr() + " - ");
        ui->plainTextEdit_enter->clear();
        calc.resetStr();
        calc.lastAction = MINUS;
    }
}

void MainWindow::on_pushButton_multiply_clicked()
{
    if(firstOperation == true){
        calc.setResult(calc.getStr().toDouble()); // т.к. это первое вычесление - сразу заносит введенное значение в результат
        ui->plainTextEdit_show->insertPlainText(calc.resulToString() + " * ");
        ui->plainTextEdit_enter->clear();
        firstOperation = false;
        calc.resetStr();
        calc.lastAction = MULT;
    }
    else{      // считает предыдущий ввод
        calc.makeCalculation(exc);

        //ui->plainTextEdit_show->textCursor().movePosition(QTextCursor::Start);
        //ui->plainTextEdit_show->textCursor().insertText("(");
        if(exc == true)  // если исключение получено
        {
            ui->plainTextEdit_enter->setPlainText("Неверное значение!");
            exc = false;
        }
        else
            ui->plainTextEdit_show->insertPlainText(calc.getStr() + ") * ");
        ui->plainTextEdit_enter->clear();

        calc.resetStr();
        calc.lastAction = MULT;
    }
}

void MainWindow::on_pushButton_divide_clicked()
{

    if(firstOperation == true){
        calc.setResult(calc.getStr().toDouble()); // т.к. это первое вычесление - сразу заносит введенное значение в результат
        ui->plainTextEdit_show->insertPlainText(calc.resulToString() + " / ");
        ui->plainTextEdit_enter->clear();
        firstOperation = false;
        calc.resetStr();
        calc.lastAction = DIV;
    }
    else{      // считает предыдущий ввод
        calc.makeCalculation(exc);

        //ui->plainTextEdit_show->textCursor().movePosition(QTextCursor::Start);
        //ui->plainTextEdit_show->textCursor().insertText("(");
        if(exc == true)  // если исключение получено
        {
            ui->plainTextEdit_enter->setPlainText("Неверное значение!");
            exc = false;
        }
        else
            ui->plainTextEdit_show->insertPlainText(calc.getStr() + ") / ");
        ui->plainTextEdit_enter->clear();

        calc.resetStr();
        calc.lastAction = DIV;
    }
}

void MainWindow::on_pushButton_changeOcthorpe_clicked()
{
    QString bufStr = QString::number(-1 * calc.getStr().toDouble());
    calc.setStr(bufStr);
    ui->plainTextEdit_enter->setPlainText(calc.getStr());
}

void MainWindow::on_pushButton_ln_clicked()
{
    if(calc.getStr() != ""){  // проверка на повторное нажатие
                                // если нажатие производилось, то str = "", иначе str хранит какое-то значение
        ui->plainTextEdit_enter->setPlainText("ln(" + calc.getStr() + ")");
        calc.lnStr();
    }

}

void MainWindow::on_pushButton_exp_clicked()
{
    if(calc.getStr() != ""){  // проверка на повторное нажатие
                                // если нажатие производилось, то str = "", иначе str хранит какое-то значение
    ui->plainTextEdit_enter->setPlainText("exp(" + calc.getStr() + ")");
    calc.expStr();
    }
}

void MainWindow::on_pushButton_power_clicked()
{
    if(firstOperation == true){
        calc.setResult(calc.getStr().toDouble()); // т.к. это первое вычесление - сразу заносит введенное значение в результат
        ui->plainTextEdit_show->insertPlainText(calc.resulToString() + " ^ ");
        ui->plainTextEdit_enter->clear();
        firstOperation = false;
        calc.resetStr();
        calc.lastAction = POWER;
    }
    else{      // считает предыдущий ввод
        calc.makeCalculation(exc);
        if(exc == true)  // если исключение получено
        {
            ui->plainTextEdit_enter->setPlainText("Неверное значение!");
            exc = false;
        }
        else
            ui->plainTextEdit_show->insertPlainText(calc.getStr() + ") ^ ");
        ui->plainTextEdit_enter->clear();

        calc.resetStr();
        calc.lastAction = POWER;
    }
}

void MainWindow::on_pushButton_cos_clicked()
{
    if(calc.getStr() != ""){  // проверка на повторное нажатие
                                // если нажатие производилось, то str = "", иначе str хранит какое-то значение
        ui->plainTextEdit_enter->setPlainText("cos(" + calc.getStr() + ")");
        calc.cosStr();
    }
}

void MainWindow::on_pushButton_sin_clicked()
{
    if(calc.getStr() != ""){  // проверка на повторное нажатие
                                // если нажатие производилось, то str = "", иначе str хранит какое-то значение
        ui->plainTextEdit_enter->setPlainText("sin(" + calc.getStr() + ")");
        calc.sinStr();
    }
}

void MainWindow::on_pushButton_tan_clicked()
{
    if(calc.getStr() != ""){  // проверка на повторное нажатие
                                // если нажатие производилось, то str = "", иначе str хранит какое-то значение
     ui->plainTextEdit_enter->setPlainText("tan(" + calc.getStr() + ")");
        calc.tanStr();
    }
}

void MainWindow::on_pushButton_backSpace_clicked()
{
    calc.resizeStr(calc.getStr().size() - 1);
    ui->plainTextEdit_enter->setPlainText(calc.getStr());
}

void MainWindow::on_pushButton_history_clicked()
{
    if(isHistoryVisible == false){
        ui->listWidget->setVisible(isHistoryVisible);
        isHistoryVisible = true;
        this->setMaximumWidth(280);
        this->setMaximumHeight(580);
        this->setMinimumWidth(280);
        this->resize(280, 580);

    }
    else{
        ui->listWidget->setVisible(isHistoryVisible);
        isHistoryVisible = false;
        this->setMaximumWidth(600);
        this->setMaximumHeight(580);
        this->setMinimumWidth(600);
        this->resize(600, 580);
    }

}
