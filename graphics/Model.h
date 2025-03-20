#pragma once

#include<iostream>
#include<vector>
#include"../mp2-lab5-polinom/Polinom.h"

class Model {
  std::vector<Polinom> polinomVector;

public:
  Model();

  void addPolinomToVector(Polinom p);

  void addPolinom(int indP1, int indP2);
  void subPolinom(int indP1, int indP2);
  void mulPolinom(int indP1, int indP2);
  void mulPolinom(double cnst, int indP2);
};
