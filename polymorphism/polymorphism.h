#ifndef NG_POLYMORPHISM_1_H
#define NG_POLYMORPHISM_1_H

class Polygon {
protected:
  int width, height;

public:
  void set_values(int a, int b) {
    width = a;
    height = b;
  }
};

class Rectangle : public Polygon {
public:
  int getArea() { return width * height; }
};

class Triangle : public Polygon {
public:
  int getArea() { return width * height / 2; }
};

#endif