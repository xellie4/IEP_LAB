#include <iostream>
#include <list>
#include <math.h>
#include <iomanip>
#include <map>

using namespace std;

class Punct{
    private:
        int x,y;

    public:
        
        // Punct(int x, int y):x(x),y(y){}
        Punct(int a, int b){
            x = a;
            y = b;
        }

        void setX(int a){ x = a; }

        void setY(int b){ y = b; }

        int getX(){ return this->x; }

        int getY(){ return this->y; }
};

class Figura{
    protected:
        list<Punct> listaPuncte;
    
    public:
        float perimetrul(){
            //perimeter of a polygon by coordinates: we calculate the distance between 2 points an added it to a sum that represents the parameter
            float sum = 0.00;
            int size = listaPuncte.size();
            float aux = 0.0;

            for(std::list<Punct>::iterator it = listaPuncte.begin(); it != listaPuncte.end(); ++it){
                aux++;
                std::list<Punct>::iterator next;
                if(aux == size){
                    next = listaPuncte.begin();
                }else{
                    next = next = std::next(it, 1);
                }
                //'it' is the current element list, C++ 11 has next for the next element in the list
                sum += sqrt(pow((it->getX()-next->getX()),2)+pow((it->getY()-next->getY()),2));
            }
            std::cout<<fixed<< setprecision(2)<< sum;
            return sum;
        }

        list<Punct> getListaPuncte(){
            return listaPuncte;
        }

        void punctModificat(int x, int y, int index){
            list<Punct>::iterator it = listaPuncte.begin();
            std::advance(it, index);
            it->setX(x);
            it->setY(y);

        }
};

class Triunghi: public Figura{
    public:
        Triunghi(Punct p1, Punct p2, Punct p3){
            listaPuncte = {p1, p2, p3};
        }

        Triunghi(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
            Punct pct1 = Punct(p1.first, p1.second), pct2 = Punct(p2.first, p2.second), pct3 = Punct(p3.first, p3.second);
            listaPuncte = {pct1, pct2, pct3};
        }
};

class Dreptunghi: public Figura{
    public:
        Dreptunghi(Punct p1, Punct p2, Punct p3, Punct p4){
            listaPuncte = {p1, p2, p3, p4};
        }

        Dreptunghi(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4){
            Punct pct1 = Punct(p1.first, p1.second);
            Punct pct2 = Punct(p2.first, p2.second);
            Punct pct3 = Punct(p3.first, p3.second);
            Punct pct4 = Punct(p4.first, p4.second);
            listaPuncte.push_back(pct1);
            listaPuncte.push_back(pct2);
            listaPuncte.push_back(pct3);
            listaPuncte.push_back(pct4);
        }
};

class Pentagon: public Figura{
    public:
        Pentagon(Punct p1, Punct p2, Punct p3, Punct p4, Punct p5){
            listaPuncte = {p1, p2, p3, p4, p5};
        }

        Pentagon(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4, pair<int, int> p5){
            Punct pct1 = Punct(p1.first, p1.second);
            Punct pct2 = Punct(p2.first, p2.second);
            Punct pct3 = Punct(p3.first, p3.second);
            Punct pct4 = Punct(p4.first, p4.second);
            Punct pct5 = Punct(p5.first, p5.second);
            listaPuncte.push_back(pct1);
            listaPuncte.push_back(pct2);
            listaPuncte.push_back(pct3);
            listaPuncte.push_back(pct4);
            listaPuncte.push_back(pct5);
        }
};


class Cerc : public Figura{
    public:
        static Cerc* getInstance(Punct p1, int raza){//changed this because of an error for initiliazation of reference non-const with lvalue
            if(instance != 0)
                throw -1;
            else{
                instance = new Cerc(raza, p1);
                return instance;
            }
        }

        Cerc(Cerc const&) = delete;
        void operator = (Cerc const&) = delete;

