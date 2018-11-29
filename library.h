#include "resource.h"
#include "member.h"
#include "input.h"
#include "space.h"
#include <string>
#include <fstream>
<<<<<<< HEAD
#include <sstream>
#include <vector>

using namespace std;

class library{
	private:
<<<<<<< HEAD
		vector<book*> book_p;
		vector<member*> member_p;
		vector<space*> space_p;
		vector<string> input_list;
	public:
		library();
		void init();
		void do_work();
		void refresh(string date, string past_date);
		book* find_book(string name);
		member* find_member(string name);
		void code_0(ofstream &fp, string resource_name, string member_name, char type, string date);
		void code_0_s(ofstream &fp, string space_type, string member_name, char type, string date, int time, int space_number, int number_of_member);
		void code_1(ofstream &fp);
		void code_2(ofstream &fp, string member_name);
		void code_3(ofstream &fp);
		void code_4(ofstream &fp, string borrowed_date);
		void code_5(ofstream &fp, string return_date);
		void code_6(ofstream &fp, string restricted_date);
		void code_7(ofstream &fp, string resource_name, string member_name, string date, int delay);
		void code_8(ofstream &fp);
		void code_9(ofstream &fp, string space_type, int space_number);
		void code_10(ofstream &fp);
		void code_11(ofstream &fp);
		void code_12(ofstream &fp);
		void code_13(ofstream &fp);
		void code_14(ofstream &fp, string space_type);
		float get_sum(string date);
		void sort_input();
<<<<<<< HEAD
		void save_resource();
		void save_input();
		void save_space();
};

library :: library(){
<<<<<<< HEAD
	init();
	save_input();
	save_space();
	sort_input();
	do_work();
	int i;
}


book* library :: find_book(string name){
	int i;
	for(i = 0; i < book_p.size(); i++){
		if(name == book_p[i]->get_name()) return book_p[i];
	}
	return 0;
}

member* library :: find_member(string name){
	int i;
	for(i = 0; i < member_p.size(); i++){
		if(name == member_p[i]->get_name()) return member_p[i];
	}
	return 0;
}

void library :: init(){
	ifstream fp("resource.dat");
<<<<<<< HEAD
	string temp;
	book* bp;
	space* st;
	int i = 0;
	string tok;

	// save resource.dat //
	getline(fp, temp);
	while(1){
		getline(fp, temp);
		if(fp.eof()) break;
		else{
			stringstream ss(temp);
			ss >> tok;
			ss >> tok;
<<<<<<< HEAD
			bp = new book(tok);
			book_p.push_back(bp);
		}
	}
	fp.close();
	//// 

<<<<<<< HEAD
	// allocate space_p //
	for(i = 0; i < 13; i++){
		if(i < 10) st = new seat(i+1);
		else st = new studyroom(i-9);
	}
	////
}

void library :: save_input(){
	string temp;
	string tok;
	member* mp;
	int i = 0;

	ifstream fpi("input.dat"); 
<<<<<<< HEAD
	getline(fpi, temp);
	while(1){
		getline(fpi, temp);
		if(fpi.eof()) break;
		else{
<<<<<<< HEAD
			input_list.push_back(temp);
			stringstream ss(temp);
			ss >> tok;
			ss >> tok;
			ss >> tok;
			ss >> tok;
			ss >> tok;
			member_type = tok;
			ss >> tok;
<<<<<<< HEAD
			if(!find_member(tok)){
				if(member_type == "Undergraduate") mp = new undergraduate(tok);
				else if(member_type == "Graduate") mp = new graduate(tok);
				else if(member_type == "Faculty") mp = new faculty(tok);
				else cout << "wrong input : wrong member type" << endl;
				member_p.push_back(mp);
			}
		}
		i++;
	}
	fpi.close();
}

void library :: save_space(){
<<<<<<< HEAD
	string temp;
	string tok;
	member* mp;

	ifstream fpi("space.dat");
	getline(fpi, temp);
	while(1){
		getline(fpi, temp);
		if(fpi.eof()) break;
		else{
			input_list.push_back(temp);
			stringstream ss(temp);
			ss >> tok;
			ss >> tok;
			ss >> tok;
			ss >> tok;
			ss >> tok;
			ss >> tok;
<<<<<<< HEAD
			if(!find_member(tok)){
				if(member_type == "Undergraduate") mp = new undergraduate(tok);
				else if(member_type == "Graduate") mp = new graduate(tok);
				else if(member_type == "Faculty") mp = new faculty(tok);
				else cout << "wrong input : wrong member type" << endl;
				member_p.push_back(mp);
			}
		}
	}
	fpi.close();
}

