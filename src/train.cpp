// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr), current(nullptr) {}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};
  if (!first) {
    first = newCar;
    first->next = first;
    first->prev = first;
    current = first;
  } else {
    Car* tail = first->prev;
    tail->next = newCar;
    newCar->prev = tail;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  if (!first) {
    countOp = 0;
    return 0;
  }

  int length = 1;
  bool lightOffExists = !first->light;

  for (const Car* node = first->next; node != first; node = node->next) {
    if (!node->light) lightOffExists = true;
    ++length;
  }

  countOp = lightOffExists ? length * 2 : length * (length + 1);
  return length;
}
int Train::getOpCount() const { return countOp; }
