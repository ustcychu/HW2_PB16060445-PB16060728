#pragma once
#include <math.h>
#include <cstdlib>
#include <ctime>

#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

__declspec(dllexport)	bool set_len(int inf, int sup);
__declspec(dllexport)	bool set_mode(int symbol);
__declspec(dllexport)	bool set_range(int inf, int sup);
__declspec(dllexport)	bool set_row(int row);
__declspec(dllexport)	bool set_operator(bool add, bool min, bool mul, bool div, bool power);
__declspec(dllexport)	bool set_file_app(int app);
__declspec(dllexport)	bool set_path(bool symbol, bool reset, string pathe, string pathk);
__declspec(dllexport)	bool set_Ngenapp(bool symbol);
__declspec(dllexport)	bool set_PowerType(bool symbol);
__declspec(dllexport)	bool set_xi_disp(int symbol);
__declspec(dllexport)	void N_generate();
__declspec(dllexport)	void getexp(string &exps, string &keys);
__declspec(dllexport)	void getexp_i(int index, string &exps, string &str_key);
