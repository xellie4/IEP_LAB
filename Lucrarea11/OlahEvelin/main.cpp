/*Considerand clasa de baza figura, 
construiti 3 clase derivate care sa implementeze figuri geometrice 
si perimetrul acestora (cu numar diferit de laturi).

Fiecare figura contine un vector (sau lista) de puncte.
Clasa punct detine coordonatele unui punct in axele x si y.

Se va folosi o functie template pentru a afla panta dreptei formata din 
oricare doua puncte ale unei figuri geometrice - se poate face pentru primele doua puncte 
din lista de puncte a figurii (vezi exemplu template in C++ from the ground up, 
https://docs.google.com/viewer?a=v&pid=sites&srcid=ZGVmYXVsdGRvbWFpbnxzZnVpY3V8Z3g6MTI1MzI2ZjMyNGNhNWU5Nw, pagina 375 ).

Se va crea clasa singleton cerc, cu o raza specificata si un punct de origine. 
O functie template va fi implementata pentru a determina daca o figura se afla pe cerc 
(verificam daca punctele ce creaza figura, de forma (X,Y), 
satisfac relatia matematica (x-a)^2+ (y-b)^2=R^2, 
unde a si b sunt coordonatele centrului C(a,b)-daca satisfac relatia atunci se afla pe cerc). 
Crearea unui nou cerc va arunca o eroare ce va fi prinsa pentru ca iesirea din program 
sa nu fie brusca.
In main se va crea un meniu care va permite adaugarea de figuri geometrice de tipurile alese, 
adaugarea de puncte, 
modificarea punctelor, 
afisarea pantei dreptei pe o figura aleasa, 
crearea unui cerc, 
verificarea daca o figura are puncte pe cerc.
*/
#include <iostream>
#include <list>
#include <cmath>

using namespace std;

class Punct{
    private:
        double x;
        double y;
    public:
        Punct(double p1, double p2):x(p1),y(p2){
            //cout << "se creeaza obiectul Punct\n";
        }
        
        double getX(){
            return x;
        }
        
        double getY(){
            return y;
        }
        
        void setX(double p){
            x = p;
        }
        
        void setY(double p){
            x = p;
        }
};

class Figura{
    protected:
        list<Punct> puncte;
    public:
        void adaugaPuncte(Punct punct){
            puncte.push_back(punct);
        }
        
        list<Punct> getListOfPuncte(){
            return puncte;
        }
        
};

class Cerc:public Figura{
    private:
        static Cerc* inst_;
        double raza;
        Punct pctOrigine;
        Cerc(int r, Punct p):raza(r),pctOrigine(p){
            //cout << "se creeaza obiectul Cerc\n";
        };
    public:
        static Cerc* getInstance(int r, Punct p){
            if (inst_ == NULL) {
                inst_ = new Cerc(r,p);
                
                return(inst_);
            } else {
                throw -1;
            }
        }
        
        double getRaza(){
            return raza;
        }
        
        Punct getPctOrigine(){
            return pctOrigine;
        }
};     

class Triunghi:public Figura{
    public:
        Triunghi(Punct pct1, Punct pct2, Punct pct3){
            adaugaPuncte(pct1);
            adaugaPuncte(pct2);
            adaugaPuncte(pct3);
            
            cout << "se creeaza obiectul Triunghi\n";
        }
};

class Dreptunghi:public Figura{
    public:
        Dreptunghi(Punct pct1, Punct pct2, Punct pct3, Punct pct4){
            adaugaPuncte(pct1);
            adaugaPuncte(pct2);
            adaugaPuncte(pct3);
            adaugaPuncte(pct4);
            
            cout << "se creeaza obiectul Dreptunghi\n";
        }
};

class Patrat:public Figura{
    public:
        Patrat(Punct pct1, Punct pct2, Punct pct3, Punct pct4){
            adaugaPuncte(pct1);
            adaugaPuncte(pct2);
            adaugaPuncte(pct3);
            adaugaPuncte(pct4);
            
            cout << "se creeaza obiectul Patrat\n";
        }
};

Cerc* Cerc::inst_ = NULL;
    
template<class Figura>
float pantaDreapta(Figura fig){
    
    list<Punct> listaPct = fig.getListOfPuncte();
    
    Punct pct1 = listaPct.front();
    Punct pct2 = listaPct.back();
    
    float panta = (float)(pct2.getY() - pct1.getY())/(float)(pct2.getX() - pct1.getX());
    return panta;
}

