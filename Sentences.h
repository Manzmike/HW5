using namespace std;

enum find_states{Dollar,Type,Type_1,Type_2,Type_3,Type_4,Type_5, Data, Star, Check_Sum};

class finder
{
	private:
		enum find_states State;		// Holds current state the traffic light is in
		string to_find;				// string to find
		
	public:
		finder(string);				// Constructor
		
		~finder();					// Destructor
	
	
		bool find(char c);			// Main implementation for the state machine
};
