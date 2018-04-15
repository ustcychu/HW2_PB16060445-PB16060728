
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stack>
#include<map>
#include<math.h>

using namespace std;
typedef struct ExpDetail {
	string expression;
	int prior;
}MyExp;

typedef struct fenshu {
	int fenzi;
	int fenmu;
}fenshu;

typedef struct fanhui {
	string express;
	string result;
}fanhui;
typedef struct canshu {
	int num_ques;
	int scalemax_op;
	int num_op;
	int num_float;
	int is_real;
	int is_decimal;
	int is_power;
	int is_add;
	int is_sub;
	int is_mul;
	int is_div;
	int result_max;
}canshu;
extern "C++" __declspec(dllexport) int Produce(canshu sample);
extern "C++" __declspec(dllexport) int jiexi(string can);
extern "C++" __declspec(dllexport) int JudgePrior(char operation);
extern "C++" __declspec(dllexport) bool Judgeoperation(char operation);
extern "C++" __declspec(dllexport)void AddBracket(string &exp);
extern "C++" __declspec(dllexport)void ExpTranslate(string Suffix_exp, string result);
extern "C++" __declspec(dllexport)int Operate(char op, int num1, int &num2);
extern "C++" __declspec(dllexport)string translate(int num);
extern "C++" __declspec(dllexport)int Generate_int();
extern "C++" __declspec(dllexport)double Operate_float(char op, double num1, double num2);
extern "C++" __declspec(dllexport)string translate_float(double num);
extern "C++" __declspec(dllexport)int Generate_float();
extern "C++" __declspec(dllexport)int GreatCommon(int fenzi, int fenmu);
extern "C++" __declspec(dllexport)void Simplify(fenshu &sample);
extern "C++" __declspec(dllexport)fenshu Add(fenshu a1, fenshu a2);
extern "C++" __declspec(dllexport)fenshu Sub(fenshu a1, fenshu a2);
extern "C++" __declspec(dllexport)fenshu chen(fenshu a1, fenshu a2);
extern "C++" __declspec(dllexport)fenshu chu(fenshu a1, fenshu a2);
extern "C++" __declspec(dllexport)fenshu Operate_fenshu(char op, fenshu num1, fenshu &num2);
extern "C++" __declspec(dllexport)string translate_fenshu(fenshu sample);
int Generate_fenshu();
char randsign();
