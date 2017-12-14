// course.cpp

#include "course.h"
#include <string>
#include <iostream>
using namespace std;

Student Course::getStudent(int index) const
{
   // TODO: Fill this in
   return classList[index];
}

void Course::setStudent(int index, const Student & s)
{
   // TODO: Fill this in
   classList[index] = s;
   
}

void Course::displayList() const
{
   cout << "Class list for course: " << name << endl;

   for (int i = 0; i < size; i++)
   {
      classList[i].display();
   }
}

Course Course :: operator =(const Course & rhs)
{
   size = rhs.getSize();
   name = rhs.name;
   
   if (classList != rhs.classList)
   {
   delete [] classList;
   classList = new Student[size];
   }
   
   for (int i = 0; i < size; i++)
   {
      classList[i] = rhs.classList[i];
   }
}
