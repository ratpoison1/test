class member{
	protected:
		string name;
	public:
		string get_name(){
			return name;
		}
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
		}
		bool get_borrowed(){
			return borrowed;
		}
		bool get_restricted(){
			return restricted;
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
		string get_borrowed_book(){
			return borrowed_book;
		}
		string get_deadline(){
			return deadline;
		}
		string get_borrowed_date(){
			return borrowed_date;	
		}

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
		void set_restricted_date(string s){
			restricted_date = s;
		}
		void set_borrowed_book(string s){
			borrowed_book = s;
		}
		void set_deadline(string s){
			deadline = s;
		}
		void set_borrowed_date(string s){
			borrowed_date = s;
		}
};
