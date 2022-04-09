
#include <string>
#include <iostream>

#include "Sentences.h"

using namespace std;

finder::finder(string s)									// constructor
{
	to_find = s;											// setup string to find in incoming characters
	State = Type;											// set initial state to "None"
}

finder::~finder()			// destructor
{

}

bool finder::find(char c)
{
	int i;
	int start;												// start of the 3-character string
	i=0;
	// this code is the State Machine that looks for the occurance of the
	// 3-character in3 string variable in the instring variable //dollar sign
/*
	if(State == Dollar && c == to_find[i]) {
	State=Type;					
		i++;							
	}
//type	
	else if(State == Type) {
		i++;

		if(State == Type && c == to_find[0]) {					// found 1st character
			State = Type_1;									// go to FOUND_ONE state
		}


		else if(State == Type_1) {
			if(c == to_find[1])									// found 2nd character
				State = Type_2;								// go to FOUND_TWO state
			else if(c == to_find[0]) {							// found 1st character again
				State = Type_1;								// go back the FOUND_ONE state
			}
			else												// didn't find the 1st or 2nd character
				State = Type;									// go back to the NONE state
		}


		else if(State == Found_Two) {
			if(c == to_find[2]) {								// found 3rd character
				State = Type;
				return true;									// return true
			}
			else if(c == to_find[0]) {							// found 1st character again
				State = Found_One;								// go back to FOUND_ONE state
			}
			else												// didn't find 3rd or 1st character
				State = Type;									// go back to the NONE state
		}		
	}

//data
	else if(State == Data) {
		if(c == to_find[i]) {								
			State = Dollar;
			i++;									
		}
		else if(c == to_find[i]) {							
			State = Data;								
		}
		else												
			State = Dollar;		
	}

//star
	else if(State == Star) {
		if(c == to_find[i]) {								
			State = Dollar;									
		}
		else if(c == to_find[0]) {							
			State = Star;								
		}
		else												
			State = Dollar;									
	}

//checksum
	else if(State == Data) {
		if(c == to_find[2]) {								
			State = Dollar;
			return true;									
		}
		else												
			State = Dollar;		
		}												
	return false;	
*/

if(State == Type) {
//cout<<"Start"<<endl;
//G	
		if(State == Type && c == to_find[0]) {
			cout<<"Start Letter "<<to_find[0]<<endl;
			cout<<"Start Letter "<<to_find[1]<<endl;
			cout<<"Start Letter "<<to_find[2]<<endl;
			cout<<"Start Letter "<<to_find[3]<<endl;
			cout<<"Start Letter "<<to_find[4]<<endl;
			State = Type_1;
			//cout<<"CHECK!!!"<<endl<<endl;
										
		}

//P
		else if(State == Type_1) {
			cout<<"CHECK!!!"<<endl<<endl;
			if(c == to_find[1]){
				cout<<"Type 1 Letter "<<to_find[1]<<endl;									
				State = Type_2;
				cout<<"Stop 1"<<endl;
			}
												
			
			else if('$' == to_find[i]){
				cout<<"Stop 2"<<endl;
				State = Dollar;
			}
			
			else{	
				cout<<"Stop 3"<<endl;											
				State = Type;
			}
		}									
		
//G
		else if(State == Type_2) {
			i++;
			if(c == to_find[2]){	
				cout<<"Type 2 Letter "<<to_find[2]<<endl;							
				State = Type_3;
			}
												
			
			else if('$' == to_find[i])
				State = Dollar;
			
			else												
				State = Type;
		}								
		
//G
		else if(State == Type_3) {
			i++;
			if(c == to_find[3]){
				cout<<"Type 3 Letter "<<to_find[3]<<endl;									
				State = Type_4;
			}
												
			
			else if('$' == to_find[i])
				State = Dollar;
			
			else												
				State = Type;
		}

		

//A		
		else if(State == Type_4) {
			i++;
			if(c == to_find[4]){
				cout<<"Type 4 Letter "<<to_find[4]<<endl;									
				State = Data;
				return true;
			}
																				
			
			else if('$' == to_find[i])
				State = Dollar;
			
			else												
				State = Type;
		}								
		
	}
	return false;
}							


