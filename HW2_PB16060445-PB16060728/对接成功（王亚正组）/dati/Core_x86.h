#pragma once
__declspec(dllexport) typedef struct  Parameter
{
	//�ýṹ�����������û�Ҫ��Ĳ���������Setting�����������ɶ�ӦҪ�����Ŀ
    int integer = 1;  //֧�� ���� ������Ϊ1����֧����Ϊ0��Ĭ��Ϊ֧��
	int decimal = 0;  //֧�� С�� ������Ϊ1����֧����Ϊ0��Ĭ��Ϊ��֧��
	int fraction = 0; //֧�� ���� ������Ϊ1����֧����Ϊ0��Ĭ��Ϊ��֧��
	int add = 1;      //֧�� �ӷ� ����������Ϊ1����֧����Ϊ0��Ĭ��Ϊ֧��
	int sub = 1;      //֧�� ���� ����������Ϊ1����֧����Ϊ0��Ĭ��Ϊ֧��
	int multiply = 1; //֧�� �˷� ����������Ϊ1����֧����Ϊ0��Ĭ��Ϊ֧��
	int division = 1; //֧�� ���� ����������Ϊ1����֧����Ϊ0��Ĭ��Ϊ֧��
	int pow = 0;      //֧�� �˷� ����������Ϊ1����֧����Ϊ0��Ĭ��Ϊ��֧��
	int bracktet = 1; //֧�� ���� ����������Ϊ1����֧����Ϊ0��Ĭ��Ϊ֧��

}Parameter;

__declspec(dllexport) int Setting_Parameter(int question_num, int sup,Parameter argument);
//   �ú��������û��趨����
//   question_num  ��Ӧ���ɵ���Ŀ������>0��
//   sup ��Ӧ���ɵ������Ͻ磨>=1��
//   argument ��Ӧ�����ṹ��

__declspec(dllexport) int Generate(int setting_error);
//   ���ɶ�ӦҪ�����Ŀ
//   ��Ŀ����result.txt �𰸴���key.txt