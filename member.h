class member{
	protected:
		int loan_period;
		int num_limit;
		string name;
		string restricted_date;
		vector<string> deadline;
		string borrowed_date;
		vector<string> list;
		int borrowed_studyroom;
		int borrowed_seat;
		int studyroom_hh;
		int seat_hh;
		int empty_hh;
		int howmany_seat;
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
		int get_howmany_seat(){
			return howmany_seat;
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
		void set_empty_date(string s){
			empty_date = s;
		void set_howmany_seat(int n){
			howmany_seat = n;
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
		void set_borrowed(bool n){
			borrowed = n;
		}
		void set_restricted(bool n){
			restricted = n;
		}
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
	private:
	public:
		undergraduate(string n){
			name = n;
			borrowed = 0;
			borrowed_studyroom = 0;
			borrowed_seat = 0;
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

