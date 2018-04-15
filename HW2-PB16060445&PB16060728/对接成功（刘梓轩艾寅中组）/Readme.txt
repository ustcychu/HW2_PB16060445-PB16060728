hw2-CoreDll
Core代码

作业

使用方法
头文件: DLL2.h

链接库:

x64: x64/Core.lib, x64/Core.dll// 暂不支持
x86: x86/Core.lib, x86/Core.dll
API

//生成参数的设置

bool set_range(int inf, int sup);
设置生成数字的大小	
inf:生成数字的下界，默认为1
sup:生成数字的上界，默认为20

bool set_len(int inf, int sup);
设置生成表达式的长度，整数/分数/小数/操作符的长度都算作1，如： 2+3*5/7 的长度为7
如需设置操作数的大小，只需按照操作数大小=（表达式长度+1）/2的方式来设置
	
inf:生成长度的下界，默认为5
sup:生成长度的上界，默认为9
如果希望生成单一长度的表达式，那么请将输入参数设为inf==sup=你要的值，如希望生成3个操作数的式子，那么请输入set_len(5,5);


bool set_mode(int symbol);
设置输出数字的模式：
symbol: 0为整数，1为分数（包括整数），2为小数

bool set_row(int row);
设置N_generate()函数中一次生成的式子数目，最大为100
row:取值范围1~100

bool set_operator(bool add, bool min, bool mul, bool div, bool power);
设置将要使用的操作符：其中所有的变量都为bool型，0为不使用，1为使用
add:支持加法
min:支持减法
mul:支持乘法
div:支持除法
power：支持乘方

bool set_PowerType(bool symbol);
设置乘方显示的方式
symbol:0为^,1为**

bool set_xi_disp(int symbol);
支持显示小数的精度，最低1位，最高10位
symbol：大小为1~10的整数

//end 生成参数的设置



//genenrate表达式

void N_generate();
设置生成的函数：一次生成多个表达式
如选用了读文件方式，则需先调用set_path()函数来设置，预设路径为：
式子的结果存在  "D://result.txt";
答案的结果存在 = "D://key.txt";
每一行存一个式子，一个答案，直接读取即可
如选用调用内存中式子的方式，请使用gtexp_i()函数，具体用法见该函数的注释
另：两种模式可同时使用，但不建议


bool set_Ngenapp(bool symbol);	
设置生成的式子是否会覆盖，针对使用内存读取式子的组，如果希望保存之前的式子，可以通过
设置symbol为1来保证之前的式子不会被覆盖，如果不用，请设为0
symbol：系统默认为0



void getexp(string &exps, string &keys);
一次生成一个表达式，返回式子串和结果（无需再处理，即可直接显示）

//end generate 表达式




//使用N_generate()后获取表达式和答案的方式

1、利用读写文件的方式
//设置部分

bool set_path(bool symbol, bool reset, string pathe, string pathk);
设置是否使用文件读取模式，其中：
第一个参数：symbol 控制是否支持 1为支持，0则不支持
第二个参数: reset  控制是否需要重新设置文件路径，其中0为不需要，1为需要
如果不需要，则后两个参数设为空串即可
第三个参数：pathe  设置表达式文件的存储路径
第四个参数：pathk  设置答案文件的存储路径
默认支持加减乘除

bool set_file_app(int app);
设置文件是否支持附加写
app为1，则新生成的式子不会覆盖之前的式子
app为0则会覆盖（默认值）




2、直接读取内存中存储的表达式和答案

void getexp_i(int index, string &exps, string &str_key);

其中i为下标范围：0~row（生成的式子总数-1），
exps为式子串
str_key为答案串

//end 使用N_generate()后获取表达式和答案的方式



另：
假如ui发现了什么bug或者需要什么别的设置可以告诉我们~