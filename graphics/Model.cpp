#include"Model.h"

Model::Model(): polinomVector() {
    bufferPolinom = Polinom();
}

void Model::addMonomToBufferPolinom(Monom m) {
    bufferPolinom += m;
}

void Model::loadBufferPolinom() {
    if (bufferPolinom.getSize() == 0) {
        throw EmptyPolinom();
    }
    polinomVector.push_back(bufferPolinom);
}

void Model::clrBufferPolinom() {
    bufferPolinom.clear();
}

void Model::addPolinomToVector(Polinom p) {
  polinomVector.push_back(p);
}

void Model::addPolinom(int numP1, int numP2) {
  int ind1 = numP1 - 1;
  int ind2 = numP2 - 1;

  if ((0 <= ind1) && (0 <= ind2) && (ind1 < polinomVector.size()) && (ind2 < polinomVector.size())) {
    Polinom res(polinomVector[ind1]);
    res += polinomVector[ind2];
    polinomVector.push_back(res);
  }
  else {
    throw PoliNotInVector();
  }
}

void Model::subPolinom(int numP1, int numP2) {
  int ind1 = numP1 - 1;
  int ind2 = numP2 - 1;

  if ((0 <= ind1) && (0 <= ind2) && (ind1 < polinomVector.size()) && (ind2 < polinomVector.size())) {
    Polinom res(polinomVector[ind1]);
    res -= polinomVector[ind2];
    polinomVector.push_back(res);
  }
  else {
    throw PoliNotInVector();
  }
}

void Model::mulPolinom(int numP1, int numP2) {
  int ind1 = numP1 - 1;
  int ind2 = numP2 - 1;

  if ((0 <= ind1) && (0 <= ind2) && (ind1 < polinomVector.size()) && (ind2 < polinomVector.size())) {
    Polinom res(polinomVector[ind1]);
    res *= polinomVector[ind2];
    polinomVector.push_back(res);
  }
  else {
    throw PoliNotInVector();
  }
}

void Model::mulPolinom(double cnst, int numP1) {
  int ind1 = numP1 - 1;

  if ((0 <= ind1) && (ind1 < polinomVector.size())) {
    Polinom res(polinomVector[ind1]);
    res *= cnst;
    polinomVector.push_back(res);
  }
}
