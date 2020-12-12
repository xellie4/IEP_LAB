//mai trebuie vinde pasarea
#include <iostream>
#include <list>
#include <exception>
#include <typeinfo>

using namespace std;

class Pasare{
    public:
        virtual void zboara() = 0;
        virtual void sunet() = 0;
};

class Papagal: public Pasare{
    private:
        list<string> cuvintePapagal = {};
        int dist;
    public:
        Papagal(const int& dist):dist(dist){}
        void zboara(){
            cout<<"Zbor "<<dist<<'\n';
        }

        void sunet(){
            cout<<"Sunet papagal"<<'\n';
        }

        void adaugaCuvinte(string cuv){
            cuvintePapagal.push_back(cuv);
        }

        void getCuvinte(){
            for(list<string>::iterator i = cuvintePapagal.begin(); i != cuvintePapagal.end(); i++ ){
                cout<< *i << ' ';
            }
            cout<<'\n';
        }
};

class Gaina: public Pasare{
    private:
        static int nrGaini;
        int dist;
    public:
        void zboara(){
            cout<<"Zboara "<<dist<<'\n';
        }

        void sunet(){
            cout<<"Sunet gaina"<<'\n';
        }

        Gaina(int d){
            nrGaini++;
            if(nrGaini > 30){
                throw length_error("Too many instances! Delete!");
            }else if(d > 10){
                cout<<"max 10m; please use SetDistance to set distance for this chicken, now it will be set to 0";
                this->dist = 0;
            }else{this->dist = d;}
        }

        void setDistance(int d){
            if(d > 10){
                cout<<"max 10m\n";
            }else {dist = d;}
        }
        ~Gaina(){
            nrGaini--;
        }

        //nu stiu exact ce se cere aici
        Pasare* sell(Pasare *p){
            if(typeid(p) != typeid(Gaina)){
                this->~Gaina();
                return p;
            }
            return p;
        }

        void adunareStrutGaina(){
            cout<<"Nr gaini inainte de adunare:"<<nrGaini<<'\n';
            nrGaini--;
            cout<<"Nr gaini dupa de adunare:"<<nrGaini<<'\n';
        }


};
int Gaina::nrGaini = 0;//without this we get undefined reference for nrGaini because the linker doesn't know where to allocate data without telling him manually

class Strut: public Pasare{
    private:
        Strut(){};//because of being singleton
        int gainiStrut = 0;

    public:
        static Strut& getInstance(){
            static Strut instance;

            return instance;
        }

        Strut(Strut const&) = delete;//we must delete those to block accidentally copy because this is singleton
        void operator=(Strut const&) = delete;


        void zboara(){
            cout<<"Nu zboara\n";
        }

        void sunet(){
            cout<<"Strut sunet\n";
        }

        void operator+(Gaina& gaina){
            cout<<"gaini strut inainte: "<<gainiStrut<<'\n';
            gainiStrut ++;
            gaina.adunareStrutGaina();

            cout<<"gaini strut dupa: "<<gainiStrut<<'\n';
        }
};


int main(){

    Papagal p1 = Papagal(20);
    Gaina g1 = Gaina(8);
    Strut &s1 = Strut::getInstance();
    Pasare *p;
    Pasare* papagal = new Papagal(1);

    p = g1.sell(papagal);
    p->sunet();

    s1.sunet();
    s1.zboara();
    p1.sunet();
    p1.zboara();
    g1.sunet();
    g1.zboara();

    s1+g1;

    Gaina g2 = Gaina(11);
    g2.zboara();
    g2.setDistance(5);
    g2.zboara();
    return 0;
}