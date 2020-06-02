#include "dod.h"

 float Operacje::sredniaocen(std::vector<float> oceny)
        {
            float wynik = 0;
            for(int i = 0; i < oceny.size(); i++)
            {
                wynik += oceny[i];
            }
            wynik = wynik/(oceny.size());
            return wynik;
        }