        int getRaza(){
            return raza;
        }

        float perimetrul(){//override perimetrul figurii pentru cerc;
            return 6.283 * raza;
        }
    protected:
        static Cerc *instance;
        int raza;
        Cerc(int r, Punct p1) { this->raza = r; this->listaPuncte = { p1 }; }
};
Cerc *Cerc::instance = 0;

//panta a primelor doua puncte din lista
template<class Figura>
void pantaDreapta(Figura f){
    cout<<"aici2\n";
    list<Punct> lista = f.getListaPuncte();
    list<Punct>::iterator it = lista.begin();
    list<Punct>::iterator it2 = lista.begin();
    std::advance(it2, 1);
    float panta = (float)(it2 -> getY() - it -> getY())/(float)(it2 -> getX() - it -> getX());
    std::cout<< panta << '\n';
}

template<class Figura>
bool figuraCerc(Figura f, Cerc &c){
    list<Punct>::iterator it;
    list<Punct> lista = f.getListaPuncte();
    list<Punct> lista2 = c.getListaPuncte();//are un singur punct, centrul cercului
    Punct centrulCercului = lista2.back();
    cout<<"centrul cercului: "<< centrulCercului.getX()<<'\n';
    for(it = lista.begin(); it != lista.end(); ++it){
        if ((pow((float)it->getX() - centrulCercului.getX(),2) + pow((float)it->getY() - centrulCercului.getY(), 2)) == pow((float)c.getRaza(), 2)){
            return true;
        }
    }
    return false;
}


