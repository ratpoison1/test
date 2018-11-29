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
		int get_num_borrowed(){
			return list.size();
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

