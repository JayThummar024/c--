#include <iostream>
using namespace std;

class AbstractEmployee{
    // this is like a contract that any class that signs this contract will have to create the below given function
    
    virtual void AskForPromotion()=0; //pure virtual function
};

//abstraction
class Employee:AbstractEmployee{
    private:
        string Company;
        int Age;
    protected:
        string Name;

    public:
        // setters & getters-  set / retrive data which is encapsulated
        void setName(string name){
            Name = name;
        }
        string getName(){
            return Name;
        }

        void setCompany(string company){
            Company = company;
        }

        string getCompany() {
            return Company;
        }

        void setAge(int age){
            if(age>=18){
                Age = age;
            }
        }

        int getAge(){
            return Age;
        }

        Employee(string name , string company , int age){
            Name = name;
            Company = company;
            Age = age;
        }

        void introduceYourSelf(){
            cout<<"Name : "<<Name<<endl;
            cout<<"Company : "<<Company<<endl;
            cout<<"Age : "<<Age<<endl;
        }

        void AskForPromotion(){

            if(Age>30){
                cout<< Name << " congrats! You are Promoted" <<'\n';
            }else{
                cout << Name << " You can't be promoted" <<'\n';
            }
        }

        // virtual for polymorphism using pointers
        virtual void work(){
            cout<< Name << " is reading Emails"<<endl;
        }
};
// inheritance
class Developer: public Employee{ //by default it is private
    public:
        string FavProgrammingLanguage;
        Developer(string name , string company , int age , string favProgrammingLanguage)
        :Employee(name ,company , age )
        {
            FavProgrammingLanguage = favProgrammingLanguage;
        }

        void fixBug(){
            cout<< Name <<" Fixed Bugs using "<<FavProgrammingLanguage<<"\n";
        }

        //polymorphism
        void work(){
            cout<< Name << " is writing code"<<endl;
        }
};

class Teacher: public Employee{
    public:
        string Subject;
        void prepareSubjects(){
            cout<< Name <<" is preparing " <<Subject<<'\n';
        }

        Teacher(string name , string company , int age , string subject)
        :Employee(name , company,age){
            Subject = subject;
        }

        //polymorphism
        void work(){
            cout<< Name << " is giving homework"<<endl;
        }
};

int main(){
    Developer dev1 = Developer("Jay","Google",21,"c++");
    Teacher t1 = Teacher("Vimal","Apple",41,"Physics");

    // dev1.work();
    // t1.work();

    Employee* e1 = &dev1;
    Employee* e2 = &t1;

    e1->work();   //polymorphism using pointers , for this method in the parant class must be virtual function
    

    return 0; 
}