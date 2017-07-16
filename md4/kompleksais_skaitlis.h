#ifndef KOMPLEKSAIS_SKAITLIS_H
#define KOMPLEKSAIS_SKAITLIS_H
#include <iostream>
using namespace std;

class kompleksais_skaitlis///klases deklaresana
{
    double a;///glabajas kompleksa skaitla reala dala
    double b;///glabajas kompleksa skaitla imaginara dala

public:
    kompleksais_skaitlis(double ,double );///konstruktors, kuram padod #1 komplekso skaitli
    void drukat();///metodes "drukat" deklaresana
    void pieskaitit(double, double);///metodes "pieskaitit" deklaresana
    void reizinat(double, double );///metodes "reizinat" deklaresana
    void dalit(double, double );///(nebija uzd.prasita) metodes "dalit" deklaresana
    ~kompleksais_skaitlis();///destruktors
};

#endif // NUMBERS_H
