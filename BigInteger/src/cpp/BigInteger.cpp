//  Author:     Gabriel Poleze Ferreira #100280844
//  Purpose:    This library is used to handle with big integer as strings
//  Limitations:
//  Bugs:
//  References:

#include "BigInteger.h"

//Helper Funtion
void BigInteger::toList(long num){
    long quotient;
    long dividend = num;
    short int reminder;
    
    
    do{
        reminder = dividend % 10;
        quotient = dividend / 10;
        dividend = quotient;
        
        digits.addFirst(reminder);
        
    }while(quotient >= 10);
    
    if (quotient > 0)
        digits.addFirst(static_cast<short int>(quotient));
};

void BigInteger::toList(string s){
    int strLength = (int)s.length();
    
    if (!strLength)
        throw invalid_argument("The input should not be empty");
    
    int zero = int('0');
    size = 0;
    
    positive = true;
    
    if (strLength == 1){
        char c = s[0];
        if (c < '0' || c >'9') throw invalid_argument("The string should contains only numbers");
        digits.addFirst((short int)(c - zero));
        size++;
        return;
    }
    
    if(strLength == 2 && s[0] == '-' && s[1] == '0'){
        size++;
        positive = true;
        digits.addLast(0);
        return;
    }
    
    if (s[0] == '-'){
        positive = false;
    }
    
    int begginig = (positive)? 0 : 1;
    
    for (int i = begginig; i < strLength; i++) {
        char c = s[i];
        
        if (c < '0' || c >'9')
            throw invalid_argument("The string should contains only numbers");
        
        if (size == 0 && c == '0')
            continue;
        
        digits.addLast((short int)(c - zero));
        size++;
    }

}

//List helper functions
void BigInteger::addLast(const short int s){
//    if (size == 1 && digits[0] == 0){
//        digits[0] = s;
//        return;
//    }
    
    digits.addLast(s);
    size = digits.getSize();
}

void BigInteger::addFirst(const short int s){
//    if (size == 1 && digits[0] == 0){
//        digits[0] = s;
//        return;
//    }
    
    digits.addFirst(s);
    size = digits.getSize();
}

//Constructors
BigInteger::BigInteger(){
//    digits.addLast(0);
    positive = true;
    size = 0;
}

BigInteger::BigInteger(long num){
    if (num >= 0)
        positive = true;
    else{
        positive = false;
        num *= -1;
    }
    
    if (num >=0 && num < 10)
        digits.addLast(num);
    else
        toList(num);
    
    size = digits.getSize();
};

BigInteger::BigInteger(char* c){
    toList(string(c));
}

BigInteger::BigInteger(string s) throw (invalid_argument){
    toList(s);
}

//Copy Constructor
BigInteger::BigInteger(const BigInteger& bigNumber){
    size = bigNumber.size;
    positive = bigNumber.isPositive();
    
    LinkedList<short int> bigNumberDigits = bigNumber.digits;
    
    for (Iterator<short int> it = bigNumberDigits.begin(); it != bigNumberDigits.end(); it++) {
        digits.addLast(it.content());
    }
}

//Destructor
//    ~BigInteger();

//Arithmetics' Functions
BigInteger BigInteger::plus(const BigInteger& other) const {
    
    if (this->positive ^ other.positive)
        return minus(other);
    
    BigInteger temp;
    
    typedef Iterator<short int> iterator;
    
    iterator itBig(nullptr);
    iterator itSmall(nullptr);
    
    if (size > other.size){
        itBig = rbegin();
        itSmall = other.rbegin();
    } else{
        itBig = other.rbegin();
        itSmall = rbegin();
    }
    
    
    short int carry = 0;
    
    while(itSmall != NULL){
        short int i = carry + itSmall.content() + itBig.content();
        carry = i / 10;
        temp.addFirst(i % 10);
        itSmall--;
        itBig--;
    }
    
    while (itBig != NULL) {
        short int i = carry + itBig.content();
        carry = i / 10;
        temp.addFirst(i % 10);
        itBig--;
    }
    
    if (carry)
        temp.addFirst(carry);
    
    return temp;
}

BigInteger BigInteger::minus(const BigInteger& other) const {
    return *this;
}

//Information Functions
string BigInteger::toString(){
    if (isEmpty())
        return "";
    
    string out;
    
    if (!isPositive())
        out.append("-");
    
//    Iterator<short int> end = digits.end();
//    for (Iterator<short int> it = digits.begin(); it; it++)
    for (Iterator<short int> it = digits.begin(); it != digits.end(); it++)
        out += it.content();
    
    return out;
}

