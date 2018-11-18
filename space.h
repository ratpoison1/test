class space{
	protected:
	public:
};

class studyroom : public space{
	private:
		int room_number;
		string who_borrowed;
	public:
		studyroom(int n){
			room_number = n;
		}
		string get_who_borrowed(){
			return who_borrowed;
		}
		void set_who_borrowed(string who){
			who_borrowed = who;
		}
};

class seat : public space{
	private:
		int floor;
		int seat_number;
		string who_borrowed;
	public:
		seat(int n, int m){
			floor = n;
			seat_number = m;
		}
		string get_who_borrowed(){
			return who_borrowed;
		}
		void set_who_borrowed(string who){
			who_borrowed = who;
		}
};
