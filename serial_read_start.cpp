//******************************************************************
// Program #: Reading from serial port
//
// Programmer: Matthew Gelber/Robert Klenke
//
// Due Date: NA
//
// EGRE 347, Fall 2020       Instructor: Robert Klenke
//
// Pledge: I have neither given nor received unauthorized aid on this program.
//
// Description: C++ example for reading information from serial port one byte at a time
//
// Input: command line argument of the desired serial port
//
// Output: none
//
//******************************************************************

#include <iostream>
#include <string>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <fstream>

#include "Sentences.h"

using namespace std;

const string TYPE1("GPGGA");
const string TYPE2("GPGSA");
const string TYPE3("GPGSV");
const string TYPE4("GPRMC");

int main(int argc, char *argv[])
{
	//create insteacne of class
	int i=0;

	//unsigned char read_buff;
	ifstream infile;
	char read_buff;
	finder find_1(TYPE1);
	finder find_2(TYPE2);
	finder find_3(TYPE3);
	finder find_4(TYPE4);

	
	cout << argv[1] << endl;
	int sp = open(argv[1], O_RDONLY | O_NOCTTY | O_NDELAY);	//opens the serial port inputted as argument as read only
	//cout<<"HELLO"<<endl<<endl;



	if(sp < 0)
		cout << "unable to open port " << argv[1] << endl;
	else
		cout << "port successfully opened" << endl;

	while(1){
		//reads from port one bit at a time
		int n = read(sp, &read_buff, sizeof(read_buff));

		

		if(find_1.find(read_buff) == true) {
			cout << "Found: " << TYPE1 <<endl;
		}

			//fix print statements  
		  //printf("Read byte:%c = %d\n", read_buff, read_buff);

		}
		
	close(sp);
}
