/*
Author: Jeff Flanegan
Class: CSC 161
Date: 2019-8-22
Project: Lesson One
Implementation file
*/
#include "statistician.h"
#include <iostream>
using namespace std;

namespace main_savitch_2C
{
    statistician::statistician(){}

    void statistician::next_number(double i){

        ++tally; //add one to length
        total += i; //add new number to sum
        avg = total / tally; //re-assess the median of entered numbers

        //determine value in realtion to minimum and maximum
        //and set value accordingly
        if (tally == 1){small = i; big = i;}
        else{
            if (i < small){small = i;}
            if (i > big){big = i;}
        }
    }

    void statistician::reset( ){
        tally = 0; total = 0; small = 0; big = 0;
    }
    int statistician::length() const{
        return tally;
    }
    double statistician::sum() const{
        return total;
    }
    double statistician::mean() const{
        return avg;
    }
    double statistician::minimum() const{
        return small;
    }
    double statistician::maximum() const{
        return big;
    }

    statistician operator + (const statistician& s1, const statistician& s2){
        //create new statistician object
        statistician s3;
        //determine if there is an empty sequence
        //if so, return the opponent
        if (s1.length() == 0) { return s2; }
        else if (s2.length() == 0) { return s1; }
        //add lenths and sums
        s3.tally = s1.length() + s2.length();
        s3.total = s1.sum() + s2.sum();
        //find averege of the two objects
        s3.avg = (s1.sum() + s2.sum()) / (s1.length() + s2.length());
        //find smallest and largest numbers between the objects
        if (s1.minimum() < s2.minimum()){
            s3.small = s1.minimum();
        }
        else{ s3.small = s2.minimum(); }
        if (s1.maximum() > s2.maximum()){
            s3.big = s1.maximum();
        }
        else{ s3.big = s2.maximum(); }
        return s3;
    }
    statistician operator * (double j, const statistician& s){
        //empty sequence returned without modification
        if (s.length() == 0) { return s; }
        //create object and multiply values
        statistician s4;
        s4.tally = s.length(); //sequence count remains consistent
        s4.total = j * s.sum();
        s4.small = j * s.minimum();
        s4.big = j * s.maximum();
        //swap min/max if negative  multiplier is entered
        if (s4.small > s4.big){
            s4.big = j * s.minimum();
            s4.small = j * s.maximum();
        }
        s4.avg = s4.total / s4.tally;
        return s4;
    }
    bool operator == (const statistician& s1, const statistician& s2){

        return
            (s1.length() == s2.length())&&
            (s1.sum() == s2.sum())&&
            (s1.minimum() == s2.minimum())&&
            (s1.maximum() == s2.maximum());
    }

}
