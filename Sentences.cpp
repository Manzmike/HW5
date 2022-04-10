
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
	int start;
	string temp;
	string Typetemp;												// start of the 3-character string

							
	
//type	


	
		if(State == Dollar ){
			if(c == '$'){
				State=Type_1;
				//cout<<"Going to Type 1"<<endl;
			}
			else{
				State=Dollar;
			}
		}


		else if(State == Type_1 ){

			if(c == to_find[0]){
				//cout<<"Going to Type 2"<<endl;

				
				this->Message_type+=c;

				State=Type_2;	
			}
			else if(c != to_find[0]){
				State = Type_1;
			}

			if('$' == c){
				//cout<<"Dollar State"<<endl;
				State = Dollar;
			}
			
		}

		else if(State == Type_2 ){
		
			if(c == to_find[1]){
				//cout<<"Going to Type 3"<<endl;

				this->Message_type+=c;

				State=Type_3;
				
			}
			else if(c != to_find[1]){
				State = Type_1;
			}

			if('$' == c){
				//cout<<"Dollar State"<<endl;
				State = Dollar;
			}
		}

		else if(State == Type_3 ){

			if(c == 'G' || c == 'R'){
				//cout<<"Going to Type 4"<<endl;

				this->Message_type+=c;

				State=Type_4;
				
			}
			else if(c != 'G' || c != 'R'){
				State = Type_1;
			}
			if('$' == c){
				//cout<<"Dollar State"<<endl;
				State = Dollar;
			}
		}

		else if(State == Type_4 ){
			
			if(c == 'G' || c == 'S'|| c == 'M'){
				//cout<<"Going to Type 5"<<endl;

				this->Message_type+=c;

				State=Type_5;
				
			}
			else if(c != to_find[3]){
				State = Type_1;
			}
			if('$' == c){
				//cout<<"Dollar State"<<endl;
				State = Dollar;	
			}
		}
		
		else if(State == Type_5 ){
			
			if(c == 'A' || c == 'V'|| c == 'C'){
				//return true;
				this->Message_type+=c;

				State = Data;
			}
			else if(c != to_find[4]){
				State = Type_1;
			}
			if('$' == c){
				//cout<<"Dollar State"<<endl;
				State = Dollar;
			}
		}

		else if(State == Data){

			if(c =='*'){
				this->newdata=data;
				this->data="";
				State = Check_Sum1;
			}
			else if('$' == c){
				//cout<<"Dollar State"<<endl;
				State = Dollar;
			}
			else{
			this-> data+=c;
			}
		}

		else if(State == Check_Sum1){

			//cout<<"Check Sum Val:"<<c<<endl;
			State=Check_Sum2;
			if(c == '$'){
				State = Dollar;
			}

		}

		else if(State == Check_Sum2){

			//cout<<"Check Sum Val:"<<c<<endl;
			State=Check_Sum2;
			if(c == '$'){
				State = Dollar;
			}
			return true;
		}

		
	return false;	
	}
					

	void finder::print(){
		cout<<"Message type:"<<Message_type<<endl;
		cout<<"Message data:"<<newdata<<endl;
		cout<<"Message checksum:"<<Checksum<<endl<<endl;

		Message_type="";
		Checksum="";
		newdata="";

		
	}
	

