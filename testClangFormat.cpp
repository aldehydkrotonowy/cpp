#include <iostream>
#include <string>

class Person {
protected:
  Person *nextPerson;
  int (*fun)(int);
  double (*boo[3])(double);

public:
  void init();
  void clean();
  void addPersonToEnd();
};

void Person::init() { nextPerson = NULL; };
void Person::clean() {
  if (nextPerson != NULL) {
    nextPerson->clean();
    delete nextPerson;
    nextPerson = NULL;
  }
};
void Person::addPersonToEnd() {
  Person *lastPerson = this;
  while (lastPerson->nextPerson != NULL)
    lastPerson = lastPerson->nextPerson;
}