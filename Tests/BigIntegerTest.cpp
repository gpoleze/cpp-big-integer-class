//
//  main.cpp
//  big_integer_class
//
//  Created by Gabriel P Ferreira on 2017-05-28.
//  Copyright © 2017 Gabriel P Ferreira. All rights reserved.
//

#include <vector>
#include <iostream>
#include "BigInteger.h"

using namespace std;

//BigInteger fact(int n, int& runs) {
//    runs++;
//
//    if (n == 1)
//        return 1;
//
//    return n * fact(n - 1, runs);
//}



int main() {
    cout << "no-args contructor \n";
    BigInteger number1;
    cout << "number1 = " << number1.toString() << "\n\n";
    number1 = 123456789;// The problem at the augmented operator += lies here: the assignemt operator was not overloaded, causing an error.
    
    long startNumber = 0x1; //biggest long in hexadecimal 0x7FFFFFFFFFFFFFFF
    cout << "integer constructor parameter = " << startNumber << endl;
    //    cout << "sizeof(unsigned long) = " << sizeof(unsigned long) << endl;
    BigInteger number2(startNumber);
    cout << "number2 = " << number2 << "\n";
    cout << "number2(" << number2.getSize() << " digits) = " << number2 << "\n";
    
    
    string startString("1");
    //    cout << "string constructor parameter = " << startString << endl;
    BigInteger number3(startString);
    cout << "number3(" << number3.getSize() << " digits) = " << number3 << "\n";
    
    BigInteger number4(number3);
    cout << "number4(" << number4.getSize() << " digits) = " << number4 << "\n";
    
//    long i = (number2);
//    cout << "i = " << i << "\n\n";
    
    
    //Comparisons - Greater than
    cout << "\nComparisons - Greater than\n";
    cout << "( " << number1 << " > " << number2 << " ) = " << ((number1 > number2)?"true":"false") << "\n";
    cout << "( " << number2 << " > " << number2 << " ) = " << ((number2 > number2)?"true":"false") << "\n";
    cout << "( " << number3 << " > " << number2 << " ) = " << ((number3 > number2)?"true":"false") << "\n";
    
    cout << "\nComparisons - Smaller than\n";
    cout << "( " << number1 << " < " << number2 << " ) = " << ((number1 < number2)?"true":"false") << "\n";
    cout << "( " << number2 << " < " << number2 << " ) = " << ((number2 < number2)?"true":"false") << "\n";
    cout << "( " << number3 << " < " << number2 << " ) = " << ((number3 < number2)?"true":"false") << "\n";
    
    cout << "\nComparisons - Equal to than\n";
    cout << "( " << number1 << " == " << number2 << " ) = " << ((number1 == number2)?"true":"false") << "\n";
    cout << "( " << number2 << " == " << number2 << " ) = " << ((number2 == number2)?"true":"false") << "\n";
    cout << "( " << number3 << " == " << number2 << " ) = " << ((number3 == number2)?"true":"false") << "\n";
    
    cout << "\nComparisons - not Equal to than\n";
    cout << "( " << number1 << " != " << number2 << " ) = " << ((number1 != number2)?"true":"false") << "\n";
    cout << "( " << number2 << " != " << number2 << " ) = " << ((number2 != number2)?"true":"false") << "\n";
    cout << "( " << number3 << " != " << number2 << " ) = " << ((number3 != number2)?"true":"false") << "\n";
    
    cout << "\nComparisons - Greater than or equal to\n";
    cout << "( " << number1 << " >= " << number2 << " ) = " << ((number1 >= number2)?"true":"false") << "\n";
    cout << "( " << number2 << " >= " << number2 << " ) = " << ((number2 >= number2)?"true":"false") << "\n";
    cout << "( " << number3 << " >= " << number2 << " ) = " << ((number3 >= number2)?"true":"false") << "\n";
    
    cout << "\nComparisons - Smaller than or equal to\n";
    cout << "( " << number1 << " <= " << number2 << " ) = " << ((number1 <= number2)?"true":"false") << "\n";
    cout << "( " << number2 << " <= " << number2 << " ) = " << ((number2 <= number2)?"true":"false") << "\n";
    cout << "( " << number3 << " <= " << number2 << " ) = " << ((number3 <= number2)?"true":"false") << "\n";
    
    //Adition
    cout << "\nAddition\n";
    cout << "number2 = " << number2 << "  number3 = " << number3 << "\n";
//    cout << "number2.plus(number3) = " << number2.plus(number3) << "\n";
    cout << "number2 + number3 = " << number2 + number3 << "\n";
    cout << "number2 + 98 = " << number2 + 99 << "\n";
    cout << "199 + number2 = " << 199 + number2 << "\n";
    
    //Augmented assignment operators
    cout << "\nAugmented assignment operators - +=\n";
//    number2 += 100;
    cout << "number2(before assignment) = " << number2 << "\n";
    number2 += 100;
    cout << "number2 = " << number2 << "\n";
    
//    vector<int> n = {0,1,2,3,4,5,6,7,8,9};
//
//    for(int i: n){
//        cout << i << ", ";
//    }
    return 0;
}


