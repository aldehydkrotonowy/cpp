#include <iostream>
#include <cstring> //strlen
using namespace std;

class Nazwisko {
    char *nazwisko;
    public: Nazwisko(const char *n):nazwisko(strcpy(new char[strlen(n)+1], n))
    {
        cout<<"konstruktor Nazwisko: "<<nazwisko<<endl;
    }
    virtual ~Nazwisko()//musi byc wirtualny, w przeciwnym razie destruktor klasy Imie nie zostanie wywolany
    {
        cout<<"destruktor Nazwisko: "<<nazwisko<<endl;
        delete []nazwisko;
    }
};
class Pelne : public Nazwisko {
    char *imie;
    public: Pelne(const char *i, const char *n):Nazwisko(n),imie(strcpy(new char[strlen(i)+1], i))
    {
        cout<<"konstruktor Pelne imie, nazwisko: "<<imie<<endl;
    }
    ~Pelne()
    {
        cout<<"destruktor Pelne imie, nazwisko"<<endl;
        delete []imie;
    }
};
int main(void)
{
    Nazwisko *osoba = new Pelne("Jan", "Malinowski");
    delete osoba;
}
