/*
 *Jeff Flanegan
 * CSC 161 C++
 * Homework 3
 * 2019-8-30
 */
/*
 * FILE:sequence2.cxx
 * CLASS IMPLEMENTED: sequence2.h
 * INVARIANT for the sequence2 class:
 * 1. The number of items in the array is the member variable "used".
 * 2. The current cursor position on the array is the member variable "current_index".
 * 3. The size of the array is the member variable "capacity".
 * 4. The array is dynamic and is pointed to by the member variable "data"
 * 5. If the current cursor position is located at an index where a value
 *     has not been stored, this is considered to not have an item. we do not care about
 *     the part of the sequence which holds no items.
 */
#include <algorithm>
#include <cstdlib>
#include "sequence2.h"
using namespace std;

namespace main_savitch_4
{   
    const sequence::size_type sequence::DEFAULT_CAPACITY;
    
    //default constructor
     sequence::sequence(size_type initial_capacity)
    {
        data = new value_type[initial_capacity];
        capacity = initial_capacity;
        used = 0;
    }
    //copy constructor 
    sequence::sequence(const sequence& source)
    {
        data = new value_type[source.capacity];
        capacity = source.capacity;
        used = source.used;
        current_index = source.current_index;
        copy(source.data, source.data + used, data);
    }
    //destructor
    sequence::~sequence( )
    {
	delete [ ] data;
    }
    //make array larger by copying data to new, larger, array and destructing the old
    void sequence::resize(size_type new_capacity)
    {
        //memory was previously sufficient
        if (new_capacity == capacity || new_capacity < used)
            return;
        
        value_type *larger_array;       
        larger_array = new value_type[new_capacity];
        copy(data, data + used, larger_array);
        delete [ ] data;
        data = larger_array;
        capacity = new_capacity;
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
    //resize array if it is found to be too small
    void sequence::insert(const value_type& entry){
        if (size() >= capacity){
            resize(capacity + 5);
        }
            if (is_item()){
                //work backwards from the end shifting data right
                for (int i = size(); i > current_index; i--){
                    data[i] = data[i-1];
                }
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
    //insert new value to the right of the current index and shift data right.
    //if no value found at current index, append value to  the end of the sequence
    //resize array if it is found to be too small
    void sequence::attach(const value_type& entry){
                
        if (size() >= capacity){
            resize(capacity + 5);
        }
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
                data[current_index] = entry;
            }
            used++;
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
    //overload assignment operator for copying objects
    void sequence::operator =(const sequence& source)
    {
	value_type *new_data;

	// Check for possible self-assignment:
	if (this == &source)
            return;

	// If needed, allocate an array with a different size
	if (capacity != source.capacity)
	{ 
	    new_data = new value_type[source.capacity];
	    delete [ ] data;
	    data = new_data;
	    capacity = source.capacity;
	}

	// copy the data from the source array:
	used = source.used;
        current_index = source.current_index;
	copy(source.data, source.data + used, data);
    }

}


