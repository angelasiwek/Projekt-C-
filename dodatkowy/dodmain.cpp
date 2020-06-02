#include "dod.h"

int main()
{
    int i, j;
    unsigned int liczbauczniow;
    std::cout << "Ilu uczniow chcesz dodac?" << std::endl;
    std::cin >> liczbauczniow;
    std::vector<Student> studenci;
    std::vector<Operacje> srednieocen;
    Statystyki statystyki1;
    Student stud;
    std::string im, naz;
    std::vector<float> oc;
    float ocena1;
    float srednia = 0;
    unsigned int liczbaocen;
    statystyki1.zdany = 0;
    statystyki1.niezdany = 0;
    statystyki1.liczbaocenALL = 0;
    statystyki1.sredniaocenALL = 0;
    for( i = 0; i < liczbauczniow; i++)
    {
        srednia = 0;
        liczbaocen = 0;
        std::cout << "Podaj imie i nazwisko studenta nr " << i+1 << std::endl;
        std::cin >> stud.imie;
        std::cin >> stud.nazwisko;

        std::cout << "Wpisz ile ocen chcesz przypisac do studenta " << std::endl;
        std::cin >> liczbaocen;
        std::cout << "Wpisz teraz te oceny: " << std::endl;
        for(j = 0; j < liczbaocen ; j++)
        {
            std::cin >> ocena1;
            stud.ocenki.push_back(ocena1);
        }
        studenci.push_back(stud);
        srednia = srednieocen[i].sredniaocen(studenci[i].ocenki);
        statystyki1.liczbaocenALL += liczbaocen;
        statystyki1.sredniaocenALL += srednia;
        std::cout << "Srednia ocen studenta " << studenci[i].imie << " " << studenci[i].nazwisko << " " << srednia << std::endl;
        if(srednia >= 3)
        {
            statystyki1.zdany += 1;
            std::cout << "Student ten zdal. " << std:: endl;
        }
        else 
        {
            statystyki1.niezdany += 1;
            std::cout << "Student ten nie zdal. " << std::endl;
        }
        
    }
    statystyki1.sredniaocenALL = statystyki1.sredniaocenALL / statystyki1.liczbaocenALL ;
    std::cout << "Srednia ocen wszystkich uczniow to " << statystyki1.sredniaocenALL << std::endl;
    std::cout << "Liczba uczniow ktorzy zdali przedmiot to " << statystyki1.zdany << std::endl;
    std::cout << "Liczba uczniow ktorzy nie zdali przedmiotu to " << statystyki1.niezdany << std::endl;
    return 0;
}