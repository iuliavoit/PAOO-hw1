#include <iostream>
using namespace std;

class Animal
{

public:
    int *age, *weight;
    string *name;
    Animal();
    Animal(int a, int w, string n); // constructor
    Animal(const Animal &a);        // copy constructor
    Animal(Animal &&a);             // move constructor
    ~Animal();                      // destructor
    int getAnimalAge() { return *age; }
    int getAnimalAWeight() { return *weight; }

    // Animal copy assignment operator
    Animal &operator=(const Animal &a)
    {
        // handling assignment to self
        if (this == &a)
        {
            cout << "Assigned object to itself\n";
            return *this;
        }
        age = a.age;
        weight = a.weight;
        name = a.name;
        cout << "Inside of animal copy assignment operator\n";
        return *this;
    }
};
// default constructor
Animal::Animal()
{
}

// Normal constructor
Animal::Animal(int a, int w, string n)
{
    cout << "Normal constructor of class Animal called.\n";
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
    cout << "Destructor of class Animal called\n";
    if (age != nullptr)
        delete age;
    if (weight != nullptr)
        delete weight;
    if (name != nullptr)
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
    Cow(){};
    Cow(int lit, int a, int w, string n) : Animal(a, w, n)
    {
        cout << "Constructor of class Cow has been called"
             << "\n";
        milkLiters = new int;
        *milkLiters = lit;
    }

    // Animal copy assignment operator
    Cow &operator=(const Cow &c)
    {
        // handling assignment to self
        if (this == &c)
        {
            cout << "Assigned object to itself\n";
            return *this;
        }
        milkLiters = c.milkLiters;
        Animal::operator=(c); // assigning  base class parts to the new obj
        cout << "Inside of cow copy assignment operator\n";
        return *this;
    }

    ~Cow()
    {
        if (milkLiters != nullptr)
            delete milkLiters;
        cout << "Cow destroyed.Destructor of class Cow has been called"
             << "\n";
    }
};

class Pig : public Animal
{

public:
    int *daysUntilChristmas;
    Pig(int d, int a, int w, string n) : Animal(a, w, n)
    {
        daysUntilChristmas = new int;
        *daysUntilChristmas = d;
        cout << "Constructor of class Pig has been called"
             << "\n";
    }

    Pig(const Pig &p) = delete;

    ~Pig()
    {
        if (daysUntilChristmas != nullptr)
            delete daysUntilChristmas;
        cout << "Pig destroyed.Destructor of class Pig has been called"
             << "\n";
    }

    int *getDaysUntilChristmas(Pig p)
    {
        return p.daysUntilChristmas;
    }
};

int *getMilkLiters(Cow c)
{
    return c.milkLiters;
}

int main()
{
    Animal a(1, 100, "Animal1"); // normal constr
    a = a;                       // assigning object to itself
    Animal b;

    b = a; // using the copy assignment operator

    cout << "First animal age: " << a.getAnimalAge();
    cout << "\n Second animal age: " << b.getAnimalAge();
    cout << "\n";

    // Copy all parts of an object.
    Cow cow(10, 2, 230, "Milka");
    Cow cow2;
    cow2 = cow;
    cout << cow2.getAnimalAge(); // should work bc of line 119
    cout<<"\n";
    return 0;
}
