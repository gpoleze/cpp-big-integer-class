//  Author:     Gabriel Poleze Ferreira #100280844
//  Purpose:    This library is used to handle with big integer as an array
//  Limitations:
//  Bugs:
//  References:

#ifndef BigInteger_h
#define BigInteger_h

#include <string>
#include <iostream>
#include <sstream>
#include "LinkedList.cpp"

using namespace std;

class BigInteger{
    
private:
    //Fields
    LinkedList<short int> digits;
    int size;
    bool positive;
    
    //Helper Funtion
    void toList(long);
    void toList(string);
    
    //List helper functions
    void addLast(const short int s);
    void addFirst(const short int s);
    
public:
    //Constructors
    BigInteger();
    BigInteger(long);
    BigInteger(char*);
    BigInteger(string) throw (invalid_argument);
    
    //Copy Constructor
    BigInteger(const BigInteger&);
    
    //Destructor
    //    ~BigInteger();
    
    //Arithmetics' Functions
    BigInteger plus(const BigInteger&) const;
    //    BigInteger minus(const BigInteger&) const;
    //    BigInteger times(const BigInteger&) const;
    //    BigInteger dividedBy(const BigInteger&) const;
    
    //Getters
    bool isPositive() const {return positive;}
    int getSize()const {return size;};
    
    //Information Functions
    string toString();
    bool isEmpty() const {return size==0;};
    
    //Iterators
    Iterator<short int> begin() const {return digits.begin(); }
    Iterator<short int> end()   const {return digits.end();   }
    Iterator<short int> rbegin()const {return digits.rbegin();}
    Iterator<short int> rend()  const {return digits.rend();  }
    
    //    Operators Overload    //
    //Assignment Operator
    const BigInteger& operator=(const BigInteger&);
    //  Augmented operators
    BigInteger operator+=(const BigInteger&);
    //    BigInteger operator-=(const BigInteger&);
    //    BigInteger operator*=(const BigInteger&);
    //    BigInteger operator/=(const BigInteger&);
    //    BigInteger operator%=(const BigInteger&);
    
    //  Unary Operators
    BigInteger operator+();
    BigInteger operator-();
    
    // Casting operators - dont use them or it will give a error when trying to add usign BigInteger + int, the compiler doent know wich casting to do, from BigInteger to int or the int to BigInteger
    //    operator long() throw (bad_cast);
    //    operator int() throw (bad_cast);
    
    //Friend Functions - ostream
    friend ostream& operator<<(ostream& out, const BigInteger& bigNumber);
};

// Non-member Functions - Overloaded Operators - Unary
BigInteger operator+(const BigInteger&, const BigInteger&);
BigInteger operator*(const BigInteger&, const BigInteger&);

// Non-member Functions - Overloaded Operators - Comparison
bool operator< (const BigInteger&, const BigInteger&);
bool operator<=(const BigInteger&, const BigInteger&);
bool operator> (const BigInteger&, const BigInteger&);
bool operator>=(const BigInteger&, const BigInteger&);
bool operator==(const BigInteger&, const BigInteger&);
bool operator!=(const BigInteger&, const BigInteger&);

#endif /* BigInteger_h */
