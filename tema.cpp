#include <iostream>
using namespace std;

class Animal{
    
    public: 
        string animalName, animalGender, animalSound;
        int animalAge;
        Animal(string name, string gender, string sound, int age){
            cout << "Constructor of class Animal has been called" <<"\n";
            animalName = name;
            animalGender = gender;
            animalSound = sound;
            animalAge = age;
        }

        ~Animal() {
            cout << "Desonstructor of main class Animal has been called" <<"\n";
        }

        Animal(const Animal& a) {  //copies  the data of the existing object and assignes it to the new object 
            cout << "Copy constructor of main class Animal has been called --deep copy " <<"\n";
            animalName = a.animalName;
            animalGender = a.animalGender;
            animalSound = a.animalSound;
            animalAge = a.animalAge;
        }

        void makeAnimalSound() {
               cout << "Animal sound is : " << animalSound <<"\n";
        }

        string getName() {
             return animalName;
        }

};

class Cow : public Animal {

    public:
        int milkAmountPerDay;
        Cow(int amount, string animalName, string animalGender, string animalSound, int animalAge) : Animal( animalName,  animalGender,  animalSound,  animalAge){
             cout << "Constructor of class Cow has been called" <<"\n";
            milkAmountPerDay = amount;
        }

        ~Cow() {
             cout << "Desonstructor of class Cow has been called" <<"\n";
        }

       
};

int main()
{
    Animal a("NormalAnimal","male","normalSound",1);
    Animal a2(a);  //copy constructor is called
    Cow milka( 100, "Milka", "female", "mooo", 2);
    
    cout<<milka.getName()<<"\n";
    milka.makeAnimalSound();
   
    return 0; //destructors are called
}