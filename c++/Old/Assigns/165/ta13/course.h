// course.h

#ifndef COURSE_H
#define COURSE_H

#include "student.h"
#include <string>
#include <iostream>
using namespace std;

class Course
{
private:
   string name;
   int size;
   Student* classList;

public:
   Course(int size)
   {
      // Fill this in!
      this->size = size;
      classList = new Student[size];   
   }
   Course(const Course & rhs)
   {
      name = rhs.name;
      size = rhs.getSize();
      classList = new Student[size];
      for (int i = 0; i < size; i++)
      {
        // setStudent(i, rhs);
         classList[i] = rhs.classList[i];
      }
   }
   
   ~Course()
   {
      delete [] classList;
      cout << "Cleaning up Course: " << name << endl;
   }
   Course operator =(const Course & rhs);
   string getName() const { return name; }
   void setName(string name) { this->name = name; }
   
   int getSize() const { return size; }
   void setSize(int size) { this->size = size; }

   Student getStudent(int index) const;
   void setStudent(int index, const Student &);

   void displayList() const;

};

#endif
