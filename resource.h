using namespace std;

class resource{
	protected :
		string name;
		char state;
	string get_name(){
		return name;
	}
};

class book : public resource{
	public :
		book(string n){
			name = n;
			state = 'R';
		}
};