void library :: sort_input(){
<<<<<<< HEAD
	int i = 0;
	string tok1, tok2, temp;
	while(1){
		stringstream ss(input_list[i]);
		ss >> tok1;
		i++;
<<<<<<< HEAD
		if(i == input_list.size()) break;
		else{
			stringstream ss(input_list[i]);
			ss >> tok2;
		}
		if(get_sum(tok1) > get_sum(tok2)){
			temp = input_list[i-1];
			input_list[i-1] = input_list[i];
			input_list[i] = temp;
			i = 0;
		}
	}
}

void library :: do_work(){
	int i = 0;
	int delay;
	int yy, mm, dd, yy_d, mm_d, dd_d;
<<<<<<< HEAD
	member* mp;
	int hh;
	book* bp;
	space* sp;

	string operation;
	string resource_type;
	string resource_name;
	string member_type;
	string member_name;
	string date;
	string past_date;

	string space_type;
	string time_string;
	string space_number_string;
	string number_of_member_string;
<<<<<<< HEAD
	int space_number;
	int number_of_member;
	int time;
	bool past_check = 0;

	string temp;
	string tok;
<<<<<<< HEAD

	ifstream inf("input.dat");
	ofstream outf("output.dat");
	outf << "Op_#\tReturn_code\tDescription" << endl;

	while(i < input_list.size()){
		temp = input_list[i];
		i++;
		outf << i << "\t";

		stringstream ss(temp);
		ss >> tok;
		date = tok;

		// in "space.dat", cutting space_type, space_number //
		if(date[2] != '/'){
			ss >> tok;
<<<<<<< HEAD
			space_type = tok;
			ss >> tok;
			space_number_string = tok;
			if(space_number_string.length() == 1)
				space_number = space_number[0]-48;
			elsei
				space_number = (space_number_string[0]-48)*10 + space_number_string[1]-48;
			sp = space_p[space_number-1];
		}
		////

		// in "input.h", cutting resource_type, resource_name //
		else{ 
			ss >> tok;
			resource_type = tok;
			ss >> tok;
			resource_name = tok;i
			bp = find_book(resource_name);
		}
		////

		ss >> tok;
		operation = tok;
		ss >> tok;
		member_type = tok;
		ss >> tok;
		member_name = tok;
	
		mp = find_member(member_name);
		
		// in "space.h", cutting number_of_member, time //
		if(date[2] != '/' && operation == 'B'){
			ss >> tok;
			number_of_member_string == tok;
			if(number_of_member_string.length() == 1)
				number_of_member = number_of_member_string[0]-48;
			else
				number_of_member = (number_of_member_string[0]-48)*10 + number_of_member_string[1]-48;
			ss >> tok;
<<<<<<< HEAD
			time_string = tok;
			if(tok.length() == 1)
				time = time_string[0] - 48;
			else
				time = (time_string[0]-48)*10 + time_string[1]-48;
		}
		////

		// resource do_work //
		if(date[2] == '/'){
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
		////

		// space do_word //
		else{ 
			hh = (date[11]-48)*10 + date[12]-48;
			if(past_check) refresh(date, past_date); // refresh	
			if(space_type == "StudyRoom"){
				if(operation == 'B'){
					if(space_number > STUDYROOM) code_8(outf);
					else if(hh < 9 || hh > 18) code_9(outf, space_type, space_number);
					else if(up->get_borrowed_studyroom() != 0) code_11(outf);
					else if(number_of_member > 6) code_12(outf);
					else if(time > 6) code_13(outf);
					else if(studyroom_num == 10) code_14(outf, space_type);
					else code_0_s(outf, space_type, member_name, 'B', date, time, space_number, number_of_member);
				}
				else if(operation == 'R'){
					if(space_number > STUDYROOM) code_8(outf);
					else if(hh < 9 || hh > 18) code_9(outf, space_type, space_number);
					else if(up->get_borrowed_studyroom() == 0) code_10(outf);
					else code_0_s(outf, space_type, member_name, 'R', date, time, space_number, number_of_member);	
				}
				else if(operation == 'E'){
					if(space_number > STUDYROOM) code_8(outf);
					else if(hh < 9 || hh > 18) code_9(outf, space_type, space_number);
					else if(up->get_borrowed_studyroom() == 0) code_10(outf);
					else code_0_s(outf, space_type, member_name, 'E', date, time, space_number, number_of_member);	
				}
				else{
					if(space_number > STUDYROOM) code_8(outf);
					else if(hh < 9 || hh > 18) code_9(outf, space_type, space_number);
					else if(up->get_borrowed_studyroom() == 0) code_10(outf);
					else code_0_s(outf, space_type, member_name, 'E', date, time, space_number, number_of_member);	
				}
			}
			else if(space_type == "Seat"){
				if(operation == 'B'){
					if(space_number > SEAT) code_8(outf);
					else if(space_number == 2 && (hh < 9 || hh > 21)) code_9(outf, space_type, space_number);
					else if(space_number == 3 && (hh < 9 || hh > 19)) code_9(outf, space_type, space_number);
					else if(up->get_borrowed_seat() != 0) code_11(outf);
					else if(number_of_member > 6) code_12(outf);
					else if(time > 3) code_13(outf);
					else if(sr->get_borrowed_number() + number_of_member > 50) code_14(outf, space_type);
					else code_0_s(outf, space_type, member_name, 'B', date, time, space_number, number_of_member);
				}
				else if(operation == 'R'){
					if(space_number > SEAT) code_8(outf);
					else if(time < 9 || time > 18) code_9(outf, space_type, space_number);
					else if(up->get_borrowed_studyroom() == 0) code_10(outf);
					else code_0_s(outf, space_type, member_name, 'R', date, time, space_number, number_of_member);	
				}
				else if(operation == 'E'){
					if(space_number > SEAT) code_8(outf);
					else if(space_number == 2 && (hh < 9 || hh > 21)) code_9(outf, space_type, space_number);
					else if(space_number == 3 && (hh < 9 || hh > 19)) code_9(outf, space_type, space_number);
					else if(up->get_borrowed_studyroom() == 0) code_10(outf);
					else code_0_s(outf, space_type, member_name, 'E', date, time, space_number, number_of_member);	
				}
				else{
					if(space_number > SEAT) code_8(outf);
					else if(space_number == 2 && (hh < 9 || hh > 21)) code_9(outf, space_type, space_number);
					else if(space_number == 3 && (hh < 9 || hh > 19)) code_9(outf, space_type, space_number);
					else if(up->get_borrowed_studyroom() == 0) code_10(outf);
					else code_0_s(outf, space_type, member_name, 'C', date, time, space_number, number_of_member);	
				}
>>>>>> --need--
			}
			else cout << "wrong input, space_type : " << space_type << endl;
		}
		////

		past_date = date;
		past_check = 1;
	}
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
<<<<<<< HEAD

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

void library :: code_0_s(ofstream &fp, string space_type, string member_name, char type, string date, int time, int space_number, int number_of_member){
	member* mp;
	space* sp;
	int hh, hh_e;

	mp = find_member(member_name);

	hh = (date[11]-48)*10 + date[12]-48;
	hh += time;
	hh_e = hh + 1;
	if(space_type == "StudyRoom"){
		if(hh > 18) hh = 18;
	}
	else if(space_type == "Seat"){
		if(space_number == 2){
			if(hh > 21) hh = 21;
			if(hh_e > 21) hh_e = 21;
		}
		else if(space_number == 3){
			if(hh > 18) hh = 18;
			if(hh_e > 18) hh_e = 18;
		}
		else cout << "code_0_s : time limit space_number error" << endl;
	}

	int i;
	if(space_type == "StudyRoom"){
		sp = space_p[space_number-1];
			
		if(type == 'B'){
			mp->set_borrowed_studyroom(space_number);
			mp->set_studyroom_hh(hh);
		}	
		else if(type == 'R')
			mp->set_borrowed_studyroom(0);
	}
	else if(space_type == "Seat"){
		sp = space_p[space_number+9];
	
		if(type == 'B'){
			mp->set_borrowed_seat(space_number);
			mp->set_seat_hh(hh);
			mp->set_howmany_seat(number_of_member);
			sp->set_borrowed_number(st->get_borrowed_number() + number_of_member);
		}	
		else if(type == 'R'){
			mp->set_borrowed_seat(0);
			sp->set_borrowed_number(st->get_borrowed_number() - number_of_member);
		}
		else if(type == 'E'){
			mp->set_empty_hh(up->get_seat_hh());
			mp->set_seat_hh(hh_e);
		}
		else if(type == 'C'){
			mp->set_seat_hh(up->get_empty_hh());
		}
	}
	else fp << "code_0_s space_type error. space_type : " << space_type << endl;
	fp << "0\tSuccess." << endl;
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

void library :: code_8(ofstream &fp){
	fp << "8\tInvalid space id." << endl;
}

void library :: code_9(ofstream &fp, string space_type, int space_number){
	fp << "9\tThis space is not available now. Available from ";
	if(space_type == "StudyRoom") fp << "09 to 18." << endl;
	else if(space_type == "Seat"){
		if(space_number == 1) fp << "always. (code_9 error)" << endl;
		if(space_number == 2) fp << "09 to 21." << endl;
		if(space_number == 3) fp << "09 to 18." << endl;
	}
	else cout << "code_9 space_type error. space_type : "<< space_type << endl;
}

void library :: code_10(ofstream &fp){
	fp << "10\tYou did not borrow this place." << endl;
}
<<<<<<< HEAD

void library :: code_11(ofstream &fp){
	fp << "11\tYou already borrowed this kind of space." << endl;
}

void library :: code_12(ofstream &fp){
	fp << "12\tExceed available number." << endl;
}

void library :: code_13(ofstream &fp){
	fp << "13\tExceed available time." << endl;
}

void library :: code_14(ofstream &fp, string space_type){
	fp << "14\tThere is no remain space. This space is available after ";
	int i, hh, time, temp;
	time = 24;

	for(i = 0; i < member_p.size(); i++){
		if(space_type == "StudyRoom"){
			if(member_p[i]->get_borrowed_studyroom() != 0)
				temp = member_p[i]->get_studyroom_hh();
		}
		else if(space_type == "Seat"){
			if(member_p[i]->get_borrowed_seat() != 0)
				temp = member_p[i]->get_seat_hh();
		}
		if(time > temp) time = temp;
	}
	fp << time << endl;
}

float library :: get_sum(string date){
	int yy, mm, dd, hh;
	if(date[2] == '/'){
		yy = (date[0]-48)*10 + date[1]-48;
		mm = (date[3]-48)*10 + date[4]-48;
		dd = (date[6]-48)*10 + date[7]-48;
		return yy*360 + mm*30 + dd;
	}
	else{
		yy = (date[2]-48)*10 + date[3]-48;
		mm = (date[5]-48)*10 + date[6]-48;
		dd = (date[8]-48)*10 + date[9]-48;
		hh = (date[11]-48)*10 + date[12]-48;
		return yy*360 + mm*30 + dd + hh/100;
	}
}

void library :: sort_input(){
	int i;
	string tok1, tok2, temp;
	i = 0;
	whlie(1){
		stringstream ss1(input_list[i]);
		ss1 >> tok1;
		i++;
		if(i == num_input break);
		else{
			stringstream ss2(input_list[i]);
			ss2 >> tok2;
		}
		if(get_sum[tok1] > get_sum[tok2]){
			temp = input_list[i-1];
			input_list[i-1] = input_list[i];
			input_list[i] = temp;
			i = 0;
		}
	}
}

void library :: refresh(string date, string past_date){
	int i;
	int hh;
<<<<<<< HEAD
	member* mp;
	space* sp;
	hh = (date[11]-48)*10 + date[12]-48;
	if(get_sum(date) - get_sum(past_date) < 0.5){
		for(i = 0; i < member_p.size(); i++){
			mp = member_p[i];
			if((mp->get_borrowed_seat() != 0) && (hh >= mp->get_seat_hh())){
				sp = space_p[mp->get_borrowed_seat()-1];
				mp->set_borrowed_seat(0);
				sp->set_borrowed_number(sp->get_borrowed_number()-mp->get_howmany_seat());
			}
			if((mp->get_borrowed_studyroom() != 0) && (hh >= mp->get_studyroom_hh())){
				sp = space_p[mp->get_borrowed_studyroom()-1];
				mp->set_borrowed_studyroom(0);
				sp->set_borrowed_number(0);
			}
		}
	}
	else{
<<<<<<< HEAD
		for(i = 0; i < member_p.size(); i++){
			mp = member_p[i];
			mp->set_borrowed_studyroom(0);
			mp->set_borrowed_seat(0);
		}
		for(i = 0; i < SEAT; i++) space_p[i]->set_borrowed_number(0);
	}
}
