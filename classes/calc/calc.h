#ifndef CALC_H
#define CALC_H
#include <QString>
#include <cmath>

#define PI 3.14159265  // число ПИ

typedef double typeOfCalc;

enum exceptionCalc { invalidValue };

class Calc
{

private:

    typeOfCalc _result = 0; // stores result calculation of previous calculations and entered number(in QString)
    QString _s = ""; // stores entered number in QString

public:


    Calc();
    void reset();// сбрасывает значения на начальные
    void resetResult();
    void resetStr();

    void appendStr(int num);
    void appendStr(QString str);

    void setStr(QString str);
    QString getStr();
    void resizeStr(int num);


    void setResult(typeOfCalc num);
    typeOfCalc getResult();
    QString resulToString();

    void add();  // adds _result and _s after puts result in _result
    void sub();  //
    void div();  //
    void mult(); //

    void sinStr();
    void cosStr();
    void tanStr();
    void lnStr();
    void expStr();
    void powerStr(double num);


    void add(typeOfCalc num);
    void sub(typeOfCalc num);

};

#endif // CALC_H
