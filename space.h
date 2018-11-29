class space{
	protected:
<<<<<<< HEAD
		int number;
		int borrowed_number;
		int limit;
	public:
		int get_borrowed_number(){
			return borrowed_number;
		}
		void set_borrowed_number(int n){
			borrowed_number = n;
		}
};

class studyroom : public space{
	private:
<<<<<<< HEAD
	public:
		studyroom(int n){
			number = n;
			borrowed_number = 0;
			limit = 6;
		}
};

class seat : public space{
	private:
<<<<<<< HEAD
	public:
		seat(int n){
			number = n;
			borrowed_number = 0;
			limit = 50;
		}
};
