using namespace std;

class input{
	private:
		int yy;
		int mm;
		int dd;
		string resource_type;
		string resource_name;
		char operation;
		string member_type;
		string member_name;
	public:
		void set_yy(char a, char b){
			yy = (a-48)*10 + b-48;
		}
		void set_mm(char a, char b){
			mm = (a-48)*10 + b-48;
		}
		void set_dd(char a, char b){
			dd = (a-48)*10 + b-48;
		}
		void set_resource_type(string rt){
			resource_type = rt;
		}
		void set_resource_name(string rn){
			resource_name = rn;
		}
		void set_operation(string o){
			operation = o[0];
		}
		void set_member_type(string mt){
			member_type = mt;
		}
		void set_member_name(string mn){
			member_name = mn;
		}

		int get_yy(){
			return yy;
		}
		int get_mm(){
			return mm;
		}
		int get_dd(){
			return dd;
		}
		string get_resource_type(){
			return resource_type;
		}
		string get_resource_name(){
			return resource_name;
		}
		char get_operation(){
			return operation;
		}
		string get_member_type(){
			return member_type;
		}
		string get_member_name(){
			return member_name;
		}
};
