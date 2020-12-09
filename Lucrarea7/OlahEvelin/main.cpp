#include <iostream>
#include <memory>

using namespace std;
// lucrarea 7: item 21, 22, 23

//item 23
namespace Camere{

class CameraFoto{
    private:
        string numeCamera;
        int nrCadre;
    public:
        CameraFoto(string nume, int nr):
            numeCamera(nume),
            nrCadre(nr)
            {
                cout << "se creeaza obiectul\n";
            };
            
        CameraFoto(){}
        ~CameraFoto(){
            cout << "se sterge obiectul\n";
        }
        
        //item 22: settere si gettere pentru atributele unei clase care sunt declarate private
        void setNumeCamera(const string& nume){
            this->numeCamera = nume;
        }
        void setNrCadre(const int& nr){
            this->nrCadre = nr;
        }
        
        string getNumeCamera(){
            return this->numeCamera;
        }
        int getNrCadre(){
            return this->nrCadre;
        }
        
        //print
        void afisare(){
            cout << "Nume camera si nr cadre:" << this->numeCamera << " " << this->nrCadre << "\n";
        }
        
        const CameraFoto operator+(CameraFoto& lhs)const; //21 item
};

//item 21
inline const CameraFoto operator+(CameraFoto& lhs, CameraFoto& rhs){
    return CameraFoto(lhs.getNumeCamera() + rhs.getNumeCamera(), lhs.getNrCadre() + rhs.getNrCadre() );
}
  string numeCamera;
        int nrCadre;
bool verifNrCadrePesteOVal(CameraFoto f, int x){
    if (f.getNrCadre() > x){
        return true;
    } else {
        return false;
    }
}

}

int main()
{
    Camere::CameraFoto cF("Canon 6D", 1200);
    
    cF.afisare();
    
    cF.setNrCadre(1201);
    
    cout << "nr cadre: " << cF.getNrCadre() << "\n";
    
    cout << "verificare daca nr de cadre este peste 200:\n";
    cout << verifNrCadrePesteOVal(cF,200) << "\n";

    //item 21
    Camere::CameraFoto cF2("Canon 5D", 5);
    Camere::CameraFoto sum(" ", 0);
    
    sum = cF + cF2;
    
    sum.afisare();
    return 0;
}
