#include <iostream>

using namespace std;

class Countries{
    private:
        string name, climate;
        float population;

    public:
        Countries(string name, string climate, float population):name(name), climate(climate), population(population){}
        ~Countries(){};

        void getName(){
            cout<<name<<'\n';
        }
        void getClimate(){
            cout<<climate<<'\n';
        }
        void getPopulation(){
            cout<<population<<'\n';
        }
    
    Countries(const Countries &CountriesSec){
        name = CountriesSec.name;
        climate = CountriesSec.climate;
        population = CountriesSec.population;
    };

    Countries& operator = (const Countries &countries){
        return *this;
    };
};



int main(){
    Countries romania("Romania","temperat",19.31);
    Countries romania2 = Countries(romania);
    Countries romania3(romania2);

    romania.getName();
    romania2.getClimate();
    romania3.getPopulation();

    return 0;
}