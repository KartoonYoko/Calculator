#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "../../Calculator/untitled/exprtk/exprtk.hpp"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/image/calc.png")); // doesnt work
   // QTextCursor cursor;
   // ui->plainTextEdit_show->setTextCursor(cursor);
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
       bool exc = false; // для получения исключения

    if(calc.getStr() != ""){  // проверка на что-то
        ui->plainTextEdit_show->insertPlainText(calc.getStr());
        makeCalculation(exc);

    }
    if(exc == true)  // если исключение получено
        ui->plainTextEdit_enter->setPlainText("Неверное значение!");
    else
        ui->plainTextEdit_enter->setPlainText(calc.resulToString());

}

void MainWindow::makeCalculation(bool &exc){
    if(lastAction == PLUS){
        calc.add();
    }
    if(lastAction == MINUS){
        calc.sub();
    }
    if(lastAction == MULT){
        calc.mult();
    }
    if(lastAction == DIV){
        try {
             calc.div();
        } catch (exceptionCalc e) {
            ui->plainTextEdit_enter->setPlainText("Неверное значение!");
            exc = true;
        }
    }
    if(lastAction == POWER){
        calc.power();
    }

}

void MainWindow::makeCalculation(){
    if(lastAction == PLUS){
        calc.add();
    }
    if(lastAction == MINUS){
        calc.sub();
    }
    if(lastAction == MULT){
        calc.mult();
    }
    if(lastAction == DIV){
        calc.div();
    }
    if(lastAction == POWER){
        calc.power();
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
        lastAction = PLUS;
    }
    else{                   // считает предыдущий ввод
        makeCalculation();
        ui->plainTextEdit_show->insertPlainText(calc.getStr() + " + ");
        ui->plainTextEdit_enter->clear();
        calc.resetStr();
        lastAction = PLUS;

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
        lastAction = MINUS;
    }
    else{                    // считает предыдущий ввод
        makeCalculation();
        ui->plainTextEdit_show->insertPlainText(calc.getStr() + " - ");
        ui->plainTextEdit_enter->clear();
        calc.resetStr();
        lastAction = MINUS;
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
        lastAction = MULT;
    }
    else{      // считает предыдущий ввод
        makeCalculation();

        //ui->plainTextEdit_show->textCursor().movePosition(QTextCursor::Start);
        //ui->plainTextEdit_show->textCursor().insertText("(");
        ui->plainTextEdit_show->insertPlainText(calc.getStr() + ") * ");
        ui->plainTextEdit_enter->clear();

        calc.resetStr();
        lastAction = MULT;
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
        lastAction = DIV;
    }
    else{      // считает предыдущий ввод
        makeCalculation();

        //ui->plainTextEdit_show->textCursor().movePosition(QTextCursor::Start);
        //ui->plainTextEdit_show->textCursor().insertText("(");
        ui->plainTextEdit_show->insertPlainText(calc.getStr() + ") / ");
        ui->plainTextEdit_enter->clear();

        calc.resetStr();
        lastAction = DIV;
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
    calc.lnStr();
}

void MainWindow::on_pushButton_exp_clicked()
{
    calc.expStr();
}

void MainWindow::on_pushButton_power_clicked()
{
    if(firstOperation == true){
        calc.setResult(calc.getStr().toDouble()); // т.к. это первое вычесление - сразу заносит введенное значение в результат
        ui->plainTextEdit_show->insertPlainText(calc.resulToString() + " ^ ");
        ui->plainTextEdit_enter->clear();
        firstOperation = false;
        calc.resetStr();
        lastAction = POWER;
    }
    else{      // считает предыдущий ввод
        makeCalculation();

        //ui->plainTextEdit_show->textCursor().movePosition(QTextCursor::Start);
        QString bufStr = ui->plainTextEdit_show->toPlainText();
        bufStr = "(" + bufStr;
        //bufStr.insert(0, "(");
        //ui->plainTextEdit_show->textCursor().insertText("(");
        //ui->plainTextEdit_show->setPlainText(bufStr);
        //ui->plainTextEdit_show->textCursor().movePosition(QTextCursor::End);
        ui->plainTextEdit_show->insertPlainText(calc.getStr() + ") ^ ");
        ui->plainTextEdit_enter->clear();

        calc.resetStr();
        lastAction = POWER;
    }
}

void MainWindow::on_pushButton_cos_clicked()
{
    calc.cosStr();
}

void MainWindow::on_pushButton_sin_clicked()
{

    calc.sinStr();
}

void MainWindow::on_pushButton_tan_clicked()
{
    calc.tanStr();
}

void MainWindow::on_pushButton_clearOneLetter_clicked()
{
    calc.resizeStr(calc.getStr().size() - 1);
    ui->plainTextEdit_enter->setPlainText(calc.getStr());
}
