#include<iostream>
#include<vector>
#include<string>

class Student
{
    public:
        std::string imie;
        std::string nazwisko;
        std::vector<float> ocenki;
        float sredniaoc;
        friend class Operacje;
};

class Operacje
{
    public:
        float sredniaocen(std::vector<float> oceny);

};

class Statystyki : Student
{
    public:
        float sredniaocenALL;
        unsigned int liczbaocenALL;
        unsigned int zdany;
        unsigned int niezdany;

};



