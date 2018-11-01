using namespace std;

class resource{
	protected:
		string name;
		string who_borrowed;
		char state;
	public:
		char get_state(){
			return state;
		}
		string get_name(){
			return name;
		}
		string get_who_borrowed(){
			return who_borrowed;
		}
		void set_who_borrowed(string who){
			who_borrowed = who;
		}
		void set_state(char c){
			state = c;
		}
};

class book : public resource{
	public:
		book(string n){
			name = n;
			state = 'R';
		}
};


