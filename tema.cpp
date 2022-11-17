#include <iostream>
using namespace std;

class Animal
{

public:
int *age, *weight;
    string *name;
    Animal(int a, int w, string n); // constructor
    Animal(const Animal &a);        // copy constructor
    Animal(Animal &&a);             // move constructor
    ~Animal();                      // destructor
    int getAnimalAge() { return *age; }
    int getAnimalAWeight() { return *weight; }
};

// Normal constructor
Animal::Animal(int a, int w, string n)
{
    cout << "Normal constructor called.\n";
    age = new int;
    weight = new int;
    name = new string;
    *age = a;
    *weight = w;
    *name = n;
}
// Copy constructor.
Animal::Animal(const Animal &a)
{
    age = new int;
    weight = new int;
    name = new string;
    *age = *a.age;       // copy age
    *weight = *a.weight; // copy weight
    *name = *a.name;     // copy name
    cout << "Copy constructor called.\n";
}

// Move Constructor
Animal::Animal(Animal &&a)
{ // Transfer ownership of a.age to age etc.
    age = a.age;
    weight = a.weight;
    name = a.name;
    a.age = nullptr; // Steal the data and then null out the source pointer
    a.weight = nullptr;
    a.name = nullptr;
    cout << "Move  constructor called.\n";
}

// Desctructor
Animal::~Animal()
{
    cout << "Freeing animal; destructor called\n";
    delete age;
    delete weight;
    delete name;
}

Animal createAnimal(int a, int w, string n)
{
    Animal an(a, w, n); // invoke normal constructor
    return an;          // implicitly invoke copy constructor
}

class Cow : public Animal
{

public:
int *milkLiters;
    Cow(int lit, int a, int w, string n) : Animal(a, w, n)
    {
        cout << "Constructor of class Cow has been called"
             << "\n";
        milkLiters = new int;
        *milkLiters = lit;
    }

    ~Cow()
    {
        delete age;
        delete weight;
        delete name;
        delete milkLiters;
        cout << "Cow destroyed.Destructor of class Cow has been called"
             << "\n";
    }
};

int* getMilkLiters(Cow c)
{
    return c.milkLiters;
}

int main()
{
    Animal a(1, 100, "Animal1"); // normal constr
    cout<<"Animal is " <<a.getAnimalAge()<<" yrs old \n";
    Animal b(a);                 // copy constr
      cout<<"Animal b is " <<b.getAnimalAge()<<" yrs old \n";
    Animal c(std::move(a));
      cout<<"Animal b weights " <<b.getAnimalAWeight()<<" kgs \n";

      Cow cow(10, 2,230,"Milka");
       cout<<"Cow is " <<cow.getAnimalAge()<<" yrs old \n";
    return 0;
}
/*#include <iostream>
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
            if(animalAge!=nullptr) delete animalAge;

            cout << "Animal destroyed.Destructor of main class Animal has been called" <<"\n";
        }

        Animal(const Animal& a) {  //copies  the data of the existing object and assignes it to the new object --deep copy
            cout << "Copy constructor of main class Animal has been called  " <<"\n";
            animalName = a.animalName;
            animalGender = a.animalGender;
            animalSound = a.animalSound;
            animalAge = a.animalAge;
        }

        Animal(Animal&& a) { //works with rvalue references and points to the already existing object in the memory; prevents more than 1 obj to poiny to the same memory location
            a.animalName = nullptr;
            a.animalGender = nullptr;
            a.animalSound = nullptr;
            a.animalAge = nullptr;
            cout<<"Move constructor of main class Animal has been called." <<"\n";
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
             cout << "Cow destroyed.Destructor of class Cow has been called" <<"\n";
        }


};

int main()
{
    Animal a("NormalAnimal","male","normalSound",1);
    Animal a2(a);  //copy constructor is called
    Cow milka( 100, "Milka", "female", "mooo", 2);

    cout<<milka.getName()<<"\n";
    milka.makeAnimalSound();

   cout<<"Calling the move constructor :";
   cout<<"\n";


   //lvalue = an object reference; rvalue = a value
    return 0; //destructors are called
}
*/