int main()
{
    int option;
    map<string, Figura> dictFiguri;
    int contorT = 0, contorD = 0, contorP = 0;
    string formatKey;
    list<Punct> listaPuncte2;
    Cerc *cerc = NULL;
    try{
    while(1){
        std::cout<<"1. Adauga triunghi"<<'\n';
        std::cout<<"2. Adauga dreptunghi"<<'\n';
        std::cout<<"3. Adauga pentagon"<<'\n';
        std::cout<<"4. Adauga cerc"<<'\n';
        std::cout<<"5. Adauga puncte"<<'\n';//nu stiu ce sa fac cu punctele adaugate?? le voi adauga intr-o lista de puncte
        std::cout<<"6. Modifica punctele"<<'\n';//ma gandesc ca punctele figurilor deja create
        std::cout<<"7. Afisare panta pentru figura aleasa"<<'\n';
        std::cout<<"8. Afla daca figura are puncte pe cerc"<<'\n';
        std::cout<<"9. Afiseaza figurile create"<<'\n';
        std::cout<<"10. Afiseaza perimetrul unei figuri"<<'\n';
        std::cout<<"11. Exit\n";
        std::cout<<"Optiunea aleasa este: ";
        std::cin >> option;
        switch(option){
            case 1:{
                int x, y;
                std::cout<<"Coordonate puncte triunghi:"<<'\n';
                Punct *p1, *p2, *p3;
                std::cout<<"Coordonate pentru primul punct: x= ";
                std::cin>>x;
                std::cout<<" y=  ";
                std::cin>>y;
                p1 = new Punct(x, y);

                std::cout<<"Coordonate pentru al doilea punct: x= ";
                std::cin>>x;
                std::cout<<" y=  ";
                std::cin>>y;
                p2 = new Punct(x, y);

                std::cout<<"Coordonate pentru al treilea punct: x= ";
                std::cin>>x;
                std::cout<<" y=  ";
                std::cin>>y;
                p3 = new Punct(x, y);

                Triunghi t(*p1, *p2, *p3);
                contorT++;
                formatKey = "Triunghi" + to_string(contorT);
                std::cout<<"Figura este retinuta in dictionarul cu figuri astfel: "<< formatKey<<'\n';
                dictFiguri.insert(pair<string, Figura>(formatKey, t));
                break;
            }
            case 2:{
                int x, y;
                std::cout<<"Coordonate puncte dreptunghi:"<<'\n';
                Punct *p1, *p2, *p3, *p4;
                std::cout<<"Coordonate pentru primul punct: x= ";
                std::cin>>x;
                std::cout<<" y=  ";
                std::cin>>y;
                p1 = new Punct(x, y);

                std::cout<<"Coordonate pentru al doilea punct: x= ";
                std::cin>>x;
                std::cout<<" y=  ";
                std::cin>>y;
                p2 = new Punct(x, y);

                std::cout<<"Coordonate pentru al treilea punct: x= ";
                std::cin>>x;
                std::cout<<" y=  ";
                std::cin>>y;
                p3 = new Punct(x, y);

                std::cout<<"Coordonate pentru al patrulea punct: x= ";
                std::cin>>x;
                std::cout<<" y=  ";
                std::cin>>y;
                p4 = new Punct(x, y);

                Dreptunghi d(*p1, *p2, *p3, *p4);
                contorD++;
                formatKey = "Dreptunghi" + to_string(contorD);
                std::cout<<"Figura este retinuta in dictionarul cu figuri astfel: "<< formatKey<<'\n';
                dictFiguri.insert(pair<string, Figura>(formatKey, d));
                break;
            }
            case 3:{
                int x, y;
                std::cout<<"Coordonate puncte pentagon:"<<'\n';
                Punct *p1, *p2, *p3, *p4, *p5;
                std::cout<<"Coordonate pentru primul punct: x= ";
                std::cin>>x;
                std::cout<<" y=  ";
                std::cin>>y;
                p1 = new Punct(x, y);

                std::cout<<"Coordonate pentru al doilea punct: x= ";
                std::cin>>x;
                std::cout<<" y=  ";
                std::cin>>y;
                p2 = new Punct(x, y);

                std::cout<<"Coordonate pentru al treilea punct: x= ";
                std::cin>>x;
                std::cout<<" y=  ";
                std::cin>>y;
                p3 = new Punct(x, y);

                std::cout<<"Coordonate pentru al patrulea punct: x= ";
                std::cin>>x;
                std::cout<<" y=  ";
                std::cin>>y;
                p4 = new Punct(x, y);

                std::cout<<"Coordonate pentru al std::cincilea punct: x= ";
                std::cin>>x;
                std::cout<<" y=  ";
                std::cin>>y;
                p5 = new Punct(x, y);

                Pentagon p(*p1, *p2, *p3, *p4, *p5);
                contorP++;
                formatKey = "Pentagon" + to_string(contorP);
                std::cout<<"Figura este retinuta in dictionarul cu figuri astfel: "<< formatKey<<'\n';
                dictFiguri.insert(pair<string, Figura>(formatKey, p));
                break;
            }
            case 4:{
                int x, y, raza;
                std::cout<<"Coordonate puncte pentr:"<<'\n';
                std::cout<<"Coordonate pentru punct: x= ";
                std::cin>>x;
                std::cout<<" y=  ";
                std::cin>>y;
                std::cout<<"Raza cercului: ";
                std::cin>>raza;
                Punct p1(x, y);

                cerc = Cerc::getInstance(p1, raza);
                std::cout<<"Figura este retinuta in dictionarul cu figuri astfel: Cerc"<<'\n';
                dictFiguri.insert(pair<string, Figura>("Cerc", *cerc));
                break;
            }
            case 5:{
                std::cout<<"Adauga punct: "<<"x= ";
                int x,y;
                std::cin>>x;
                std::cout<<"y= ";
                std::cin>>y;
                Punct p(x, y);
                listaPuncte2.push_back(p);
                break;
                }
            case 6:{
                std::cout<<"Introdu numele figuri, daca nu mai tin minte introdu 'exit' si alege optiunea 9\n";
                string opt;
                std::cin>>opt;
                if(opt == "exit"){
                    break;
                }else{
                    map<string, Figura>::iterator it;
                    it = dictFiguri.find(opt);
                    if(it != dictFiguri.end()){
                        Figura f = it->second;
                        list<Punct> puncteFigura = f.getListaPuncte();
                        list<Punct>::iterator p = puncteFigura.begin();
                        std::cout<<"Care punct sa fie modificat, introdceti index(de la 0 incepand): ";
                        int x;
                        std::cin>>x;
                        if(x < 0){
                            break;
                        }else if(x > 3 && puncteFigura.size() == 3 || (x > 4 && puncteFigura.size() == 4) || (x > 5 && puncteFigura.size() == 5)){
                            break;
                        }
                        std::advance(p, x);
                        std::cout<<"Valorile punctelor sunt: "<<p->getX()<<' '<<p->getY();
                        std::cout<<"Introduceti noile valori: x= ";
                        int a,b;
                        std::cin>>a;
                        std::cout<<"y= ";
                        std::cin>>b;
                        it->second.punctModificat(a, b, x);
                        
                        break;
                    }else{
                        std::cout<<"Nume gresit sau figura nu exista. Prima litera din nume este mare!'\n";
                    }
                }
                break;
                }
            case 7:{
                std::cout<<"Introdu numele figuri, daca nu mai tin minte introdu 'exit' si alege optiunea 9\n";
                string opt;
                std::cin>>opt;
                if(opt == "exit"){
                    break;
                }else{
                    map<string, Figura>::iterator it;
                    it = dictFiguri.find(opt);
                    if(it != dictFiguri.end()){
                        cout<<"Aici\n";
                        std::cout<<"Panta figurii este: "; pantaDreapta(it->second);
                        break;
                    }else{
                        std::cout<<"Nume gresit sau figura nu exista. Prima litera din nume este mare!'\n";
                        break;
                    }
                }

                break;
            }
            case 8:{
                std::cout<<"Introdu numele figuri, daca nu mai tin minte introdu 'exit' si alege optiunea 9\n";
                string opt;
                std::cin>>opt;
                if(opt == "exit"){
                    break;
                }else{
                    map<string, Figura>::iterator it;
                    map<string, Figura>::iterator it2;
                    it2 = dictFiguri.find("Cerc");
                    it = dictFiguri.find(opt);
                    if(it != dictFiguri.end()){
                        bool x = figuraCerc(it->second, *cerc);
                        if(x){
                            cout<<"Apartine"<<'\n';
                        }else{
                            cout<<"Nu apartine"<<'\n';
                        }
                    }else{
                        std::cout<<"Nume gresit sau figura nu exista. Prima litera din nume este mare!'\n";
                        break;
                    }
                    break;
                }
            }
            case 9:{
                std::map<string, Figura>::iterator it = dictFiguri.begin();
                for(it; it!=dictFiguri.end(); ++it){
                    std::cout<<it->first<<' ';
                }
                std::cout<<'\n';
                break;
            }
            case 10:{
                std::cout<<"Introdu numele figuri, daca nu mai tin minte introdu 'exit' si alege optiunea 9\n";
                string opt;
                std::cin>>opt;
                if(opt == "exit"){
                    break;
                }else if(opt != "Cerc"){
                    map<string, Figura>::iterator it;
                    it = dictFiguri.find(opt);
                    if(it != dictFiguri.end()){
                        cout<<"Perimetrul este: "<< it->second.perimetrul()<<'\n';
                        break;
                    }else{
                        std::cout<<"Nume gresit sau figura nu exista. Prima litera din nume este mare!'\n";
                        break;
                    }
                }else{
                    cout<<"Perimetrul este: "<<cerc->perimetrul()<<'\n';
                }

                break;
            }
            case 11:{
                return 0;
            }
            default: break;
        }
    }
    }catch(int err){
        std::cout<<"Doar un cerc, err-> "<< err<<'\n';
    }


    return 0;
}