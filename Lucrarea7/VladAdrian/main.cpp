//item 20, 22, 23
#include <iostream>

using namespace std;

namespace Teen{
class Teen{
    private://item22
    string name, surname;
    int age;

    public:
    Teen(){}
    Teen(const string& n, const string& s, const int& a ):name(n), surname(s), age(a){}

    virtual ~Teen(){}

    Teen(const Teen &anotherTeen):name(anotherTeen.name), surname(anotherTeen.surname), age(anotherTeen.age){}

    Teen& operator = (const Teen& anotherTeen){
        if(this == &anotherTeen) return *this;

        name = anotherTeen.name;
        surname = anotherTeen.surname;
        age = anotherTeen.age;

        return *this;
    }

    string getName() const{//item22
        return name;
    }

    string getSurname() const{//item22
        return this->surname;
    }

    int getAge() const{//item22
        return this->age;
    }

    void setName(const string& n){//item22
        this->name = n;
    }

    void setSurname(const string& s){//item22
        this->surname = s;
    }

    void setAge(const int& a){//item22
        this->age = a;
    }
};
}

namespace Student{//this namespace declaration and validatestudent function -> item 23
class Student: public Teen::Teen{
    private:
        string university;

    public:
        Student(){}

        Student(const string& n, const string& s, const int& a, const string& u):Teen(n, s, a), university(u){}

        ~Student(){}

        Student(const Student& anotherStudent): Teen(anotherStudent.getName(), anotherStudent.getSurname(), anotherStudent.getAge()), university(anotherStudent.getUniversity()){}

        Student(const Teen& t, string u):Teen(t.getName(), t.getSurname(), t.getAge()), university(u){}

        Student& operator = (const Student& anotherStudent){
        if(this == &anotherStudent) return *this;
        Teen::operator=(anotherStudent);
        university = anotherStudent.university;

        return *this;
    }

        string getUniversity() const{
            return this -> university;
        }

        void setUniversity(const string& u) {
            this ->university = u;
        }

};

bool validateStudent(const Student& s){//item20
    if(s.getName() == "Vlad"){
        cout<<"Validat!"<<'\n';

        return true;
    }else{
        cout<<"Nevalidat"<<'\n';

        return false;
    }
}

}


int main(){

    Teen::Teen t1("Vlad", "Adrian", 22);
    Teen::Teen t2;
    t2 = t1;
    const Student::Student stud(t1, "Poli");//item20

    cout<<t1.getName()<<' '<<t1.getSurname()<<' '<<t1.getAge()<<'\n';//item22
    validateStudent(stud);//item20
    t1.setName("Mihai"); t1.setSurname("Bobita"); t1.setAge(44);//item22
    cout<<t1.getName()<<' '<<t1.getSurname()<<' '<<t1.getAge()<<'\n';//item22
    cout<<t2.getName()<<' '<<t2.getSurname()<<' '<<t2.getAge()<<'\n';//item22
    

    return 0;
}