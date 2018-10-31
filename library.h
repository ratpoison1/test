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
		int num_book;
		int num_undergraduate;
		book* book_p[MAX];
		undergraduate* undergraduate_p[MAX];
	public:
		library();
		void init_resource();
		void do_work();
		book* find_book(string name);
		undergraduate* find_undergraduate(string name);
		void code_0(ofstream &fp, string resource_type, string resource_name, string memeber_type, string member_name, char type, string deadline);
		void code_1(ofstream &fp, string resource_type, string resource_name, string memeber_type, string member_name);
		void code_2(ofstream &fp, string resource_type, string resource_name, string memeber_type, string member_name);
		void code_3(ofstream &fp, string resource_type, string resource_name, string memeber_type, string member_name);
		void code_4(ofstream &fp, string resource_type, string resource_name, string memeber_type, string member_name);
		void code_5(ofstream &fp, string resource_type, string resource_name, string memeber_type, string member_name);
		void code_6(ofstream &fp, string resource_type, string resource_name, string memeber_type, string member_name);
		void code_7(ofstream &fp, string resource_type, string resource_name, string memeber_type, string member_name, int delay);
};

library :: library(){
	num_undergraduate = 0;
	init_resource();
	do_work();
}


book* library :: find_book(string name){
	int i;
	for(i = 0; i < num_book; i++)
		if(name == book_p[i]->get_name()) return book_p[i];
	return 0;
}

undergraduate* library :: find_undergraduate(string name){
	int i;
	for(i = 0; i < num_undergraduate; i++)
		if(name == undergraduate_p[i]->get_name()) return undergraduate_p[i];
}

void library :: init_resource(){
	ifstream fp("resource.dat");
	char temp[MAX];
	book* b;
	int i = 0;

	while(1){
		fp.getline(temp, 100);
		if(fp.eof()) break;
		else{
			b = new book(temp);
			book_p[i] = b;
			i++;
		}
	}
	num_book = i;
	fp.close();
}

void library :: do_work(){
	int i = 0;
	undergraduate* u;

	int yy, mm, dd;
	char operation;
	string resource_type;
	string resource_name;
	string member_type;
	string member_name;
	string date;

	char temp[MAX];
	string tok;
	ifstream inf("input.dat");
	ofstream outf("output.dat");
	cout << "Op_#\tReturn_code\tDescription" << endl;

	int delay;
	int yy_d, mm_d, dd_d;
	int yy_n, mm_n, dd_n;
	string deadline;
	string bd;

	inf.getline(temp, MAX);
	while(1){
		i++;
		inf.getline(temp, MAX);
		if(inf.eof()) break;
		else{
			outf << i << "\t";

			stringstream ss(temp);
			ss >> tok;
			yy = (tok[0]-48)*10 + tok[1]-48;
			mm = (tok[3]-48)*10 + tok[4]-48;
			dd = (tok[6]-48)*10 + tok[7]-48;
			date = tok;
			
			ss >> tok;
			resource_type = tok;
			ss >> tok;
			resource_name = tok;
			ss >> tok;
			operation = tok[0];
			ss >> tok;
			member_type = tok;
			ss >> tok;
			member_name = tok;

			bd = find_undergraduate(member_name)->get_deadline();
			yy_d = (bd[0]-48)*10 + bd[1]-48;
			mm_d = (bd[3]-48)*10 + bd[4]-48;
			dd_d = (bd[6]-48)*10 + bd[7]-48;
			delay = (yy_d-yy)*360 + (mm_d-mm)*30 + dd_d-dd;

			dd_n = dd + 7;
			if(dd_n > 30){
				dd_n -= 30;
				mm_n++;
			}
			if(mm_n > 12){
				mm_n -= 12;
				yy_n++;
			}
			deadline[0] = yy_n/10 + 48;
			deadline[1] = yy_n%10 + 48;
			deadline[2] = '/';
			deadline[3] = mm_n/10 + 48;
			deadline[4] = mm_n%10 + 48;
			deadline[5] = '/';
			deadline[6] = dd_n/10 + 48;
			deadline[7] = dd_n%10 + 48;

			if(operation == 'B'){
				if(num_undergraduate == 0){
					u = new undergraduate(member_name);
					undergraduate_p[i-1] = u;
					code_0(outf, resource_type, resource_name, member_type, member_name, 'B', deadline);
				}
				else if(!find_book(resource_name))
					code_1(outf, resource_type, resource_name, member_type, member_name);
				else if(find_undergraduate(member_name)->get_borrowed())
					code_2(outf, resource_type, resource_name, member_type, member_name);
				else if(find_book(resource_name)->get_state() == 'B'){
					if(find_book(resource_name)->get_who_borrowed() == member_name)
						code_4(outf, resource_type, resource_name, member_type, member_name);
					else
						code_5(outf, resource_type, resource_name, member_type, member_name);
				}
				else if(find_undergraduate(member_name)->get_restricted())	
					code_6(outf, resource_type, resource_name, member_type, member_name);
				else
					code_0(outf, resource_type, resource_name, member_type, member_name, 'B', deadline);
			}
			else{
				if(find_undergraduate(member_name)->get_borrowed_book() != resource_name)	
					code_3(outf, resource_type, resource_name, member_type, member_name);
				else if(delay < 0)	
					code_7(outf, resource_type, resource_name, member_type, member_name, delay);
				else
					code_0(outf, resource_type, resource_name, member_type, member_name, 'R', deadline);
			}
		}
	}
	inf.close();
	outf.close();
}

void library :: code_0(ofstream &fp, string resource_type, string resource_name, string memeber_type, string member_name, char type, string deadline){
	undergraduate* up;
	book* bp;
	fp << "0\tSuccess." << endl;
	up = find_undergraduate(member_name);
	bp = find_book(resource_name);
	
	up->set_restricted(0);
	if(type == 'B'){
		up->set_borrowed(1);
		up->set_borrowed_book(resource_name);
		up->set_deadline(deadline);

		bp->set_who_borrowed(member_name);
		bp->set_state('B');
	}	
	else{
		up->set_borrowed(0);
		bp->set_state('R');
	}
}



