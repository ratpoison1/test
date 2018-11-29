#include "resource.h"
#include "member.h"
#include "input.h"
#include "space.h"
#include <string>
#include <sstream>
#include <fstream>
#define MAX 500
#define SEAT 3
#define STUDYROOM 10
using namespace std;

class library{
	private:
		int num_input;
		int num_book;
		int num_undergraduate;
		int studyroom_num;
		book* book_p[MAX];
		undergraduate* undergraduate_p[MAX];
		seat* seat_p[SEAT];
		studyroom* studyroom_p[STUDYROOM];
		string input_list[MAX];
	public:
		library();
		void init();
		void do_work();
		void refresh(string date, string past_date);
		book* find_book(string name);
		undergraduate* find_undergraduate(string name);
		void code_0(ofstream &fp, string resource_name, string member_name, char type, string date);
		void code_0_s(ofstream &fp, string space_type, string member_name, char type, string date, int time, int space_number, int number_of_member);
		void code_1(ofstream &fp);
		void code_2(ofstream &fp);
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
		void save_input();
		void save_space();
};

library :: library(){
	num_undergraduate = 0;
	num_book = 0;
	num_input = 0;
	studyroom_num = 0;
	init();
	save_input();
	save_space();
	sort_input();
	do_work();
	int i;
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
	book* b;
	seat* st;
	studyroom* sr;
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
			num_book++;
			i++;
		}
	}
	fp.close();

	for(i = 0; i < STUDYROOM; i++){
		sr = new studyroom(i);
		studyroom_p[i] = sr;
	}
	for(i = 0; i < SEAT; i++){
		st = new seat(i);
		seat_p[i] = st;
	}
}

void library :: save_input(){
	char temp[MAX];
	string tok;
	undergraduate* u;
	int i = 0;
	int j = 0;

	ifstream fpi("input.dat"); 
	fpi.getline(temp, MAX);
	while(1){
		fpi.getline(temp, MAX);
		if(fpi.eof()) break;
		else{
			input_list[i] = temp;
			num_input++;
			stringstream ss(temp);
			ss >> tok;
			ss >> tok;
			ss >> tok;
			ss >> tok;
			ss >> tok;
			ss >> tok;
			if(!find_undergraduate(tok)){
				u = new undergraduate(tok);
				undergraduate_p[j] = u;
				num_undergraduate++;
				j++;
			}
		}
		i++;
	}
	fpi.close();
}

void library :: save_space(){
	char temp[MAX];
	string tok;
	undergraduate* u;

	ifstream fpi("space.dat");
	fpi.getline(temp, MAX);
	while(1){
		fpi.getline(temp, MAX);
		if(fpi.eof()) break;
		else{
			input_list[num_input] = temp;
			num_input++;
			stringstream ss(temp);
			ss >> tok;
			ss >> tok;
			ss >> tok;
			ss >> tok;
			ss >> tok;
			ss >> tok;
			if(!find_undergraduate(tok)){
				u = new undergraduate(tok);
				undergraduate_p[num_undergraduate] = u;
				num_undergraduate++;
			}
		}
	}
	fpi.close();
}

