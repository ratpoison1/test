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
		int studyroom_hh;
		int seat_hh;
		int empty_hh;
		int howmany_seat;
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
		string get_borrowed_book(){
			return borrowed_book;
		}
		string get_deadline(){
			return deadline;
		}
		string get_borrowed_date(){
			return borrowed_date;	
		}

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
