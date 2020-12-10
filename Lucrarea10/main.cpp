#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
->clasa abstracta pasare care va contine :
functia pur virtuala zbroara si
functia pur virtuala sunet, care va afisa sunetul pe care pasarea il face.
*/
class Pasare {
private:
    int distanta_zbor;
    string sunet_pasare;
public:
    virtual void zboara() = 0;
    virtual void sunet() = 0; //va afisa sunetul pe care pasarea il face.
};

/*
->clasa derivata papagal care
va adauga intr-o lista cuvinte pe care le stie papagalul,
poate afisa cuvintele stiute de papagal,
un sunet caracteristic papagalului si cat de departe poate sa zboare acesta.
*/
class Papagal:public Pasare {
private:
    int distanta_zbor;
    string sunet_pasare;
    list<string> lista_cuvinte;
public:
    Papagal(int z, string s):distanta_zbor(z),sunet_pasare(s)
    {
        cout << "se creeaza obiectul\n";
    }

    ~Papagal() {
        cout << "se sterge obiectul\n";
    }

    void adaugaCuvinte(string cuv)
    {
        lista_cuvinte.push_back(cuv);
    }

    //afiseaza cuvintele pe care le stie papagalul
    void afiseazaCuvinte()
    {
        list<string>::iterator it;
        for (it = lista_cuvinte.begin(); it != lista_cuvinte.end(); it++)
        {
            cout << *it << " ";
        }
        cout << "\n";
    }

    void zboara() {
        cout << "distanta de zbor papagal: " << distanta_zbor << "\n";
    }

    void sunet() {
        cout << "sunet papagal: " << sunet_pasare << "\n";
    }
};

/*
->clasa derivata gaina,
numarul maxim de gaini va fi 30(numarul de instante ale clasei - se va folosi o variabila
statica in interiorul clasei ce se va incrementa la instantierea unui element).
O gaina poate sa zboare insa pe o distanta mai mica de 10 m.
O gaina poate fi vanduta pe un alt tip de pasare.
*/
class Gaina :public Pasare {
private:
    int distanta_zbor;
    string sunet_pasare;
    static int nr_max_gaini;
public:
    Gaina(int z, string s)
    {
        if(nr_max_gaini < 30){
            if(z < 10){
                distanta_zbor = z;
                sunet_pasare = s;
                
                nr_max_gaini++;
                cout << "se creeaza obiectul\n";
            }
            else {
                cout << "nu poate zbura mai mult de 10m\n";
                this->Gaina::~Gaina();
            }
        }
        else{
            cout << "s-a atins limita de nr de gaini\n";
            this->Gaina::~Gaina();
        }
    }
    
    ~Gaina()
    {
        cout << "se distruge obiectul\n";
    }
    
    void zboara()
    {
        cout << "distanta de zbor gaina: " << distanta_zbor << "\n";
    }
    
    void sunet()
    {
        cout << "sunet gaina: " << sunet_pasare << "\n";
    }
    
    //to do: O gaina poate fi vanduta pe un alt tip de pasare.
};


/*
->clasa derivata strut.
Aceasta clasa este singleton.
Un singur obiect de tip strut poate sa existe la un moment dat.
Se va implementa adunarea intre un strut si o gaina(supraincarcarea operatorului +),
rezultatul fiind incrementarea numarului de gaini continut de un strut si
scaderea unei gaini din numarul de gaini introduse.
*/
class Strut :public Pasare {

};

int Gaina::nr_max_gaini = 0;

int main()
{
    Papagal ppgl(25, "fgdfgfd");

    ppgl.zboara();
    ppgl.sunet();
    
    ppgl.adaugaCuvinte("sal");
    ppgl.adaugaCuvinte("vlad");
    ppgl.adaugaCuvinte("cf");
    
    ppgl.afiseazaCuvinte();
    
    Gaina gaina1(1,"sdsa");
    
    gaina1.zboara();
    gaina1.sunet();
    
    Gaina gaina2(12,"dfsd");
    
    return 0;
}
