#include <iostream>
#include <memory>

using namespace std;

class Pisici{
    private:
        string nume;
        int ani;
    public:
        Pisici(string n, int a):nume(n),ani(a)
        {
            cout << "se creeaza obiectul\n";
        }   
        
        ~Pisici(){
            cout << "se sterge obiectul\n";
        }
        
        Pisici(Pisici& rhs):nume(rhs.nume),ani(rhs.ani){}
        
        Pisici& operator=(const Pisici &rhs){
            Pisici::operator = (rhs);
            nume = rhs.nume;
            ani = rhs.ani;
            return *this;
        }
    
        void afiseaza(){
            cout << "Nume pisica si varsta: " << nume << " " << ani << "\n";
        }
};

Pisici* createPisici(const string &nume, const int &ani){
    return new Pisici(nume, ani);
}

int main(){
    shared_ptr<Pisici> sptr1(createPisici("Luna", 5));
    shared_ptr<Pisici> sptr2;

    auto_ptr<Pisici> aptr1(createPisici("Pisi", 1));
    auto_ptr<Pisici> aptr2;

    sptr2 = sptr1;
    sptr1->afiseaza();
    sptr2->afiseaza(); //va arata catre aceeaza zona de memorie 

    aptr2 = aptr1;
    //aptr1->afiseaza();
    aptr2->afiseaza();
    
    return 0;
}