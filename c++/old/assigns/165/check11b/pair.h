/*****************************************************
 * File: pair.h
 *
 * Purpose: Defines a Pair template class that can hold
 *   two items of arbitrary data types.
 ******************************************************/

#ifndef PAIR_H
#define PAIR_H

// TODO: Fill in this class
// Put all of your method bodies right in this file
template <class T1, class T2>
class Pair
{
private:
  T1 first;
  T2 second;
public:
  T1 getFirst()  { return first;  }
  T2 getSecond() { return second; }
  void  setFirst(T1 first)  { this->first = first;   }
  void setSecond(T2 second) { this->second = second; }
  void display();

};

template <class T1, class T2>
void Pair<T1, T2> :: display()
{
  std::cout << getFirst() << " - " << getSecond();// << endl;
}


#endif // PAIR_H
