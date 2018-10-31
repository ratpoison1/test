class member{
	protected:
		string name;
};

class undergraduate : public member{
	private:
	public:
		string get_name(){
			return name;
		}
};
