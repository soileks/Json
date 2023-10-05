#pragma once

#include<iostream>
#include<stdio.h>
#include<string>
#include<fstream>
using namespace std;

namespace MyJson {

	struct Link;
	
	public  class Ivalue abstract {
		//���� ��� ���������, �� ������ ����� getcur(����������� �������) , �������
		//���������� ivalue � ������ next, back  (� ������� ���� ��� ������ ������ �� ������, � getcur ���������� ���,
		//� � ������ ��� ��������� �� ������ ������� �������)
	public:  // � json  ���� �� ���� ���� ������ ��� ����� �� �� ��� ������ next , back �������� � �������� ivalue. 
		//���� � ���� ������� down, �� ������� val � ����� ��� �������, � ���������� val ������� � ����                                                                                    
		//����� �������� ����� next, back(���� �������� ����-��������,���� *Ivalue ���� ��� ������� ����,
		//  �� ���������� ���� � ��� ������ ������ �� ������, � ���� ��� ������ ,
		// �� ��� ������� ������� ���������� � ��� ����������)
		// 
		//����� ���� ���������� �� �������, ������� ���������� ������ �� �����, 
		//������ ��� ��� �������� ������������. ����� ������� ����� getIval (����� ��)
		//virtual Link* get_head() = 0;//����� . ����� �� �������� ������ ivalue. (ListValue)
		//���� ������ ���������� ������ �� ���� - ������, 
		//���� ������ �� ������ �� ��� ������  ���� ��������.
		virtual int getType() = 0;
		virtual string getKey() = 0;
		//virtual Itervalue* itr() = 0; 
		virtual string getVal() = 0;
		virtual void set_key(string tmp) = 0;
		//����� ���� �� ������� ��� setval(������ �������) � addval(��������� �������� � ������)
		virtual Ivalue* next(bool _f) = 0;
		virtual void back() = 0;
		virtual Ivalue* get_cur() = 0;
		//virtual void add_in_st(Ivalue* t) = 0;
		virtual void add_in_st(Link* t) = 0;
		virtual bool has_next() = 0;
		virtual void stock() = 0;
		//virtual void Next() = 0;
	};

	class ListValue;
	struct Link {

		ListValue* l;
		Ivalue* val;
		Link* next;
		//string Key;
		Link(Ivalue* _val = nullptr, Link* _next = nullptr) : val(_val), next(_next), l(nullptr)/*,Key("")*/ {}
		void setVal(Ivalue* _val) { val = _val; }
		string getVal() { return val->getVal(); }
		bool empty() {
			if (val == nullptr)
				return false;
			else return true;
		}
		int getType() {
			return val->getType();
		}
		/*void refresh() {


			if (val->getType() == 2)
				*l = *val;
		}*/
		/*string getKey() {
			return Key;
		}*/

	};
}