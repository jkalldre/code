#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>

// forward declaration for ContainerIterator
template <class T>
class VectorIterator;
template <class T>
class VectorConstIterator;
/************************************************
 * Vector
 * A class that holds stuff
 ***********************************************/
template <class T>
class Vector
{
public:
   // default constructor : empty and kinda useless
   Vector() : numItems(0), capacity(0), data(0x00000000) {}

   // copy constructor : copy it
   Vector(const Vector<T> & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Vector(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Vector()        { if (capacity) delete [] data; }
   
   // is the container currently empty
   bool empty() const  { return numItems == 0;         }

   // remove all the items from the container
   void clear()        { numItems = 0;                 }

   // how many items are currently in the container?
   int size() const    { return numItems;              }
   
   int getCapacity() const { return capacity;             }
 
   // add an item to the container
   void push_back(const T & t) throw (const char *);
   
   // '[]' overload 
   T & operator [](const int & i);
   
   // '()' overload
   T & operator ()(const int & i);
   
   // '=' overload
   void operator =(const Vector<T> & rhs);
   
   // return an iterator to the beginning of the list
   VectorIterator <T> begin() { return VectorIterator<T>(data); }

   // return an iterator to the end of the list
   VectorIterator <T> end() { return VectorIterator<T>(data + numItems);}
   
   // return an iterator to the beginning of the list
   VectorConstIterator <T> cbegin() const { return VectorConstIterator<T>(data); }

   // return an iterator to the end of the list
   VectorConstIterator <T> cend() const { return VectorConstIterator<T>(data + numItems);}
   
private:
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Container?
   int capacity;      // how many items can I put on the Container before full?
};

/**************************************************
 * Vector ITERATOR
 * An iterator through vector
 *************************************************/
template <class T>
class VectorIterator
{
  public:
   // default constructor
  VectorIterator() : p(0x00000000) {}

   // initialize to direct p to some item
  VectorIterator(T * p) : p(p) {}

   // copy constructor
   VectorIterator(const VectorIterator & rhs) { *this = rhs; }

   // assignment operator
   VectorIterator & operator = (const VectorIterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   // not equals operator
   bool operator != (const VectorIterator & rhs) const
   {
      return rhs.p != this->p;
   }

   // dereference operator
   T & operator * () const
   {
      return *p;
   }

   // prefix increment
   VectorIterator <T> & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   VectorIterator <T> operator++(int postfix)
   {
      VectorIterator tmp(*this);
      p++;
      return tmp;
   }
   
    // prefix decrement
   VectorIterator <T> & operator -- ()
   {
      p--;
      return *this;
   }

   // postfix decrement
   VectorIterator <T> operator--(int postfix)
   {
      VectorIterator tmp(*this);
      p--;
      return tmp;
   }
  private:
   T * p;
};

/**************************************************
 * Const Vector ITERATOR
 * A const iterator through vector
 *************************************************/
template <class T>
class VectorConstIterator
{
  public:
   // default constructor
  VectorConstIterator() : p(0x00000000) {}

   // initialize to direct p to some item
  VectorConstIterator(T * p) : p(p) {}

   // copy constructor
   VectorConstIterator(const VectorConstIterator & rhs) { *this = rhs; }

   // assignment operator
   VectorConstIterator & operator = (const VectorConstIterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   // not equals operator
   bool operator != (const VectorConstIterator & rhs) const
   {
      return rhs.p != this->p;
   } 

   // dereference operator
   T & operator * () const
   {
      return *p;
   }

   // prefix increment
   VectorConstIterator <T> & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   VectorConstIterator <T> operator++(int postfix)
   {
      VectorConstIterator<T> tmp(*this);
      p++;
      return tmp;
   }
   // prefix decrement
   VectorConstIterator <T> & operator -- ()
   {
      p--;
      return *this;
   }

   // postfix decrement
   VectorConstIterator <T> operator--(int postfix)
   {
      VectorConstIterator<T> tmp(*this);
      p--;
      return tmp;
   }
   
  private:
   T * p;
};

/*******************************************
 * Vector :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Vector <T> :: Vector(const Vector <T> & rhs) throw (const char *)
{
   assert(rhs.capacity >= 0);
      
   // do nothing if there is nothing to do
   if (rhs.capacity == 0)
   {
      capacity = numItems = 0;
      data = 0x00000000;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[rhs.capacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }
   
   // copy over the capacity and size
   assert(rhs.numItems >= 0 && rhs.numItems <= rhs.capacity);
   capacity = rhs.capacity;
   numItems = rhs.numItems;

   // copy the items over one at a time using the assignment operator
   for (int i = 0; i < numItems; i++)
      data[i] = rhs.data[i];

   // the rest needs to be filled with the default value for T
   for (int i = numItems; i < capacity; i++)
      data[i] = T();
}

/**********************************************
 * VECTOR : NON-DEFAULT CONSTRUCTOR
 * Preallocate the vector to "capacity"
 **********************************************/
template <class T>
Vector <T> :: Vector(int capacity) throw (const char *)
{
   assert(capacity >= 0);
   
   // do nothing if there is nothing to do
   if (capacity == 0)
   {
      this->capacity = this->numItems = 0;
      this->data = 0x00000000;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[capacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }

      
   // copy over the stuff
   this->capacity = capacity;
   this->numItems = 0;

   // initialize the container by calling the default constructor
   for (int i = 0; i < capacity; i++)
      data[i] = T();
}

/***************************************************
 * VECTOR :: PUSH_BACK
 * Insert an item on the end of the vector
 **************************************************/
template <class T>
void Vector <T> :: push_back(const T & t) throw (const char *)
{
   // do we have space?
   if (capacity == 0 || capacity == numItems)
   {
      if (capacity == 0)
         capacity = 1;
      T * tmp = new T[capacity *= 2];
      for (int i =0; i < numItems; i++)
         tmp[i] = data[i];
      delete [] data;
      data = tmp;
      
      //throw "ERROR: Insufficient space";
   }
      // add an item to the end 
      data[numItems++] = t;
      
}

template <class T>
T & Vector<T>::operator [](const int & i)
{
   return data[i];
}

template <class T>
T & Vector<T>::operator ()(const int & i)
{
   return data[i];
}

template <class T>
void Vector<T>::operator =(const Vector<T> & rhs)
{
   capacity = rhs.capacity;
   numItems = rhs.numItems;
   data = new T[capacity];
   
   for (int i = 0; i < numItems; i++)
      data[i] = rhs.data[i];
}

#endif // VECTOR_H

