/* 
 * File:   recursion.cxx
 * Author: Jeff Flanegan
 * Class: CSC 161 C++
 * Assignment: Homework 8
 * Created on October 13, 2019, 2:57 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>

using namespace std;


int fun(string str, int i) 
{ 
    
    //handle negative number once
    if (i > 0){
        cout << '-';
    }
    
    //handle non-integer char
    if((str[0]-'0') > 9 || (str[0]-'0') < 0){
        str[0] = '0';
    }
    
    //return base case
    if (str.length() == 1){
        return (str[0] - '0'); 
    }
    
    //advance to next character by leaving
    //str[0] out of the next recursion
    int next = fun(str.substr(1), 0); 
  
    //first character in string
    int first = str[0] - '0'; 
  
    //multiply the fist digit by 10 ^recourse giving it its full integer size,
    //and add to it the digits that were staged in next for the correct number.
    first = first * pow(10, str.length() - 1) + next;

    return int(first); 
} 

/* This program converts a character string of digits to an integer.
 * It does not modify the original string and only accepts integer
 * characters, or '-' if it is a negative number. If any non integer
 * character is entered, a warning will show and the characters 
 * will be changed to 0's. 
 */
int main(int argc, char** argv) {

    int i = 0; //negative integer switch
    string strNum = "";
    cout << "Enter an integer less than 2147483648, or greater than -2147483649\n"
            "non-integer characters will be changed to 0's" << endl;
    cin >> strNum;
    
    string s = strNum;
    
    //handles negative integer
    if(s[0] == '-'){
        s = s.substr(1);
        i++;
    }
    //handles non-integer character warning
    for (char c: s){
        if ((c - '0') > 9 || (c - '0') < 0){
            cout << "non-integer character found: " << c <<endl;
        }
    }
    //output string to integer conversion
    cout << fun(s, i) << endl;
    
       
    return 0;
}
