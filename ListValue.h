#pragma once
//#include"Ivalue.h"
#include"Value.h"
using namespace std;

namespace MyJson {
	class Json;
	struct Link;

	public  class ListValue :public Ivalue {
		//можно добавить текущее звено
		Link* cur_link;//текущее звено
		Link* head;
		Link* end;
		string key;
		ListValue* lval; // для внутренних списков
		stack<Link*>ST;
		stack<Ivalue*>Ist;
		string value;
		//bool exist_next;
	public:
		/*ListValue(Link* _head = nullptr,Link* _end=nullptr,string _key=" ") {
			head = _head;
			end = _end;
			key = _key;
		}*/
		ListValue() {
			//exist_next = true;
			lval = nullptr;
			head = new Link();
			end = head;
			key = "";
			cur_link = head;
		}
		ListValue(std::string _key, std::string _value) : key(_key), value(_value) {};
		//Itervalue* itr() {
		//	
		//}
		//
		/*private Link* gethead() {
			return
		}*/
		bool has_next() {
			if (cur_link->next != nullptr)
				return true;
			else return false;
		}
		Ivalue* next(bool _f) {
			if (_f == true)
				ST.push(cur_link);
			if (cur_link->next == nullptr) {
				//cout << "next is nullptr" << endl;
				return nullptr;
			}
			cur_link = cur_link->next;
			return cur_link->val;
		}
		void add_in_st(Link* t) {
			ST.push(t);
		}
		/*void add_in_st(Ivalue* y) {
			Ist.push(y);
		}*/
		void back() {

		}
		/*Ivalue * down(Link* _tmp) {
			Link* b;
			if (_tmp->getType() == 2) {
				b=_tmp->val.

			}
				return 
		}*/
		/*Ivalue* back() {
			Link* tmp = ST.top();
			ST.pop();
			cur_link = tmp;
			return tmp->val;
		}*/
		Ivalue* get_cur() {
			return cur_link->val;
		}
		/*Link* get_end() {
			return this->end;
		}*/
		ListValue* getLast() {// текущий список список
			return lval;
		}
		/* Link* get_head()  {
			return this->head;
		}*/
		int getType() {
			return 2;
		}
		string getKey() {
			return key;
		}
		string getVal() {
			return lval->getKey();
		}
		void set_key(string _tmp) {
			this->key = _tmp;
		}
		void stock() {
			cur_link = head;
		}
		friend ostream& operator <<(ostream& out, ListValue& obj) {//вроде должно работать, но не точно
			Link* curr = obj.head;
			while (curr != nullptr) {
				out << "\"" << curr->val->getKey() << "\"" << ":" << " ";
				if (curr->val->getType() == 1) {
					out << "\"" << curr->val->getVal() << "\"" << endl;
					curr = curr->next;
				}
				else if (curr->val->getType() == 2) {
					cout << "{" << endl;
					out << curr->val << endl;
					cout << "}" << endl;
				}
			}
			return out;
		}
		void MoveNext() {
			this->cur_link = cur_link->next;
			/*if (cur_link == nullptr) {
				Link* newL = new Link();
				end = newL;
			}*/
		}
		void addList(string _key = "") {

			string tmp;
			//end->l = lval;


			//if (lval != nullptr)// {
			//	if (lval->end->val->getKey() == "")
			//	{//lval->end->val.
			//		lval->end->val->set_key(tmp);
			//		//tmp = key;
			//		//end->l = lval;//
			//	}


			/* }
			else {*/
			tmp = _key;

			lval = new ListValue();
			//if(end->l!=nullptr)
			//end->l = lval;
			//lval->head->Key = _key;
			lval->key = _key; //ключ внутреннего списка
			//lval->head->val.
			//end->l = lval;
			//lval->end->val->getKey() = _key; //ключ звена
			if (end->empty()) {


				Link* t = new Link(lval, nullptr);
				
				if (end->l == nullptr)
					end->l = lval;
				end->next = t;
				end = t;
				end->l = lval;
			}
			else {
				end->l = lval;
				end->val = lval;
			}
			//}
			//if (end->l == nullptr)
			//end->l = lval;
			cur_link = lval->head;

		}
		ListValue* existList() {
			return cur_link->l;
		}
		void addVal(string _key, string _val) {
			Link* t;
			Value* val = new Value;
			val->set_key(_key);
			val->set_val(_val);
			if (head->val == nullptr) {
				head->val = val;
				//t = new Link(&val,nullptr);
				//head = t;
				//end = t;
			}
			else {
				t = new Link(val, nullptr);
				cur_link = t;
				end->next = t;
				end = t;
			}



		}
		friend class Json;
	};


}