 #include <vector>

class member{
	protected:
		int loan_period;
		int num_limit;
		int cap_limit;
		string name;
		string restricted_date;
		vector<string> deadline;
		vector<string> deadline_e;
		vector<string> borrowed_date;
		vector<string> borrowed_date_e;
		vector<string> list;
		vector<string> list_e;
		vector<int> size_e;
		int borrowed_studyroom;
		int borrowed_seat;
		int studyroom_hh;
		int seat_hh;
		int empty_hh;
		int cap;
	public:
		string get_name(){
			return name;
		}
		int get_loan_period(){
			return loan_period;
		}
		int get_num_limit(){
			return num_limit;
		}
		bool check_book(string s){
			int i;
			for(i = 0; i < list.size(); i++){
				if(list[i] == s) return 1;
			}
			return 0;
		}
		bool check_book_e(string s){
			int i;
			for(i = 0; i < list_e.size(); i++){
				if(list_e[i] == s) return 1;
			}
			return 0;
		}
		int get_borrowed_studyroom(){
			return borrowed_studyroom;
		}
		int get_borrowed_seat(){
			return borrowed_seat;
		}
		int get_empty_hh(){
			return empty_hh;
		}
		int get_studyroom_hh(){
			return studyroom_hh;
		}
		int get_seat_hh(){
			return seat_hh;
		}
		int get_num_borrowed(){
			return list.size();
		}
		int get_cap_limit(){
			return cap_limit;
		}
		int get_cap(){
			return cap;
		}
		string get_deadline_i(int i){
			return deadline[i];
		}
		string get_restricted_date(){
			return restricted_date;
		}
		string get_deadline(string resource_name){
			int i;
			for(i = 0; i < list.size(); i++){
				if(list[i] == resource_name)
					return deadline[i];
			}
			return "//";
		}
		string get_borrowed_date(string s){
			int i;
			for(i = 0; i < list.size(); i++){
				if(list[i] == s) return borrowed_date[i];	
			}
		}
		string get_borrowed_date_e(string s){
			int i;
			for(i = 0; i < list_e.size(); i++){
				if(list_e[i] == s) return borrowed_date_e[i];	
			}
		}
		void refresh_e(int date){
			int i, dead;
			int yy, mm, dd;
			for(i = 0; i < list_e.size(); i++){
				yy = (deadline_e[i][0]-48)*10 + deadline_e[i][1]-48;
				mm = (deadline_e[i][3]-48)*10 + deadline_e[i][4]-48;
				dd = (deadline_e[i][6]-48)*10 + deadline_e[i][7]-48;
				dead = yy*360 + mm*30 + dd;
				if(date >= dead){
					del_list(list_e[i], size_e[i]); 
				}
			}
		}
		void set_empty_hh(int n){
			empty_hh = n;
		}
		void set_seat_hh(int n){
			seat_hh = n;
		}
		void set_studyroom_hh(int n){
			studyroom_hh = n;
		}
		void set_borrowed_studyroom(int n){
			borrowed_studyroom = n;
		}
		void set_borrowed_seat(int n){
			borrowed_seat = n;
		}
		void set_restricted_date(string s){
			restricted_date = s;
		}
		void add_list(string resource_name, string dl, int size, string date){
			if(size == 0){
				list.push_back(resource_name);
				deadline.push_back(dl);
				borrowed_date.push_back(date);
			}
			else{
				list_e.push_back(resource_name);
				size_e.push_back(size);
				deadline_e.push_back(dl);
				borrowed_date_e.push_back(date);
				cap += size;
			}
		}
		void del_list(string s, int size){
			int i;
			if(size == 0){
				for(i = 0; i < list.size(); i++){
					if(list[i] == s){
						list.erase(list.begin() + i);
						deadline.erase(deadline.begin() + i);
						borrowed_date.erase(borrowed_date.begin() + i);
						return;
					}
				}
			}
			else{
				for(i = 0; i < list_e.size(); i++){
					if(list_e[i] == s){
						list_e.erase(list_e.begin() + i);
						size_e.erase(size_e.begin() + i);
						deadline_e.erase(deadline_e.begin() + i);
						borrowed_date_e.erase(borrowed_date_e.begin() + i);
						cap -= size;
						return;
					}
				}
			}
			cout << "del_list error : there is no book in the list" << endl;
		}
};

class undergraduate : public member{
	private:
	public:
		undergraduate(string n){
			name = n;
			loan_period = 14;
			num_limit = 1;
			restricted_date = "000000";
			borrowed_studyroom = 0;
			borrowed_seat = 0;
			cap = 0;
			cap_limit = 100;
			seat_hh = 24;
			studyroom_hh = 24;
			empty_hh = 24;
		}
};

class graduate : public member{
	public:
		graduate(string n){
			name = n;
			loan_period = 30;
			num_limit = 5;
			restricted_date = "000000";
			borrowed_studyroom = 0;
			borrowed_seat = 0;
			cap = 0;
			cap_limit = 500;
			seat_hh = 24;
			studyroom_hh = 24;
			empty_hh = 24;
		}
};
class faculty : public member{
	public:
		faculty(string n){
			name = n;
			loan_period = 30;
			num_limit = 10;
			restricted_date = "000000";
			borrowed_studyroom = 0;
			borrowed_seat = 0;
			cap = 0;
			cap_limit = 1000;
			seat_hh = 24;
			studyroom_hh = 24;
			empty_hh = 24;
		}
};

