<<<<<<< HEAD
=======
#include "resource.h"
#include "member.h"
#include "input.h"
#include "space.h"
>>>>>>> --need--
#include <string>
#include <fstream>
<<<<<<< HEAD
#include <sstream>
#include <vector>
=======
#define SEAT 3
#define STUDYROOM 10
using namespace std;
>>>>>>> --need--

class library{
	private:
		int num_input;
		int num_book;
<<<<<<< HEAD
<<<<<<< HEAD
		int num_member;
		vector<book*> book_p;
		vector<member*> member_p;
=======
		string input_list[MAX];
>>>>>>> from "read and read input.dat" to "read once and save all data"
=======
		int num_empty;
		seat* seat_p[SEAT];
		studyroom* studyroom_p[STUDYROOM];
		string input_list[MAX];
		string empty_list[MAX];
>>>>>>> --need--
	public:
		library();
		void init();
		void do_work();
		void refresh(string date, string past_date, string space_type);
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
		void code_8();
		void code_9();
		void code_10();
		void code_11();
		void code_12();
		void code_13();
		void code_14();
		float get_sum(string date);
		void sort_input();
};

library :: library(){
<<<<<<< HEAD
	num_member = 0;
=======
	num_empty = 0;
>>>>>>> --need--
	init();
	sort_input();
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
<<<<<<< HEAD
	string temp;
	member* mp;
	book* bp;
=======
	seat* st;
	studyroom* sr;
>>>>>>> --need--
	int i = 0;
	string tok;
<<<<<<< HEAD
	string member_type;
=======
	num_input = 0;
>>>>>>> from "read and read input.dat" to "read once and save all data"

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
<<<<<<< HEAD
	ifstream fpi("input.dat"); // save input.dat
	getline(fpi, temp);
=======
>>>>>>> --need--
	while(1){
<<<<<<< HEAD
=======
		input_list[num_input] = temp;
		num_input++;
>>>>>>> from "read and read input.dat" to "read once and save all data"
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
<<<<<<< HEAD
	num_member = i;
=======
>>>>>>> from "read and read input.dat" to "read once and save all data"
	fpi.close();

	ifstream fpi2("space.dat"); // save space.dat
	getline(fpi2, temp);
	while(1){
		getline(fpi2, temp);
		input_list[num_input] = temp;
		num_input++;
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
	fpi2.close();
	num_undergraduate = i;

	for(i = 0; i < STUDYROOM; i++){
		sr = new studyroom(i);
		studyroom_p[i] = sr;
	}
	for(i = 0; i < SEAT; i++){
		st = new seat(i);
		seat_p[i] = st;
	}
}

void library :: do_work(){
	int i = 0;
	int delay;
	int yy, mm, dd, yy_d, mm_d, dd_d;
	member* mp;
	book* bp;
	seat* st;
	studyroom* sr;

	string operation;
	string resource_type;
	string resource_name;
	string member_type;
	string member_name;
	string date;
<<<<<<< HEAD
<<<<<<< HEAD
=======

	string space_type;
	string time_string;
	char space_number_char;
	char number_of_member_char;
	char time_char;
	int space_number;
	int number_of_member;
	int time;
	int past_date;

>>>>>>> --need--
	string temp;
	string tok;

	ifstream inf("input.dat");
	ofstream outf("output.dat");
	outf << "Op_#\tReturn_code\tDescription" << endl;


=======


>>>>>>> from "read and read input.dat" to "read once and save all data"
	while(1){
		temp = input_list[i];
		i++;
<<<<<<< HEAD
=======
		if(i == num_input) break;
>>>>>>> from "read and read input.dat" to "read once and save all data"
		else{
			outf << i << "\t";

			stringstream ss(temp);
			ss >> tok;
			date = tok;
			if(date[2] != '/'){
				ss >> tok;
				space_type = tok;
				ss >> tok;
				space_number_char = tok[0];
				space_number = space_number_char-48;
				if(space_type == "StudyRoom")
					sr = studyroom_p[space_number-1];
				else
					st = seat_p[space_number-1];
			}
			else{
				ss >> tok;
				resource_type = tok;
				ss >> tok;
				resource_name = tok;
				bp = find_book(resource_name);
			}
			ss >> tok;
			operation = tok;
			ss >> tok;
			member_type = tok;
			ss >> tok;
			member_name = tok;
<<<<<<< HEAD
	
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
=======

			if(date[2] != '/' && operation == 'B'){
				ss >> tok;
				number_of_member_char = tok[0];
				number_of_member = number_of_member_char-48;
				ss >> tok;
				if(tok.length() == 1){
					time_char = tok[0];
					time = time_char - 48;
				}
				else{
					time_string = tok;
					time = (time_string[0]-48)*10 + time_string[1]-48;
					if(space_type == "Seat" && member_type == "Undergraduate"){
						if(time > 3) time = 3;
					if(space_type == "Studyroom" && member_type == "Undergraduate"){
						if(time > 6) time = 6;
					}
				}
			}
			up = find_undergraduate(member_name);


			if(date[2] != '/'){
				if(operation == 'B'){
					if(!bp) code_1(outf);
					else if(up->get_borrowed()) code_2(outf);
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
					if(!up->get_borrowed()) code_3(outf);
					else if(up->get_borrowed_book() != resource_name) code_3(outf);
					else{
						delay = get_sum(date) - get_sum(up->get_deadline());
						if(delay > 0)	
							code_7(outf, resource_name, member_name, date, delay);
						else
							code_0(outf, resource_name, member_name, 'R', date);
					}
				}
			}
			else{
				refresh(date, past_date, space_type); // refresh	
				past_date = date;
				if(space_type == "StudyRoom"){
					if(operation == 'B'){
						if(space_number > STUDYROOM) code_8();
						else if(time < 9 || time > 18) code_9();
						else if(up->get_borrowed_studyroom() != 0) code_11();
						else if(number_of_member > 6) code_12();
						else if(time + 3 > 18) code_13();
						else if(sr->borrowed_number == 50) code_14();
						else code_0();
					}
					else if(operation == 'R'){
						if(space_number > STUDYROOM) code_8();
						else if(time < 9 || time > 18) code_9();
						else if(up->get_borrowed_studyroom() == 0) code_10();
						else code_0();	
					}
					else if(operation == 'E'){
						if(space_number > STUDYROOM) code_8();
						else if(time < 9 || time > 18) code_9();
						else if(up->get_borrowed_studyroom() == 0) code_10();
						else code_0();	
					}
					else{
						if(space_number > STUDYROOM) code_8();
						else if(time < 9 || time > 18) code_9();
						else if(up->get_borrowed_studyroom() == 0) code_10();
						else code_0();	
					}
				}
				if(space_type == "Seat"){
					if(operation == 'B'){
						if(space_number > STUDYROOM) code_8();
						else if(time < 9 || time > 18) code_9();
						else if(up->get_borrowed_seat() != 0) code_11();
						else if(number_of_member > 6) code_12();
						else if(time + 3 > 18) code_13();
						else if(sr->borrowed_number == 50) code_14();
						else code_0();
					}
					else if(operation == 'R'){
						if(space_number > STUDYROOM) code_8();
						else if(time < 9 || time > 18) code_9();
						else if(up->get_borrowed_studyroom() == 0) code_10();
						else code_0();	
					}
					else if(operation == 'E'){
						if(space_number > STUDYROOM) code_8();
						else if(time < 9 || time > 18) code_9();
						else if(up->get_borrowed_studyroom() == 0) code_10();
						else code_0();	
					}
					else{
						if(space_number > STUDYROOM) code_8();
						else if(time < 9 || time > 18) code_9();
						else if(up->get_borrowed_studyroom() == 0) code_10();
						else code_0();	
					}
>>>>>>> --need--
				}
			}
		}
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

float library :: get_sum(string date){
	int yy, mm, dd, hh;
	if(date[2] == '/'){
		yy = (date[0]-48)*10 + date[1]-48;
		mm = (date[3]-48)*10 + date[4]-48;
		dd = (date[6]-48)*10 + date[7]-48;
		return yy*360 + mm*12 + dd;
	}
	else{
		yy = (date[2]-48)*10 + date[3]-48;
		mm = (date[5]-48)*10 + date[6]-48;
		dd = (date[8]-48)*10 + date[9]-48;
		hh = (data[11]-48)*10 + date[12]-48;
		return yy*360 + mm*12 + dd + hh/100;
	}
}

<<<<<<< HEAD
	return yy*360 + mm*30 + dd;
=======
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
>>>>>>> --need--
}

void library :: refresh(string date_r, string past_date_r){
	int i, j;
	undergraduate* up;
	string date, past_date;
	for(i = 0; i < 8; i++) date[i] = date_r[i+2];
	for(i = 0; i < 8; i++) past_date[i] = past_date_r[i+2];

	if(date == past_date){
		for(i = 0; i < num_empty; i++){
			up = find_undergraduate(empty_list[i]);
			if(get_sum(date_r) > get_sum(up->get_empty_date())){
				up->set_borrowed_seat = 0;	
				for(j = 0; j < num_empty-1; j++){
					empty_list[j] = empty_list[j+1];
				}
				num_empty--;
			}
		}
	}
	else{
		num_empty = 0;
		for(i = 0; i < num_undergraduate; i++){
			up = undergraduate_p[i];
			up->borrowed_studyroom = 0;
			up->borrowed_seat = 0;
		}
		for(i = 0; i < SEAT; i++) seat_p[i]->borrowed_number = 0;
		for(i = 0; i < STUDYROOM; i++) studyroom_p[i]->borrowed_number = 0;
	}
}
