struct param {
	int arg1;
	int arg2;
};

struct param_operate{
	double num1;
	double num2;
	char op;
}

program PROG {
	version VERS {
		string func0(void)   = 1;
		int    func1(string) = 2;
		int    func2(int)    = 3;
		int    func3(param)  = 4;
		param  func4(void)  = 5;
		void   myexit(void)  = 6;
		double  operate(param_operate) = 7;
	} = 1;
} = 0x30009999;