void library :: sort_input(){
	int i;
	string tok1, tok2, temp;
	i = 0;
	while(1){
		stringstream ss(input_list[i]);
		ss >> tok1;
		i++;
		if(i == num_input) break;
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
	int hh;
	undergraduate* up;
	book* bp;
	seat* st;
	studyroom* sr;

	char operation;
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
	char space_number_char;
	char number_of_member_char;
	char time_char;
	int space_number;
	int number_of_member;
	int time;
	bool past_check = 0;

	string temp;
	string tok;
	ofstream outf("output.dat");
	outf << "Op_#\tReturn_code\tDescription" << endl;
	
	while(1){
		temp = input_list[i];
		i++;
		if(i == num_input + 1) break;
		else{
			outf << i << "\t";

			stringstream ss(temp);
			ss >> tok;
			date = tok;
			if(date[2] != '/'){ // space.dat cutting space_type, space_number
				ss >> tok;
				space_type = tok;
				ss >> tok;
				if(tok.length() == 1){
					space_number_char = tok[0];
					space_number = space_number_char-48;
				}
				else{
					space_number_string = tok;
					space_number = (space_number_string[0]-48)*10 + space_number_string[1]-48;
				}
				if(space_type == "StudyRoom")
					sr = studyroom_p[space_number-1];
				else
					st = seat_p[space_number-1];
			}
			// input.h cutting resource_type, resource_name //
			else{ 
				ss >> tok;
				resource_type = tok;
				ss >> tok;
				resource_name = tok;
				bp = find_book(resource_name);
			}
			ss >> tok;
			operation = tok[0];
			ss >> tok;
			member_type = tok;
			ss >> tok;
			member_name = tok;
			// end //

			// space.h cutting number_of_member, time //
			if(date[2] != '/' && operation == 'B'){
				ss >> tok;
				if(tok.length() == 1){
					number_of_member_char = tok[0];
					number_of_member = number_of_member_char-48;
				}
				else{
					number_of_member_string = tok;
					number_of_member = (number_of_member_string[0]-48)*10 + number_of_member_string[1]-48;
				}
				ss >> tok;
				if(tok.length() == 1){
					time_char = tok[0];
					time = time_char - 48;
				}
				else{
					time_string = tok;
					time = (time_string[0]-48)*10 + time_string[1]-48;
				}
			}
			// end //
			up = find_undergraduate(member_name);


			if(date[2] == '/'){
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
				}
				else cout << "wrong input, space_type : " << space_type << endl;
			}
			// end //
		}
		past_date = date;
		past_check = 1;
	}
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

void library :: code_0_s(ofstream &fp, string space_type, string member_name, char type, string date, int time, int space_number, int number_of_member){
	undergraduate* up;
	studyroom* sr;
	seat* st;
	int hh, hh_e;

	up = find_undergraduate(member_name);

	hh = (date[11]-48)*10 + date[12]-48;
	hh += time;
	hh_e = hh + 1;
	if(space_type == "StudyRoom") if(hh > 18) hh = 18;
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
		sr = studyroom_p[space_number-1];
			
		if(type == 'B'){
			up->set_borrowed_studyroom(space_number);
			up->set_studyroom_hh(hh);
			studyroom_num++;
		}	
		else if(type == 'R'){
			up->set_borrowed_studyroom(0);
			studyroom_num--;
		}
	}
	else if(space_type == "Seat"){
		st = seat_p[space_number-1];
	
		if(type == 'B'){
			up->set_borrowed_seat(space_number);
			up->set_seat_hh(hh);
			up->set_howmany_seat(number_of_member);
			st->set_borrowed_number(st->get_borrowed_number() + number_of_member);
		}	
		else if(type == 'R'){
			up->set_borrowed_seat(0);
			st->set_borrowed_number(st->get_borrowed_number() - number_of_member);
		}
		else if(type == 'E'){
			up->set_empty_hh(up->get_seat_hh());
			up->set_seat_hh(hh_e);
		}
		else if(type == 'C'){
			up->set_seat_hh(up->get_empty_hh());
		}
	}
	else fp << "code_0_s space_type error. space_type : " << space_type << endl;
	fp << "0\tSuccess." << endl;
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

	for(i = 0; i < num_undergraduate; i++){
		if(space_type == "StudyRoom" && undergraduate_p[i]->get_borrowed_studyroom() != 0)
			temp = undergraduate_p[i]->get_studyroom_hh();
		else if(space_type == "Seat" && undergraduate_p[i]->get_borrowed_seat() != 0)
			temp = undergraduate_p[i]->get_seat_hh();
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

void library :: refresh(string date, string past_date){
	int i;
	int hh;
	undergraduate* up;
	seat* st;
	studyroom* sr;
	hh = (date[11]-48)*10 + date[12]-48;
	if(get_sum(date) - get_sum(past_date) < 0.5){
		for(i = 0; i < num_undergraduate; i++){
			up = undergraduate_p[i];
			if((up->get_borrowed_seat() != 0) && (hh >= up->get_seat_hh())){
				st = seat_p[up->get_borrowed_seat()-1];
				up->set_borrowed_seat(0);
				st->set_borrowed_number(st->get_borrowed_number()-1);
			}
			if((up->get_borrowed_studyroom() != 0) && (hh >= up->get_studyroom_hh())){
				sr = studyroom_p[up->get_borrowed_studyroom()-up->get_howmany_seat()];
				up->set_borrowed_studyroom(0);
				studyroom_num--;
			}
		}
	}
	else{
		for(i = 0; i < num_undergraduate; i++){
			up = undergraduate_p[i];
			up->set_borrowed_studyroom(0);
			up->set_borrowed_seat(0);
		}
		for(i = 0; i < SEAT; i++) seat_p[i]->set_borrowed_number(0);
		studyroom_num = 0;
	}
}
