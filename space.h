class space{
	protected:
	public:
};

class studyroom : public space{
	private:
		int room_number;
		int borrowed_number;
	public:
		studyroom(int n){
			room_number = n;
			borrowed_number = 0;
		}
		int get_borrowed_number(){
			return borrowed_number;
		}
		void set_borrowed_number(int n){
			borrowed_number = n;
		}
};

class seat : public space{
	private:
		int seat_number;
		int borrowed_number;
	public:
		seat(int n){
			seat_number = n;
			borrowed_number = 0;
		}
		int get_borrowed_number(){
			return borrowed_number();
		}
		void set_borrowed_number(int n){
			borrowed_number = n;
		}
};
