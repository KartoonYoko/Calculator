#include "calc.h"

Calc::Calc(){}
void Calc::reset(){
    setStr("");
    setResult(0);
}
void Calc::resetResult(){
    setResult(0);
}
void Calc::resetStr(){
    setStr("");
}



void Calc::appendStr(int num){
    switch (num) {
        case 1:
            this->_s.append("1");
            break;
        case 2:
            this->_s.append("2");
            break;
        case 3:
            this->_s.append("3");
            break;
        case 4:
            this->_s.append("4");
            break;
        case 5:
            this->_s.append("5");
            break;
        case 6:
            this->_s.append("6");
            break;
        case 7:
            this->_s.append("7");
            break;
        case 8:
            this->_s.append("8");
            break;
        case 9:
            this->_s.append("9");
            break;
        case 0:
            this->_s.append("0");
            break;
    }
}
void Calc::appendStr(QString str){
    this->_s.append(str);
}

void Calc::setStr(QString str){
    this->_s = str;
}
QString Calc::getStr(){
    return this->_s;
}


void Calc::setResult(typeOfCalc num){
    this->_result = num;
}
typeOfCalc Calc::getResult(){
    return this->_result;
}
QString Calc::resulToString(){
    QString s = QString::number(this->_result);
    return s;
}



void Calc::add(){
    this->_result += this->_s.toDouble();
}
void Calc::sub(){
    this->_result -= this->_s.toDouble();
}
void Calc::div(){
    if(this->_s.toDouble() == 0) {
       throw invalidValue;
    }
    else{
        this->_result /= this->_s.toDouble();
    }
}
void Calc::mult(){
    this->_result *= this->_s.toDouble();
}


void Calc::add(typeOfCalc num){
    this->_result += num;
}
void Calc::sub(typeOfCalc num){
    this->_result -= num;
}


void Calc::sinStr(){
    this->_s = QString::number(sin(this->_s.toDouble() * PI / 180));
}
void Calc::cosStr(){
    this->_s = QString::number(cos(this->_s.toDouble() * PI / 180));
}
void Calc::tanStr(){
    this->_s = QString::number(tan(this->_s.toDouble() * PI / 180));
}
void Calc::lnStr(){
    this->_s = QString::number(log(this->_s.toDouble()));
}
void Calc::expStr(){
    this->_s = QString::number(exp(this->_s.toDouble()));
}
void Calc::powerStr(double num){
    double a = this->_s.toDouble();
    double result = 1;
    for(int i = 0; i < trunc(num); i++)
        result *= a;
    this->_s = QString::number(result);
}


void Calc::resizeStr(int num){
    this->_s.resize(num);
}
