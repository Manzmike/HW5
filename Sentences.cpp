
#include <string>
#include <iostream>

#include "Sentences.h"

using namespace std;

finder::finder(string s)									// constructor
{
	to_find = s;											// setup string to find in incoming characters
	State = Dollar;											// set initial state to "None"
}

finder::~finder()			// destructor
{

}

bool finder::find(char c)
{
	int i;
	int start;												// start of the 3-character string

							
	
//type	


	/*if(State == Type) {
		cout<<"Type state"<<endl;*/
		if(State == Dollar ){
			if(c == '$'){
				State=Type_1;
				cout<<"Going to Type 1"<<endl;
			}
			else{
				State=Dollar;
			}
		}


		else if(State == Type_1 ){
			cout<<"State 1 "<<"To Find: "<<to_find[0]<<" C: "<<c<<endl;

			if(c == to_find[0]){
				//When G = G
				cout<<"Going to Type 2"<<endl<<endl;
				State=Type_2;
			}
			if('$' == c){
				cout<<"Dollar State"<<endl;
				State = Dollar;
			}
			
		}

		else if(State == Type_2 ){
			cout<<"State 2 "<<"To Find: "<<to_find[1]<<" C: "<<c<<endl;
		
			if(c == to_find[1]){
				cout<<"Going to Type 3"<<endl<<endl;
				State=Type_3;
			}
			if('$' == c){
				cout<<"Dollar State"<<endl;
				State = Dollar;
			}
		}

		else if(State == Type_3 ){
			cout<<"State 3 "<<"To Find: "<<to_find[2]<<" C: "<<c<<endl;
			if(c == to_find[2]){
				cout<<"Going to Type 4"<<endl<<endl;
				State=Type_4;
			}
			if('$' == c){
				cout<<"Dollar State"<<endl;
				State = Dollar;
			}
		}

		else if(State == Type_4 ){
			cout<<"State 4 "<<"To Find: "<<to_find[3]<<" C: "<<c<<endl;
			if(c == to_find[3]){
				cout<<"Going to Type 5"<<endl<<endl;
				State=Type_5;
			}
			if('$' == c){
				cout<<"Dollar State"<<endl;
				State = Dollar;	
			}
		}
		
		else if(State == Type_5 ){
			cout<<"State 5 "<<"To Find: "<<to_find[4]<<" C: "<<c<<endl;
			if(c == to_find[4]){
				//return true;
				State = Data;
			}
			if('$' == c){
				cout<<"Dollar State"<<endl;
				State = Dollar;
			}
		}

		else if(State == Data){
			cout<<"Searching!"<<endl;
			cout<<c<<endl;
			if(c =='*'){
				State = Star;
			}
			else if('$' == c){
				cout<<"Dollar State"<<endl;
				State = Dollar;
			}

		}

		else if(State == Star){
			cout<<"At Star!"<<endl;
			State=Check_Sum;
			if(c == '$'){
				State = Dollar;
			}

		}
		else if(State == Check_Sum){

			cout<<c<<endl;
			exit(1);
		}
	return false;	
	}
	
							


