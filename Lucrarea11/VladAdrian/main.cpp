#include <iostream>
#include <list>
#include <math.h>
#include <iomanip>

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
            float sum = 0;
            int size = listaPuncte.size();
            int aux = 0;

            for(std::list<Punct>::iterator it = listaPuncte.begin(); it != listaPuncte.end(); ++it){
                aux++;
                std::list<Punct>::iterator next;
                if(aux == size){
                    next = listaPuncte.begin();
                }else{
                    next = next = std::next(it, 1);
                }
                //'it' is the current element list, C++ 11 has next for the next element in the list
                sum += sqrt(pow((next->getX() - it->getX()), 2) + pow((next -> getY() - it -> getY()), 2));
            }
            std::cout<<std::fixed<<std::setprecision(2)<<"Perimetrul este: "<< sum;
            return sum;
        }

        list<Punct> getListaPuncte(){
            return listaPuncte;
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
        static Cerc& getInstance(Punct p1, int raza){
            if(instance != 0)
                throw -1;
            else{
                instance = new Cerc(raza, p1);
                return *instance;
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
float pantaDreapta(Figura f){
    Punct p1 = f.getListaPuncte()[0];
    Punct p2 = f.getListaPuncte()[1];

    return ((p2.getY() - p1.getY())/(p1.getX() - p2.getX()));
}

template<class Figura>
bool figuraCerc(Figura f, Cerc c){
    return true;
}


int main()
{
    try{
    Punct x = Punct(0, 0);
    Punct y = Punct(1, 1);
    Punct z = Punct(2, 2);
    Cerc &c1 = Cerc::getInstance(x, 10);
    Triunghi t1 = Triunghi(x,y,z);
    cout<< t1.perimetrul()<<'\n';
    cout<< c1.getRaza()<< "   "<< c1.perimetrul();
    }catch(int err){
        cout<<"Doar un cerc, err-> "<< err<<'\n';
    }


    return 0;
}