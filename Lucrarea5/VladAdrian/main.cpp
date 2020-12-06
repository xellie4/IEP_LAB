//item 7,11,12
#include <iostream>

using namespace std;

class Countries{
    protected:
        string name;

    public:
        Countries(string name):name(name){}

        virtual ~Countries(){}

        Countries(const Countries& rhs):name(rhs.name){}

        Countries& operator=(const Countries &rhs){
            string *nameOriginal = &name;
            name = rhs.name;
            delete nameOriginal;

            return *this;
        }

        virtual void getDetails(){}
};

class Romania:public Countries{
    private:
        int population;

    public:
     Romania(string name, int population): Countries(name), population(population){}

     ~Romania(){
         cout<<"deleted"<<'\n';
     }

     Romania(const Romania& rhs):Countries(rhs),population(rhs.population){}

     Romania& operator=(const Romania &rhs){
         Countries::operator = (rhs);
         population = rhs.population;
         return *this;
     }

     void getDetails(){
         cout<<"Name: "<<name<<" with population: "<<population<<'\n';
     }
};

int main(){
    Countries *c;
    Romania *r = new Romania("Romania", 20);

    c = r;
    delete c;

    Romania r2("Romania2", 18);
    Romania r3(r2);
    r2.getDetails();
    cout<<"Other details\n";
    r3.getDetails();

    return 0;
}