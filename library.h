#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "input.h"
#include "member.h"
#include "resource.h"

class library{
	private:
		int num_input;
		int num_book;
		int num_member;
		vector<book*> book_p;
		vector<member*> member_p;
	public:
		library();
		void init();
		void do_work();
		book* find_book(string name);
		member* find_member(string name);
		void code_0(ofstream &fp, string resource_name, string member_name, char type, string date);
		void code_1(ofstream &fp);
		void code_2(ofstream &fp, string member_name);
		void code_3(ofstream &fp);
		void code_4(ofstream &fp, string borrowed_date);
		void code_5(ofstream &fp, string return_date);
		void code_6(ofstream &fp, string restricted_date);
		void code_7(ofstream &fp, string resource_name, string member_name, string date, int delay);
		int get_sum(string date);
};

library :: library(){
	num_member = 0;
	init();
	do_work();
}


book* library :: find_book(string name){
	int i;
	for(i = 0; i < num_book; i++){
		if(name == book_p[i]->get_name()) return book_p[i];
	}
	return 0;
}

member* library :: find_member(string name){
	int i;
	for(i = 0; i < num_member; i++){
		if(name == member_p[i]->get_name()) return member_p[i];
	}
	return 0;
}

void library :: init(){
	ifstream fp("resource.dat");
	string temp;
	member* mp;
	book* bp;
	int i = 0;
	string tok;
	string member_type;

	getline(fp, temp);
	while(1){
		getline(fp, temp);
		if(fp.eof()) break;
		else{
			stringstream ss(temp);
			ss >> tok;
			ss >> tok;
			bp = new book(tok);
			book_p.push_back(bp);
			i++;
		}
	}
	num_book = i;
	fp.close();

	i = 0;
	ifstream fpi("input.dat");
	getline(fpi, temp);
	while(1){
		getline(fpi, temp);
		if(fpi.eof()) break;
		else{
			stringstream ss(temp);
			ss >> tok;
			ss >> tok;
			ss >> tok;
			ss >> tok;
			ss >> tok;
			member_type = tok;
			ss >> tok;
			if(!find_member(tok)){
				if(member_type == "Undergraduate") mp = new undergraduate(tok);
				else if(member_type == "Graduate") mp = new graduate(tok);
				else if(member_type == "Faculty") mp = new faculty(tok);
				else cout << "wrong input : wrong member type" << endl;
				member_p.push_back(mp);
				i++;
			}
		}
	}
	num_member = i;
	fpi.close();
}

void library :: do_work(){
	int i = 0;
	int delay;
	int yy, mm, dd, yy_d, mm_d, dd_d;
	member* mp;
	book* bp;

	string operation;
	string resource_type;
	string resource_name;
	string member_type;
	string member_name;
	string date;
	string temp;
	string tok;

	ifstream inf("input.dat");
	ofstream outf("output.dat");
	outf << "Op_#\tReturn_code\tDescription" << endl;


	getline(inf, temp);
	while(1){
		i++;
		getline(inf, temp);
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
			operation = tok;
			ss >> tok;
			member_type = tok;
			ss >> tok;
			member_name = tok;
	
			mp = find_member(member_name);
			bp = find_book(resource_name);
		
			if(operation == "B"){
				if(!bp)
					code_1(outf);
				else if(mp->get_num_limit() == mp->get_num_borrowed())
					code_2(outf, member_name);
				else if(bp->get_state() == 'B'){
					if(bp->get_who_borrowed() == member_name)
						code_4(outf, mp->get_borrowed_date());
					else
						code_5(outf, find_member(bp->get_who_borrowed())->get_deadline(resource_name));
				}
				else if(get_sum(date) <= get_sum(mp->get_restricted_date()))
					code_6(outf, mp->get_restricted_date());
				else
					code_0(outf, resource_name, member_name, 'B', date);
			}
			else{
				if(!bp){
					code_1(outf);
				}
				else if(!mp->check_book(resource_name))
					code_3(outf);
				else{
					delay = get_sum(date) - get_sum(mp->get_deadline(resource_name));
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
	member* mp;
	book* bp;
	string deadline;
	int yy, mm, dd;

	fp << "0\tSuccess." << endl;
	mp = find_member(member_name);
	bp = find_book(resource_name);

	yy = (date[0]-48)*10 + date[1]-48;
	mm = (date[3]-48)*10 + date[4]-48;
	dd = (date[6]-48)*10 + date[7]-48;

	dd += mp->get_loan_period() - 1;

	if(dd > 30){
		dd -= 30;
		mm++;
	}
	if(mm > 12){
		mm -= 12;
		yy++;
	}

	deadline += yy/10 + 48;
	deadline += yy%10 + 48;
	deadline += '/';
	deadline += mm/10 + 48;
	deadline += mm%10 + 48;
	deadline += '/';
	deadline += dd/10 + 48;
	deadline += dd%10 + 48;
	if(type == 'B'){
		mp->add_list(resource_name, deadline);
		bp->set_who_borrowed(member_name);
		bp->set_state('B');
	}	
	else if(type == 'R'){
		mp->del_list(resource_name);
		bp->set_state('R');
	}
	else cout << "code_0 error : wrong operation" << endl;
}

void library :: code_1(ofstream &fp){
	fp << "1\tNon exist resource." << endl;
}

void library :: code_2(ofstream &fp, string member_name){
	member* mp = find_member(member_name);
	fp << "2\tExceeds your possible number of borrow. Possible# of borrows: " << mp->get_num_limit() << endl;
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
	string restricted_date;
	member* mp = find_member(member_name);
	string date_r = mp->get_restricted_date();
	if(get_sum(date) > get_sum(mp->get_restricted_date())){
		yy = (date[0]-48)*10 + date[1]-48;
		mm = (date[3]-48)*10 + date[4]-48;
		dd = (date[6]-48)*10 + date[7]-48;
	}
	else{
		yy = (date_r[0]-48)*10 + date_r[1]-48;
		mm = (date_r[3]-48)*10 + date_r[4]-48;
		dd = (date_r[6]-48)*10 + date_r[7]-48;
	}

	dd += delay;
	if(dd > 30){
		dd -= 30;
		mm++;
	}
	if(mm > 12){
		mm -= 12;
		yy++;
	}
	restricted_date += yy/10 + 48;
	restricted_date += yy%10 + 48;
	restricted_date += '/';
	restricted_date += mm/10 + 48;
	restricted_date += mm%10 + 48;
	restricted_date += '/';
	restricted_date += dd/10 + 48;
	restricted_date += dd%10 + 48;

	find_book(resource_name)->set_state('R');
	mp->del_list(resource_name);
	mp->set_restricted_date(restricted_date);
	fp << "7\tDelayed return. You'll be restricted until " << restricted_date << endl;
}

int library :: get_sum(string date){
	int yy, mm, dd;
	yy = (date[0]-48)*10 + date[1]-48;
	mm = (date[3]-48)*10 + date[4]-48;
	dd = (date[6]-48)*10 + date[7]-48;

	return yy*360 + mm*30 + dd;
}

