struct param {
	int arg1;
	int arg2;
};

struct param_operate {
	float num1;
	float num2;
	char *op;
};

program PROG {
	version VERS {
		string func0(void)   = 1;
		int    func1(string) = 2;
		int    func2(int)    = 3;
		int    func3(param)  = 4;
		param  func4(void)  = 5;
		float  operate(param_operate) = 6;
		void   myexit(void)  = 7;
	} = 1;
} = 0x30009999;
