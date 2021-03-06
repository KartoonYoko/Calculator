#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "../../Calculator/untitled/classes/calc/calc.h"
#include "../Calculator/classes/calc/calc.h"
#include <QTextCursor>
#include <vector>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct sHistory{
    QString str;
    double result;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Calc calc; // класс калькулятор с методами для вычисления
    QString str; // хранит вычесление
    bool firstOperation = true; // проверка на первую операцию
    bool exc = false; // для получения исключения
    std::vector<sHistory> history; // хранит историю
    bool isHistoryVisible = false;

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_clearAll_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_point_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_equal_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_subtract_clicked();

    void on_pushButton_multiply_clicked();

    void on_pushButton_divide_clicked();

    void on_pushButton_changeOcthorpe_clicked();

    void on_pushButton_ln_clicked();

    void on_pushButton_exp_clicked();

    void on_pushButton_power_clicked();

    void on_pushButton_cos_clicked();

    void on_pushButton_sin_clicked();

    void on_pushButton_tan_clicked();

    void on_pushButton_backSpace_clicked();

    void on_pushButton_history_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
