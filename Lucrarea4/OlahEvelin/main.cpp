#include <iostream>

using namespace std;

class Ceva{
    public:
        Ceva(string text, int nr); //constructor
        ~Ceva(); //destructor
    private:
        string cevaText;
        int cevaNr; 

	Ceva(const Ceva& rhs); //copy constructor
        Ceva& operator=(const Ceva& rhs); //assignment operator
};

//constructor
Ceva::Ceva(string text, int nr): cevaText(text), cevaNr(nr)
{
    cout << "Se creeaza obiectul" << endl;
}

//destructor
Ceva::~Ceva()
{
    cout << "Se sterge obiectul" << endl;
}

int main()
{
    Ceva c("ceva",10);

    cout << "functie main" << endl;

    return 0;
}