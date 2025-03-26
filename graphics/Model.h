#pragma once

#include<iostream>
#include<vector>

#include"Exceptions.h"
#include"../mp2-lab5-polinom/Polinom.h"

class Model {
  std::vector<Polinom> polinomVector;
  Polinom bufferPolinom;

public:
  Model();

  void addMonomToBufferPolinom(Monom m);
  void loadBufferPolinom();
  void clrBufferPolinom();

  void addPolinomToVector(Polinom p);

  void addPolinom(int numP1, int numP2);
  void subPolinom(int numP1, int numP2);
  void mulPolinom(int numP1, int numP2);
  void mulPolinom(double cnst, int numP2);

  const std::vector<Polinom>& getPolinomVectorPtr();
};
