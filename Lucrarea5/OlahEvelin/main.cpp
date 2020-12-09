#include <iostream>

using namespace std;

// base class
class Ceva{
    public:
        Ceva(string text, int nr); //constructor
        virtual ~Ceva(); //destructor
        Ceva& operator=(const Ceva& rhs); //assignment operator
        void getCeva();
    protected:
        string cevaText;
        int cevaNr;
};

//constructor
Ceva::Ceva(string text, int nr): cevaText(text), cevaNr(nr)
{
    cout << "Se creeaza obiectul Ceva" << endl;
}

//destructor
Ceva::~Ceva()
{
    cout << "Se sterge obiectul Ceva" << endl;
}

//copy constructor
Ceva& Ceva::operator=(const Ceva& rhs){
    cevaText = rhs.cevaText;
    cevaNr = rhs.cevaNr;
    return * this;
}

void Ceva::getCeva()
{
    cout << cevaText << " " << cevaNr << endl;
}

// derived class
class CevaDerived: public Ceva{
    public:
        CevaDerived(string text, int nr, int nrDerived); //constructor
        ~CevaDerived(); //destructor
        CevaDerived(const CevaDerived& rhs); //copy constructor
        CevaDerived& operator=(const CevaDerived& rhs); //assignment operator
        void getCevaDerived();
    protected:
        int cevaDerivedNr;
};

//constructor calling also base constructor
CevaDerived::CevaDerived(string text, int nr, int nrDerived): 
    Ceva(text,nr),
    cevaDerivedNr(nrDerived)
{
    cout << "Se creeaza obiectul CevaDerived" << endl;
}

//destructor
CevaDerived::~CevaDerived()
{
    cout << "Se sterge obiectul CevaDerived" << endl;
}

//copy assignment operator
CevaDerived& CevaDerived::operator=(const CevaDerived& rhs)
{
    cout << "CevaDerived copy assignment operator" << endl;
    Ceva::operator=(rhs);
    cevaDerivedNr = rhs.cevaDerivedNr;
    return * this;
}

void CevaDerived::getCevaDerived()
{
    cout << cevaDerivedNr << endl;
}

int main()
{
    cout << "functie main" << endl;
    
    Ceva c("ceva",10);
    c.getCeva();

    CevaDerived cD("adssf", 10, 5);
    cD.getCevaDerived();
    
    cD.getCevaDerived();
    cout << "pointer" << endl;
    CevaDerived * cD2 = new CevaDerived("bfgdf", 1, 1);
    cD2 = &cD;
    cD.getCevaDerived();
    cD2->getCevaDerived();
    
    //delete cD2;
    
    return 0;
}