#pragma once

#include<iostream>
#include<stdio.h>
#include<string>
#include<fstream>
using namespace std;

namespace MyJson {

	struct Link;
	
	public  class Ivalue abstract {
		//если без итератора, то вводим метод getcur(возвращение текщего) , который
		//возвращает ivalue и методы next, back  (в обычной паре эти методы ничего не делают, а getcur возвращает нул,
		//а в списке они указатель на текщий элемент двигают)
	public:  // в json  если мы хоти идти вперед или назад то мы эти методы next , back вызываем у текущего ivalue. 
		//если я хочу сделать down, то получаю val и делаю его текущим, а предыдущий val помещаю в стек                                                                                    
		//можно добавить метод next, back(либо получаем ключ-значение,либо *Ivalue если это обычная пара,
		//  то возвращаем нуль и эти методы ничего не делают, а если это список ,
		// то они текущий элемент перемещают и его возвращают)
		// 
		//здесь надо избавиться от методов, которые возвращают ссылки на звено, 
		//потому что это нарушает инкапсуляцию. нужно сделать метод getIval (вроде бы)
		//virtual Link* get_head() = 0;//удали . лучше бы получать список ivalue. (ListValue)
		//если список возвращает пустой то ключ - строка, 
		//если список не пустой то это обьект  либо итератор.
		virtual int getType() = 0;
		virtual string getKey() = 0;
		//virtual Itervalue* itr() = 0; 
		virtual string getVal() = 0;
		virtual void set_key(string tmp) = 0;
		//можно было бы сделать еще setval(меняет строчку) и addval(добавляет значение в список)
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