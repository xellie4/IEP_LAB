//item 13, 14, 15
#include <iostream>
#include <memory>

using namespace std;

class Countries{
    protected:
        string name;

    public:
        Countries(const string &name):name(name){}

        virtual ~Countries(){}

        Countries(const Countries &rhs):name(rhs.name){}

        Countries& operator=(const Countries &rhs){
            string *nameOriginal = &name;
            name = rhs.name;
            delete nameOriginal;

            return *this;
        }

        virtual void getDetails(){}
};

class DetailedCountry:public Countries{
    private:
        int population;

    public:
     DetailedCountry(const string &name, const int &population): Countries(name), population(population){}

     ~DetailedCountry(){
         cout<<"deleted"<<'\n';
     }

     DetailedCountry(DetailedCountry& rhs):Countries(rhs),population(rhs.population){}

     DetailedCountry& operator=(const DetailedCountry &rhs){
         Countries::operator = (rhs);
         population = rhs.population;
         return *this;
     }

     void getDetails(){
         cout<<"Name: "<<name<<" with population: "<<population<<'\n';
     }
};

DetailedCountry* createDetailedCountry(const string &name, const int &population){//factory function that returns a pointer
    return new DetailedCountry(name, population);
}

int main(){
    shared_ptr<DetailedCountry> shptr1(createDetailedCountry("Romania", 22 ));
    shared_ptr<DetailedCountry> shptr2;

    auto_ptr<DetailedCountry> autoptr1(createDetailedCountry("Germany", 66));
    auto_ptr<DetailedCountry> autoptr2;

    shptr2 = shptr1;
    cout<<"SharedPointers: \n";
    cout<<"SharedPointer1: ";
    shptr1->getDetails();
    cout<<"SharedPointer2: ";
    shptr1->getDetails();

    cout<<"AutoPointers: \n";
    autoptr2 = autoptr1;
    cout<<"AutoPointer2: ";
    autoptr2->getDetails();

    cout<<"Calling autoptr1->getDetails would get us a segmentation fault beucause of the property of autopointers";
    cout<<". Also seems like autoPointers got deprecated and unique_pointers is suggested to replace with.";

    return 0;
}