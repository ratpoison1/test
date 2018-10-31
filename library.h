#include "resource.h"
#include "member.h"
#include "input.h"
#include <string>
#include <sstream>
#include <fstream>
#define MAX 500
using namespace std;

class library{
	private:
		int num_input;
		int num_resource;
		input* input_p[MAX];
		resource* resource_p[MAX];
	public:
		library();
		void init_resource();
		void get_input();
		void do_work();
		void do_borrow(int* fp, resource* rp, member* mp);
		void do_return(int* fp, resource* rp, member* mp);
		resource* find_resource(string name);
		member* find_member(string name);
};

library :: library(){
	init_resource();
	get_input();
	do_work();
}

void library :: do_borrow(int* fp, resource* rp, member* mp){
	if(rp == 0) cout << "there is no resource" << endl;
	else cout << "ok" << endl;
}

resource* library :: find_resource(string name){
	int i;
	for(i = 0; i < num_resource; i++)
		if(name == resource_p[i]->get_name()) return resource_p[i];
	return 0;
}

member* library :: find_member(string name){
	int i;
	for(i = 0; i < num_member; i++)
		if(name == member_p[i]->get_name()) return member_p[i];
	return 0;
}

void library :: init_resource(){
	ifstream fp("resource.dat");
	char temp[MAX];
	book* b[MAX];
	int i = 0;

	while(1){
		fp.getline(temp, 100);
		if(fp.eof()) break;
		else{
			b[i] = new book(temp);
			resource_p[i] = b[i];
			i++;
		}
	}
	num_resource = i;
	fp.close();
}

void library :: get_input(){
	ifstream fp("input.dat");
	char temp[MAX];
	string temp2;
	int temp_int;
	input* in[MAX];
	int i = 0;

	fp.getline(temp, 100);
	while(1){
		fp.getline(temp, 100);
		if(fp.eof()) break;
		else{
			in[i] = new input();
			input_p[i] = in[i];
			stringstream ss(temp);

			ss >> temp2;
			in[i]->set_yy(temp2[0], temp2[1]);
			in[i]->set_mm(temp2[3], temp2[4]);
			in[i]->set_dd(temp2[6], temp2[7]);

			ss >> temp2;
			in[i]->set_resource_type(temp2);

			ss >> temp2;
			in[i]->set_resource_name(temp2);

			ss >> temp2;
			in[i]->set_operation(temp2);

			ss >> temp2;
			in[i]->set_member_type(temp2);

			ss >> temp2;
			in[i]->set_member_name(temp2);

			i++;
		}
	}
	num_input = i;
	fp.close();
}

void library :: do_work(){
	int i;
	ofstream fp("output.dat");
	cout << "Date[yy/mm/dd]\tResource_type\tResource_name\tOperation\tMember_type\tMember_name" << endl;
	for(i = 0; i < num_input; i++){
		if(input_p[i]->get_operation() == 'B') 
			do_borrow(fp, find_resource(input_p[i]->get_resource_name()), find_member(input_p[i]->get_memer_name()));
		else do_return(fp);
	}
	fp.close();
}

