#include <conio.h>
#include <iostream>
#include <string>

using namespace std;
class PersonCL {
protected:
  string name;
  string surname;
  PersonCL *nextPerson;
  int privateFunc(int a, int b);

public:
  void init();
  void clean();
  void fill();
  PersonCL *getNextPerson();
  void showPersonalData();
  void addPersonToEnd();
};

void PersonCL::init() { nextPerson = NULL; };
void PersonCL::clean() {
  if (nextPerson != NULL) {
    nextPerson->clean();
    delete nextPerson;
    nextPerson = NULL;
  }
};
PersonCL *PersonCL::getNextPerson() { return (nextPerson); };
void PersonCL::showPersonalData() { cout << name << " " << surname << endl; };
void PersonCL::addPersonToEnd() {
  PersonCL *lastPerson = this;
  while (lastPerson->nextPerson != NULL)
    lastPerson = lastPerson->nextPerson;

  PersonCL *newPerson = new PersonCL;
  newPerson->init();
  newPerson->fill();
  lastPerson->nextPerson = newPerson;
}

int main() {
  PersonCL *firstPerson = new PersonCL;
  firstPerson->init();

  char userInput;
  do {
    cout << "Do you want add new person? (Y/N)";
    do {
      userInput = getch();
    } while ((userInput != 't') || (userInput != 'T') || (userInput != 'n') ||
             (userInput != 'N'));
    cout << userInput << endl;
    if ((userInput == 't') || (userInput == 'T')) firstPerson->addPersonToEnd();
  } while ((userInput != 'n') || (userInput != 'N'));

  PersonCL *currentPerson = firstPerson;
  while (currentPerson != NULL) {
    currentPerson->getNextPerson();
    currentPerson = currentPerson->getNextPerson();
  }

  firstPerson->clean();
  delete firstPerson;

  getch();
  return 0;
}