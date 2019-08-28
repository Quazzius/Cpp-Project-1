/*
Author: Jeff Flanegan
Class: CSC 161
Date: 2019-8-22
Project: Lesson One
Header file
*/

/*
Member functions:
    void next_number(double);
        Postcondition: The double value is given to the statistician object
        and object data members are updated to new values.

    void reset( );
        Postcondition: Object data members are reset to values of 0.

Constant member functions:
    int length( )const;
        Postcondition: The value of the amount of numbers entered the sequence is returned

    double sum()const;
        Postcondition: The sum of the numbers in the sequence is returned

    double mean()const;
        Postcondition: The average of the sequence of numbers is returned

    double minimum()const;
        Postcondition: The smallest number entered in the sequence is returned

    double maximum()const;
        Postcondition: The smallest number entered in the sequence is returned

Operator overload friends:
    friend statistician operator + (const statistician&, const statistician&);
        Postcondition: The two objects are combined as though they were a part of the same sequence,
        and as if the first object was followed by the second.
        A new object is created with the new values and is returned.

    friend statistician operator * (double, const statistician&);
        Postcondition: A new object is created with values equal to the original object,
        though multiplied by the given double, and is returned.

Class operator overload:
    bool operator == (const statistician&, const statistician&);
        Postcondition: The two objects are compared for complete equality.
        If length, sum, mean, minimum and maximum are equivalent, True is returned, otherwise False is returned.
*/
#ifndef STATISTICIAN_H //check for duplicate definition
#define STATISTICIAN_H

#include <iostream>


namespace main_savitch_2C
{
    class statistician
    {
    public:
        //Constructor
        statistician( );

        //Member functions
        void next_number(double);
        void reset( );

        //Constant member functions
        int length( )const;
        double sum()const;
        double mean()const;
        double minimum()const;
        double maximum()const;

        //Operator overload friends
        friend statistician operator + (const statistician&, const statistician&);
        friend statistician operator * (double, const statistician&);

    private:
        //Data members
        int tally = 0; // count of numbers in sequence
        double total = 0; // sum of sequence of numbers
        double avg = 0; // calculated mean of numbers in sequence
        double small = 0;  // smallest number entered
        double big = 0;  // largest number entered
    };
    //Class operator overload
    bool operator == (const statistician&, const statistician&);
}

#endif
