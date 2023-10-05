#pragma once
#include"Ivalue.h"

using namespace std;

namespace MyJson {
	struct Link;
	public class Value :public Ivalue {
		string key;  //если сделать класс ссылок, то это должны быть ссылки на строчки?
		string val;
	public:

		Value(string _key = "", string _val = "") {
			key = _key;
			val = _val;
		}
		//Link* get_head() {
		//	//Value* v;
		//	//Link* tmp;
		//	return nullptr;
		//}
		void stock(){}
		bool has_next() {
			return false;
		}

		string getKey() {
			return key;
		}
		int getType() {
			return 1;
		}
		string getVal() {
			return val;
		}
		void set_key(string _tmp) {
			this->key = _tmp;
		}
		void set_val(string _val) {
			this->val = _val;
		}
		Ivalue* next(bool _f) {
			return nullptr;
		}
		void back() {
			//return nullptr;
		}
		void add_in_st(Link* t) {
		}
		/*void add_in_st(Ivalue* y) {
		}*/
		Ivalue* get_cur() {
			return nullptr;
		}
		//void Next() {
		//	//this.
		//}
		/*  Itervalue* itr() {

		  }*/
	};




}