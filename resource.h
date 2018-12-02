#include <string>
using namespace std;

class resource{
	protected:
		string name;
		string who_borrowed;
		char state;
		int yydd_del;
		int size;
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
		int get_yydd_del(){
			return yydd_del;
		}
		int get_size(){
			return size;
		}
		void set_who_borrowed(string who){
			who_borrowed = who;
		}
		void set_state(char c){
			state = c;
		}
		void set_yydd_del(int n){
			yydd_del = n;
		}
};

class book : public resource{
	public:
		book(string n){
			name = n;
			state = 'R';
			yydd_del = 0;
			size = 0;
		}
};

class e_book : public resource{
	public:
		e_book(string n){
			int a, i;
			string size_s;
			a = n.find('[');

			name = n.substr(0, a);
			size_s = n.substr(a+1);
			size_s = size_s.substr(0, size_s.length()-1);
			size = 0;
			for(i = 0; i < size_s.length(); i++){
				size *= 10;
				size += size_s[i]-48;
			}

			state = 'R';
			yydd_del = 0;
		}
};

class magazine : public resource{
	public:
		magazine(string n){
			yydd_del = 0;
			name = n;
			state = 'R';
			size = 0;
		}
};




