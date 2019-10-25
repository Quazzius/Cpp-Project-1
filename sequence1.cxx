/*
 *Jeff Flanegan
 * CSC 161 C++
 * Homework 2
 * 2019-8-25
 */
/*
 * FILE:sequence1.cxx
 * CLASS IMPLEMENTED: sequence1.h
 * INVARIANT for the sequence1 class:
 * 1. The number of items in the array is the member variable used.
 * 2. The current cursor position on the array is the member variable current_index.
 * 3. If the current cursor position is located at an index where a value
 *      has not been stored, this is considered to not have an item. we do not care about
 *      the part of the sequence which holds no items. 
 * 
 */
#include "sequence1.h"
using namespace std;

namespace main_savitch_3
{   
    const sequence::size_type sequence::CAPACITY;
    
    //initialize object
    sequence::sequence(){
        used = 0;
        current_index = 0;
    }
    //return current index to index 0
    void sequence::start( ){
        current_index = 0;
    }
    //move current index to the right if the current index holds a value
    void sequence::advance( ){
        if (is_item()){
            current_index++;
        }
    }
    //insert new value to the left of the current value and shift data right
    //if no value found for current_index, value is inserted at the beginning of the sequence
    void sequence::insert(const value_type& entry){
        if (size() < CAPACITY){
            if (is_item()){
                //work backwards from the end shifting data right
                for (int i = size(); i > current_index; i--){
                    data[i] = data[i-1];
                }
                //passed value insert into current index
                data[current_index] = entry;
            }
            //no current value- data goes to front
            //shift data right
            else{
                for (int i = size(); i > 0; i--){
                    data[i] = data[i-1];
                }
                data[0] = entry;
                current_index = 0;
            }
            used++;
        }
    }
    //insert new value to the right of the current index and shift data right.
    //if no value found at current index, append value to  the end of the sequence
    void sequence::attach(const value_type& entry){
        if (size() < CAPACITY){
            //no current value- data goes to back
            if(!is_item()){
                data[size()] = entry;
                current_index = size();
            }
            else{
                ++current_index;
                //data to the right gets shifted right
                for (int i = size(); i > current_index; i--){
                    data[i] = data[i-1];
                }
                //new current_index gets new value
                data[current_index] = entry;
            }
            used++;
        }
    }
    //remove current value and fill void
    void sequence::remove_current( ){
        --used;//remove 1 from used part of array
        //Fill void by shifting all data left
        for (int i = current_index; i < size(); i++){
            data[i] = data[i + 1];
        }
    }
    //return size of sequence
    sequence::size_type sequence::size( ) const{
        return used;
    }
    //check if a value is in current index
    bool sequence::is_item( ) const{
        if (current_index >= size()){return false;}
        return true;
    }
    //return value of current index
    sequence::value_type sequence::current( ) const{
        if(is_item()){
            return data[current_index];
        }
    }

}
