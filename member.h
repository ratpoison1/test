class member{
	protected:
		int loan_period;
		int num_limit;
		string name;
		string restricted_date;
		vector<string> deadline;
		string borrowed_date;
		vector<string> list;
	public:
		string get_name(){
			return name;
		}
<<<<<<< HEAD
		int get_loan_period(){
			return loan_period;
=======
};

class undergraduate : public member{
	private:
		bool borrowed;
		int borrowed_studyroom;
		int borrowed_seat;
		bool restricted;
		string restricted_date;
		string borrowed_book;
		string deadline;
		string borrowed_date;
		string empty_date;
	public:
		undergraduate(string n){
			name = n;
			borrowed = 0;
			borrowed_studyroom = 0;
			borrowed_seat = 0;
>>>>>>> --need--
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
		int get_borrowed_studyroom(){
			return borrowed_studyroom;
		}
		int get_borrowed_seat(){
			return borrowed_seat;
		}
		string get_empty_date(){
			return empty_date;
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
		string get_borrowed_date(){
			return borrowed_date;	
		}

<<<<<<< HEAD
=======
		void set_empty_date(string s){
			empty_date = s;
		}
		void set_borrowed_studyroom(int n){
			borrowed_studyroom = n;
		}
		void set_borrowed_seat(int n){
			borrowed_seat = n;
		}
		void set_borrowed(bool n){
			borrowed = n;
		}
		void set_restricted(bool n){
			restricted = n;
		}
>>>>>>> --need--
		void set_restricted_date(string s){
			restricted_date = s;
		}
		void set_borrowed_date(string s){
			borrowed_date = s;
		}
		void add_list(string resource_name, string dl){
			list.push_back(resource_name);
			deadline.push_back(dl);
		}
		void del_list(string s){
			int i;
			for(i = 0; i < list.size(); i++){
				if(list[i] == s){
					list.erase(list.begin() + i);
					deadline.erase(deadline.begin() + i);
					return;
				}
			}
			cout << "del_list error : there is no book in the list" << endl;
		}
};

class undergraduate : public member{
	public:
		undergraduate(string n){
			name = n;
			loan_period = 14;
			num_limit = 1;
			restricted_date = "000000";
		}
};
class graduate : public member{
	public:
		graduate(string n){
			name = n;
			loan_period = 30;
			num_limit = 5;
			restricted_date = "000000";
		}
};
class faculty : public member{
	public:
		faculty(string n){
			name = n;
			loan_period = 30;
			num_limit = 10;
			restricted_date = "000000";
		}
};