template<class Figura>
bool figuraPeCerc(Figura fig, Cerc c){
    
    list<Punct> listaPctFig = fig.getListOfPuncte();
    Punct pctOrig = c.getPctOrigine();
    
    double razaCerc = c.getRaza();
    
    list<Punct>::iterator p;
    for(p = listaPctFig.begin(); p != listaPctFig.end(); ++p){
        if ((pow((float)p->getX() - pctOrig.getX(),2) + pow((float)p->getY() - pctOrig.getY(), 2)) == pow((float)c.getRaza(), 2)){
            return true;
        }
    }
    return false;
}

/*
In main se va crea un meniu care va permite adaugarea de figuri geometrice de tipurile alese, 
adaugarea de puncte, 
modificarea punctelor, 
afisarea pantei dreptei pe o figura aleasa, 
crearea unui cerc, 
verificarea daca o figura are puncte pe cerc.
*/
int main()
{
    int opc;
    
    Figura fig[10];
    int indexFig = 0;
    
    while(1){
        cout << "Meniu\n";
        cout << "1 <- adaugarea de figuri geometrice\n";
        cout << "2 <- adaugarea de puncte\n";
        cout << "3 <- afisarea pantei dreptei pe o figura aleasa\n";
        cout << "4 <- crearea unui cerc\n";
        cout << "5 <- verificarea daca o figura are puncte pe cerc\n";
        cout << "6 <- end\n";
        cout << "Introduceti un nr de la 1 pana la 6:\n";
        
        cin >> opc;
        
        switch(opc)
        {
            case 1:
            {  
                Punct pct1(1,1);
                Punct pct2(1,3);
                Punct pct3(4,6);
                
                Triunghi t(pct1, pct2, pct3);
                fig[indexFig] = t;
                indexFig++;
                
                Punct pct4(0,1);
                Punct pct5(5,4);
                Punct pct6(2,1);
                Punct pct7(3,3);
                
                Dreptunghi d(pct4, pct5, pct6, pct7);
                fig[indexFig] = d;
                indexFig++;
                
                Punct pct8(0,4);
                Punct pct9(2,2);
                Punct pct10(1,4);
                Punct pct11(5,8);
                
                Patrat p(pct8, pct9, pct10, pct11);
                fig[indexFig] = p;
                indexFig++;
                
                break;
            }
            case 2:
            {
                Figura f;
                
                Punct pct1(1,4);
                Punct pct2(2,3);
                Punct pct3(1,6);
                
                f.adaugaPuncte(pct1);
                f.adaugaPuncte(pct2);
                f.adaugaPuncte(pct3);
                
                list<Punct> pct = f.getListOfPuncte();
                
                list<Punct>::iterator it;
                for (it = pct.begin(); it != pct.end(); ++it){
                    cout << it->getX() << " " << it->getY() << "\n";
                }
                
                break;
            }
            case 3:
            {
                int index;
        
                cout << "Alege un numar intre 0 si " << indexFig-1 << "\n"; ;
                cin >> index;
                
                cout << "panta: " << pantaDreapta(fig[index]) << "\n";
                break;
            }
            case 4:
            {
                try{
                    Punct pct1(1,1);
                    int r = 3;
                    Cerc* c = Cerc::getInstance(r, pct1);
                    
                    /* daca stergem urmatoarele doua randuri comentate, 
                    o sa dea eroare deoarece se va incerca crearea celei de a doua instanta */
                    //int r1 = 4;
                    //Cerc* c1 = Cerc::getInstance(r1, pct1);
                } catch (int n){
                    cout << "Exceptie: deja exista o instanta a clasei cerc\n";
                }
                
                break; 
            }
            case 5:
            {
                int index;
                
                Punct pct1(1,1);
                int r = 3;
                Cerc* c = Cerc::getInstance(r, pct1);
                    
                cout << "Alege un numar intre 0 si " << indexFig-1 << "\n"; ;
                cin >> index;
                
                cout << "verificarea daca o figura are puncte pe cerc\n";
                
                if( !figuraPeCerc(fig[index], *c)){
                    cout << "nu se afla\n";
                } else {
                    cout << "se afla\n";
                }
                
                break;
            }
            case 6:
                return 0;
            default:
                break;
        }
    }
    
    return 0;
}
