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
		void init();
		void do_work();
		book* find_book(string name);
		undergraduate* find_undergraduate(string name);
		void code_0(ofstream &fp, string resource_name, string member_name, char type, string date);
		void code_1(ofstream &fp);
		void code_2(ofstream &fp);
		void code_3(ofstream &fp);
		void code_4(ofstream &fp, string borrowed_date);
		void code_5(ofstream &fp, string return_date);
		void code_6(ofstream &fp, string restricted_date);
		void code_7(ofstream &fp, string resource_name, string member_name, string date, int delay);
		int get_sum(string date);
};

library :: library(){
	num_undergraduate = 0;
	init();
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
	for(i = 0; i < num_undergraduate; i++){
		if(name == undergraduate_p[i]->get_name()) return undergraduate_p[i];
	}
	return 0;
}

void library :: init(){
	ifstream fp("resource.dat");
	char temp[MAX];
	undergraduate* u;
	book* b;
	int i = 0;
	string tok;

	fp.getline(temp, MAX);
	while(1){
		fp.getline(temp, MAX);
		if(fp.eof()) break;
		else{
			stringstream ss(temp);
			ss >> tok;
			ss >> tok;
			b = new book(tok);
			book_p[i] = b;
			i++;
		}
	}
	num_book = i;
	fp.close();

	i = 0;
	ifstream fpi("input.dat");
	fpi.getline(temp, MAX);
	while(1){
		fpi.getline(temp, MAX);
		if(fpi.eof()) break;
		else{
			stringstream ss(temp);
			ss >> tok;
			ss >> tok;
			ss >> tok;
			ss >> tok;
			ss >> tok;
			ss >> tok;
			if(!find_undergraduate(tok)){
				u = new undergraduate(tok);
				undergraduate_p[i] = u;
				i++;
			}
		}
	}
	num_undergraduate = i;
	fpi.close();
}

void library :: do_work(){
	int i = 0;
	int delay;
	int yy, mm, dd, yy_d, mm_d, dd_d;
	undergraduate* up;
	book* bp;

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
	outf << "Op_#\tReturn_code\tDescription" << endl;


	inf.getline(temp, MAX);
	while(1){
		i++;
		inf.getline(temp, MAX);
		if(inf.eof()) break;
		else{
			outf << i << "\t";

			stringstream ss(temp);
			ss >> tok;
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

			up = find_undergraduate(member_name);
			bp = find_book(resource_name);

			if(operation == 'B'){
				if(!bp)
					code_1(outf);
				else if(up->get_borrowed())
					code_2(outf);
				else if(bp->get_state() == 'B'){
					if(bp->get_who_borrowed() == member_name)
						code_4(outf, up->get_borrowed_date());
					else
						code_5(outf, find_undergraduate(bp->get_who_borrowed())->get_deadline());
				}
				else if(up->get_restricted())
					if(get_sum(date) - get_sum(up->get_restricted_date()) <= 0)
						code_6(outf, up->get_restricted_date());
					else
						code_0(outf, resource_name, member_name, 'B', date);
				else
					code_0(outf, resource_name, member_name, 'B', date);
			}
			else{
				if(!up->get_borrowed())
					code_3(outf);
				else if(up->get_borrowed_book() != resource_name)	
					code_3(outf);
				else{
					delay = get_sum(date) - get_sum(up->get_deadline());
					if(delay > 0)	
						code_7(outf, resource_name, member_name, date, delay);
					else
						code_0(outf, resource_name, member_name, 'R', date);
				}
			}
		}
	}
	inf.close();
	outf.close();
}

void library :: code_0(ofstream &fp, string resource_name, string member_name, char type, string date){
	undergraduate* up;
	book* bp;
	char deadline[8];
	int yy, mm, dd;

	fp << "0\tSuccess." << endl;
	up = find_undergraduate(member_name);
	bp = find_book(resource_name);

	yy = (date[0]-48)*10 + date[1]-48;
	mm = (date[3]-48)*10 + date[4]-48;
	dd = (date[6]-48)*10 + date[7]-35;
	if(dd > 30){
		dd -= 30;
		mm++;
	}
	if(mm > 30){
		mm -= 12;
		yy++;
	}

	deadline[0] = yy/10 + 48;
	deadline[1] = yy%10 + 48;
	deadline[2] = '/';
	deadline[3] = mm/10 + 48;
	deadline[4] = mm%10 + 48;
	deadline[5] = '/';
	deadline[6] = dd/10 + 48;
	deadline[7] = dd%10 + 48;
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

void library :: code_1(ofstream &fp){
	fp << "1\tNon exist resource." << endl;
}

void library :: code_2(ofstream &fp){
	fp << "2\tExceeds your possible number of borrow. Possible# of borrows: 1" << endl;
}

void library :: code_3(ofstream &fp){
	fp << "3\tYou did not borrow this book." << endl;
}

void library :: code_4(ofstream &fp, string borrowed_date){
	fp << "4\tYou already borrowed this book at " << borrowed_date << endl;
}

void library :: code_5(ofstream &fp, string return_date){
	fp << "5\tOther member already borrowed this book. This book will be returned at " << return_date << endl;
}

void library :: code_6(ofstream &fp, string restricted_date){
	fp << "6\tRestricted member until " << restricted_date << endl;
}

void library :: code_7(ofstream &fp, string resource_name, string member_name, string date, int delay){
	int yy, mm, dd;
	char restricted_date[8];

	yy = (date[0]-48)*10 + date[1]-48;
	mm = (date[3]-48)*10 + date[4]-48;
	dd = (date[6]-48)*10 + date[7]-48;

	dd += delay;
	if(dd > 30){
		dd -= 30;
		mm++;
	}
	if(mm > 12){
		mm -= 12;
		yy++;
	}
	restricted_date[0] = yy/10 + 48;
	restricted_date[1] = yy%10 + 48;
	restricted_date[2] = '/';
	restricted_date[3] = mm/10 + 48;
	restricted_date[4] = mm%10 + 48;
	restricted_date[5] = '/';
	restricted_date[6] = dd/10 + 48;
	restricted_date[7] = dd%10 + 48;

	find_book(resource_name)->set_state('R');
	find_undergraduate(member_name)->set_restricted(1);
	find_undergraduate(member_name)->set_borrowed(0);
	find_undergraduate(member_name)->set_restricted_date(restricted_date);
	fp << "7\tDelayed return. You'll be restricted until " << restricted_date << endl;
}

int library :: get_sum(string date){
	int yy, mm, dd;
	yy = (date[0]-48)*10 + date[1]-48;
	mm = (date[3]-48)*10 + date[4]-48;
	dd = (date[6]-48)*10 + date[7]-48;

	return yy*360 + mm*12 + dd;
}