int BigInteger::equals(const BigInteger& other) const{
    bool sign1 = isPositive();
    bool sign2 = other.isPositive();
    
    //Compare positive with a negative number
    if(sign1 ^ sign2){
        if (sign1 && !sign2)
            return 1;
        else
            return -1;
    }
    
    //signs are the same
    int size1 = getSize();
    int size2 = other.getSize();
    
    if (size1 ^ size2){
        if (size1 > size2)
            return (sign1) ? 1 : -1;
        else
            return (!sign1) ? 1 : -1;
    }
    
    //signs and size are the same
    typedef Iterator<short int> iterator;
    for(iterator it1 = begin(), it2 = other.begin(); it1 != end(); it1++, it2++){
        if (it1.content() == it2.content())
            continue;
        
        if (it1.content() > it2.content())
            return (sign1) ? 1 : -1;
        else
            return (!sign1) ? 1 : -1;
    }

    return 0;
}

//    Operators Overload    //
//Assignment Operator
const BigInteger& BigInteger::operator=(const BigInteger& other){
    this->positive = other.positive;
    this->size = other.size;
    this->digits = other.digits;
    return *this;
}

//  Augmented operators
BigInteger BigInteger::operator+=(const BigInteger& other){
    *this = plus(other);
    return *this;
}

//  Unary Operators
BigInteger BigInteger::operator+(){
    return *this;
}

BigInteger BigInteger::operator-(){
    if (size > 0)
        positive = (isPositive()) ? false : true;
    return *this;
}

/* Casting operators
BigInteger::operator int() throw(bad_cast){
    if (size > 9){
        throw bad_cast();
    }
    stringstream ss;
    
    ss << *this;
    
    int i = 0;
    ss >> i;
    
    return i;
}

BigInteger::operator long() throw(bad_cast){
    if (size > 19){
        throw bad_cast();
    }
    stringstream ss;
    
    ss << *this;
    
    long i = 0;
    ss >> i;
    
    return i;
}*/

//Friend Functions - ostream
ostream& operator<<(ostream& out, const BigInteger& bigNumber){
    if (bigNumber.isEmpty())
        out << "";
    else {
        if (!bigNumber.isPositive())
            out << '-';
        
        Iterator<short int> end = bigNumber.digits.end();
        
        for (Iterator<short int> it = bigNumber.digits.begin(); it != end; it++)
            out << it.content();
        
    }
    return out;
}

// Non-member Functions - Overloaded Operators - Unary
BigInteger operator+(const BigInteger& bigNumber1, const BigInteger& bigNumber2){
    return bigNumber1.plus(bigNumber2);
}


// Non-member Functions - Overloaded Operators - Comparison
bool operator>(const BigInteger& bigNumber1, const BigInteger& bigNumber2){
    if(bigNumber1.isEmpty() || bigNumber2.isEmpty())
        throw invalid_argument("The input should not be empty");
    return (bigNumber1.equals(bigNumber2) == 1) ? true : false;
}

bool operator<(const BigInteger& bigNumber1, const BigInteger& bigNumber2){
    if(bigNumber1.isEmpty() || bigNumber2.isEmpty())
    	throw invalid_argument("The input should not be empty");
	return (bigNumber1.equals(bigNumber2) == -1) ? true : false;
}

bool operator==(const BigInteger& bigNumber1, const BigInteger& bigNumber2){
    if(bigNumber1.isEmpty() || bigNumber2.isEmpty())
        throw invalid_argument("The input should not be empty");
    return (bigNumber1.equals(bigNumber2) == 0) ? true : false;}

bool operator!=(const BigInteger& bigNumber1, const BigInteger& bigNumber2){
    if(bigNumber1.isEmpty() || bigNumber2.isEmpty())
        throw invalid_argument("The input should not be empty");
    return (bigNumber1.equals(bigNumber2) != 0) ? true : false;
}

bool operator>=(const BigInteger& bigNumber1, const BigInteger& bigNumber2){
    if(bigNumber1.isEmpty() || bigNumber2.isEmpty())
        throw invalid_argument("The input should not be empty");
    return (bigNumber1.equals(bigNumber2) >= 0) ? true : false;
}

bool operator<=(const BigInteger& bigNumber1, const BigInteger& bigNumber2){
    if(bigNumber1.isEmpty() || bigNumber2.isEmpty())
        throw invalid_argument("The input should not be empty");
    return (bigNumber1.equals(bigNumber2) <= 0) ? true : false;
}








//string BigInteger::multipliedBy(int n){
//
//    for (int i = 0; i < n; i++) {
//        plus(toAdd);
//    }
//
//    return "";
//}
