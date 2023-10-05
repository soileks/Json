#pragma once
//#include<iostream>
//#include<stdio.h>
//#include<string>
#include<stack>
#include<fstream>
//#include"Ivalue.h"
//#include"Ivalue.h"
//#include"Value.h"
#include"ListValue.h"
#include <msclr/marshal_cppstd.h>

using namespace std;
namespace MyJson {
	struct Link;
	//class Itervalue {
		//	Link* t;
		//	Link* head;
		//
		//public:
		//	Itervalue(Link* head) {
		//		this->head = head;
		//		t = head/*->next*/;
		//	}
		//	bool hasNext() { return t != nullptr; }
		//	Ivalue* next() {
		//		if (t == nullptr) {
		//			throw -2;
		//			
		//		}
		//       Ivalue* val = t->val;
		//	   t = t->next;
		//	   return val;
			//}

	//};

	//public  class Ivalue abstract {
	//	//если без итератора, то вводим метод getcur(возвращение текщего) , который
	//	//возвращает ivalue и методы next, back  (в обычной паре эти методы ничего не делают, а getcur возвращает нул,
	//	//а в списке они указатель на текщий элемент двигают)
	//public:  // в json  если мы хоти идти вперед или назад то мы эти методы next , back вызываем у текущего ivalue. 
	//	//если я хочу сделать down, то получаю val и делаю его текущим, а предыдущий val помещаю в стек                                                                                    
	//	//можно добавить метод next, back(либо получаем ключ-значение,либо *Ivalue если это обычная пара,
	//	//  то возвращаем нуль и эти методы ничего не делают, а если это список ,
	//	// то они текущий элемент перемещают и его возвращают)
	//	// 
	//	//здесь надо избавиться от методов, которые возвращают ссылки на звено, 
	//	//потому что это нарушает инкапсуляцию. нужно сделать метод getIval (вроде бы)
	//	//virtual Link* get_head() = 0;//удали . лучше бы получать список ivalue. (ListValue)
	//	//если список возвращает пустой то ключ - строка, 
	//	//если список не пустой то это обьект  либо итератор.
	//	virtual int getType() = 0;
	//	virtual string getKey() = 0;
	//	//virtual Itervalue* itr() = 0; 
	//	virtual string getVal() = 0;
	//	virtual void set_key(string tmp) = 0;
	//	//можно было бы сделать еще setval(меняет строчку) и addval(добавляет значение в список)
	//	virtual Ivalue* next(bool _f) = 0;
	//	virtual void back() = 0;
	//	virtual Ivalue* get_cur() = 0;
	//	virtual void add_in_st(Link* t) = 0;
	//	virtual bool has_next() = 0;
	//};
	//public class Value :public Ivalue {
	//	string key;  //если сделать класс ссылок, то это должны быть ссылки на строчки?
	//	string val;
	//public:

	//	Value(string _key = "", string _val = "") {
	//		key = _key;
	//		val = _val;
	//	}
	//	//Link* get_head() {
	//	//	//Value* v;
	//	//	//Link* tmp;
	//	//	return nullptr;
	//	//}
	//	bool has_next() {
	//		return false;
	//	}

	//	string getKey() {
	//		return key;
	//	}
	//	int getType() {
	//		return 1;
	//	}
	//	string getVal() {
	//		return val;
	//	}
	//	void set_key(string _tmp) {
	//		this->key = _tmp;
	//	}
	//	void set_val(string _val) {
	//		this->val = _val;
	//	}
	//	Ivalue* next(bool _f) {
	//		return nullptr;
	//	}
	//	void back() {
	//		//return nullptr;
	//	}
	//	void add_in_st(Link* t){
	//	}
	//	Ivalue* get_cur() {
	//		return nullptr;
	//	}
	//	/*  Itervalue* itr() {

	//	  }*/
	//};

	//struct Link {
	//	Link* next;
	//	Ivalue* val;
	//	Link(string _key = "", string _val = "") {
	//		/*if ((val == nullptr) && (_val == ""))
	//			val = new ListValue();
	//		else if ((val == nullptr) && (_val != ""))
	//			val = new Value();*/
	//		val->getVal() = _val;
	//		val->getKey() = _key;
	//		next =nullptr;
	//	}
	//
	//};

	
	//class ListValue;
	//struct Link {
	//	ListValue* l;
	//	Ivalue* val;
	//	Link* next;
	//	//string Key;
	//	Link(Ivalue* _val = nullptr, Link* _next = nullptr) : val(_val), next(_next), l(nullptr)/*,Key("")*/ {}
	//	void setVal(Ivalue* _val) { val = _val; }
	//	string getVal() { return val->getVal(); }
	//	bool empty() {
	//		if (val == nullptr)
	//			return false;
	//		else return true;
	//	}
	//	int getType() {
	//		return val->getType();
	//	}
	//	/*void refresh() {
	//		
	//		
	//		if (val->getType() == 2)
	//			*l = *val;
	//	}*/
	//	/*string getKey() {
	//		return Key;
	//	}*/

	//};
	//class Json;

	//public  class ListValue :public Ivalue {
	//	//можно добавить текущее звено
	//	Link* cur_link;//текущее звено
	//	Link* head;
	//	Link* end;
	//	string key;
	//	ListValue* lval; // для внутренних списков
	//	stack<Link*>ST;
	//	string value;
	//	//bool exist_next;
	//public:
	//	/*ListValue(Link* _head = nullptr,Link* _end=nullptr,string _key=" ") {
	//		head = _head;
	//		end = _end;
	//		key = _key;
	//	}*/
	//	ListValue() {
	//		//exist_next = true;
	//		lval = nullptr;
	//		head = new Link();
	//		end = head;
	//		key = "";
	//		cur_link = head;
	//	}
	//	ListValue(std::string _key, std::string _value) : key(_key), value(_value) {};
	//	//Itervalue* itr() {
	//	//	
	//	//}
	//	//
	//	/*private Link* gethead() {
	//		return 
	//	}*/
	//	bool has_next() {
	//		if (cur_link->next != nullptr)
	//			return true;
	//		else return false;
	//	}
	//	Ivalue* next(bool _f) {
	//		if (_f == true)
	//			ST.push(cur_link);
	//		if (cur_link->next == nullptr) {
	//			//cout << "next is nullptr" << endl;
	//			return nullptr;
	//		}
	//		cur_link = cur_link->next;
	//		return cur_link->val;
	//	}
	//	void add_in_st(Link* t) {
	//		ST.push(t);
	//	}
	//	void back() {
	//	
	//	}
	//	/*Ivalue* back() {
	//		Link* tmp = ST.top();
	//		ST.pop();
	//		cur_link = tmp;
	//		return tmp->val;
	//	}*/
	//	Ivalue* get_cur() {
	//		return cur_link->val;
	//	}
	//	/*Link* get_end() {
	//		return this->end;
	//	}*/
	//	ListValue* getLast() {// текущий список список
	//		return lval;
	//	}
	//	/* Link* get_head()  {
	//		return this->head;
	//	}*/
	//	int getType() {
	//		return 2;
	//	}
	//	string getKey() {
	//		return key;
	//	}
	//	string getVal() {
	//		return lval->getKey();
	//	}
	//	void set_key(string _tmp) {
	//		this->key = _tmp;
	//	}
	//	void stock() {
	//		cur_link = head;
	//	}
	//	friend ostream& operator <<(ostream& out, ListValue& obj) {//вроде должно работать, но не точно
	//		Link* curr = obj.head;
	//		while (curr != nullptr) {
	//			out << "\"" << curr->val->getKey() << "\"" << ":" << " ";
	//			if (curr->val->getType() == 1) {
	//				out << "\"" << curr->val->getVal() << "\"" << endl;
	//				curr = curr->next;
	//			}
	//			else if (curr->val->getType() == 2) {
	//				cout << "{" << endl;
	//				out << curr->val << endl;
	//				cout << "}" << endl;
	//			}
	//		}
	//		return out;
	//	}
	//	void addList(string _key = "") {
	//		string tmp;
	//		//end->l = lval;
	//		if (lval != nullptr)
	//			if (lval->end->val->getKey() == "")
	//			{//lval->end->val.
	//				lval->end->val->set_key(tmp);
	//				//end->l = lval;//
	//			}
	//		tmp = _key;
	//		lval = new ListValue();
	//		//if(end->l!=nullptr)
	//		//end->l = lval;
	//		//lval->head->Key = _key;
	//		lval->key = _key; //ключ внутреннего списка
	//		//lval->head->val.
	//		//end->l = lval;
	//		//lval->end->val->getKey() = _key; //ключ звена
	//		if (end->empty()) {
	//			Link* t = new Link(lval, nullptr);
	//			if (end->l == nullptr)
	//				end->l = lval;
	//			end->next = t;
	//			end = t;
	//			end->l = lval;
	//		}
	//		else {
	//			//end->l = lval;
	//			end->val = lval;
	//		}
	//		//if (end->l == nullptr)
	//		//end->l = lval;
	//		cur_link = lval->head;
	//	}
	//	ListValue* existList() {
	//		return cur_link->l;
	//	}
	//	void addVal(string _key, string _val) {
	//		Link* t;
	//		Value* val = new Value;
	//		val->set_key(_key);
	//		val->set_val(_val);
	//		if (head->val == nullptr) {
	//			head->val = val;
	//			//t = new Link(&val,nullptr);
	//			//head = t;
	//			//end = t;
	//		}
	//		else {
	//			t = new Link(val, nullptr);
	//			cur_link = t;
	//			end->next = t;
	//			end = t;
	//		}



	//	}
	//	friend class Json;
	//};
	//дерево заполняем вручную, распечатываем,после этого берем конкретный джейсон и пытаемся писать для него парсер. 
	// Потом добавлям навигацию.
	//можно обьединить в один класс . 3 поля - ключ типа строка, строка(значение) и указатель на список Ivalue.
	// если указатель на список нулевой, то смотреть на строку то есть это значение
	// если указатель ненулевой то внутри список
	//
	//class  :public Ivalue {
	//	string key;
	//	string val;
	//	ListValue* root;
	//
	//};
class ListValue;
class Value;

	public  class Json {
		//Link* t;//указатель на текущий элемент
		//stack<Link*> st;//для возвращения назад (по идее надо списки, а не линки, 
		//но нужен еще указатель на текущий элемент(*Link)(это если без итератора)  + методы вперед, назад и метод,
		//который позволяет получить текущее значение(он возвращает ivalue))
		ListValue* root;
		ListValue* curL;
		string keys;
		stack <ListValue*> Stack;
		//stack <Link*> heap;
		//stack <Ivalue*> heap;//просто собираю все ival
		Link* cur; //для перемещения по звеньям
		//Link* Head;
		Link* tmp;
		Ivalue* temp;
		stack <Ivalue*> stIv;
		stack <ListValue*> s;
	public:
		Json() {
			root = new ListValue();
			cur = root->head;
			curL = root;
			keys = "root";
			tmp = root->head;
			temp = root;
			//	Head= root->head;
				//End = root->end;
		}
		void load(string filename) {

			ifstream file1(filename);
			file1 >> *this;
			cout << endl;

		};
		void save(string filename) {

		};
		Ivalue* next() {
			return root->next(true);

			/*
			if (cur == nullptr) {
				cur = root->get_head();
				st.push(cur);
			}
			else {
				if (cur != nullptr) {
					cur = cur->next;
					st.push(cur);
				}
			}*/

		};
		void next_for_netJS() {
			/*if (temp != nullptr) {

			}*/
			if (temp != nullptr)
				if(temp->has_next()){
				//if (tmp->next != nullptr) {
					this->temp->add_in_st(tmp);
					tmp = tmp->next;
					//temp=temp.
					keys = tmp->val->getKey();
				}
		}
		void add_in_start(string _key,string _val) {
			Value* tm = new Value(_key, _val);
			Link* n = curL->head;
			Link* t = new Link(tm,n);
			curL->head = t;
			keys = _key;
			this->temp->add_in_st(tmp);
			tmp = t;
			//curL->head->val.

		}
		void add_after(string _key, string _val){
			Value* tm = new Value(_key, _val);
			Link* tNext = tmp->next;
			Link* t = new Link(tm, tNext);
			if (tmp->next == nullptr)
			{
				curL->end = t;
			}
			tmp->next = t;
			keys = _key;
			this->temp->add_in_st(tmp);
			tmp = t;

			}
		void back() {
			if (tmp != root->head) {
				if (tmp == curL->head) {
					if (!s.empty()) {
						curL = s.top();
						s.pop();
					}
						
				}
				if (!this->curL->ST.empty()) {
					tmp = this->curL->ST.top();
					this->curL->ST.pop();
				}
				
				keys = tmp->val->getKey();
			}
		}
		void down() {
			if (tmp->getType() == 2) {
				//temp = curL;
				this->curL->add_in_st(tmp);
				s.push(this->curL);

				//temp = tmp->val;
				curL = tmp->l;

				temp = tmp->val;
				tmp = curL->head;
				keys = temp->get_cur()->getKey();
			}
			else if(tmp->getType() == 1) {
				this->curL->add_in_st(tmp);
				temp= tmp->val;
				keys = tmp->val->getKey();
			}
				
		};
		void converting_to_list() {//мб добавить, что это текущий список, а предыдущий запушить в стек?

			ListValue* conv = new ListValue();
			conv->key = keys;
			conv->head = tmp;
			conv->end = conv->head;
			conv->cur_link = conv->head;
			Link* c = new Link(conv, tmp->next);
			if (!curL->ST.empty())
				curL->ST.top()->next = c;
			else {
				curL->head = c;
				curL->end = curL->head;
				curL->cur_link = curL->head;
			}
			tmp = c;
			keys = tmp->val->getKey();
			//curL = conv;

		}
		void del() {
			if (!curL->ST.empty())
				curL->ST.top()->next = tmp->next;
			else {
				curL->head = tmp->next;
				if(curL->end==tmp)
					curL->end = tmp->next;
				if (curL->cur_link == tmp)
					curL->cur_link = tmp->next;
			}
			//delete tmp;
			if (!curL->ST.empty())
				tmp = curL->ST.top();
			else {
				tmp = curL->head;
			}
			keys = tmp->val->getKey();
		}
		Ivalue* get_cur() {

			return cur->val;
		}
		bool has_next() {
			if (cur->next == nullptr)
				return false;
				return true;
		}
		//string getJSONString() {
		//	stack<ListValue*> StLv;
		//	ListValue* curlist = root;
		//	//StLv.push(curlist);
		//	string str="{\n";
		//	//str += "{ \n " + root->getKey() +": {\n";
		//	//int n = 10;
		//	do {
		//		/*n--;
		//		if (n == 0)
		//			break;*/
		//	if (curlist->cur_link->getType() == 2) {//list
		//		StLv.push(curlist);
		//		str+=curlist->cur_link->val->getKey();
		//		str += ": {\n";
		//		curlist = curlist->getLast();
		//		
		//		
		//	}
		//	else {
		//		str += curlist->cur_link->val->getKey()+": "+ curlist->cur_link->val->getVal()+"\n}";
		//		if (curlist->has_next()) {
		//			curlist->cur_link=curlist->cur_link->next;
		//			str += "},";//это не правильно, потому что это не подходит для значений
		//			
		//		}
		//		else {
		//			if (StLv.empty())
		//				break;
		//			curlist = StLv.top();
		//			str += "\n}";
		//			StLv.pop();
		//		}
		//	}
		//	
		//	
		//	} while (curlist->cur_link!=root->end->next);
		//		//root->head;
		//	
		//	
		//	str += " \n }";
		//	return str;
		//}

		string getJSONString() {
			//	stack<ListValue*> StLv;
			//	ListValue* curlist = root;
			//	curlist->stock();
			//	//StLv.push(curlist);
			//	string str = "{\n";
			//	//str += "{ \n " + root->getKey() +": {\n";
			//
			//	//int n = 10;
			//	do {
			//		//n--;
			//		//if (n == 0)
			//			//break;
			//		/*if (curlist->cur_link->next == root->end->next)
			//			break;*/
			//		//cout << str;
			//		if (curlist->cur_link->getType() == 2) {//list
			//			StLv.push(curlist);
			//			str += curlist->cur_link->val->getKey();
			//			str += ": {\n";
			//			curlist = curlist->cur_link->l;
			////			curlist->stock();
			//
			//		}
			//		else {
			//			str += curlist->cur_link->val->getKey() + ": " + curlist->cur_link->val->getVal() + "\n}";
			//			if (curlist->has_next()) {
			//				curlist->cur_link = curlist->cur_link->next;
			//				str += "},";//это не правильно, потому что это не подходит для значений
			//
			//			}
			//			else {
			//				if (StLv.empty())
			//					break;
			//				curlist = StLv.top();
			//				str += "\n}\n";
			//				StLv.pop();
			//				curlist->cur_link = curlist->cur_link->next;//
			//				if (curlist->cur_link==nullptr) {//
			//					if (StLv.empty())//
			//						break;//
			//				}
			//			}
			//		}
			//
			//		//cout << str;
			//	} while (true);
			//	//root->head;
			//
			//
			//
			//	str += " \n }";
			//	return str;
			//}
			bool f = false;
			string str = "{\n";
			Ivalue* currentList = root;
			//if (value_current->getType() == 2 && lists.top() != value_current)

			root->stock();
			stack<Ivalue*> st_ivalue;
			stack<Ivalue*>lists;
			//lists.push(currentList);
			//stack<ListValue*>lists;
			//str+= "{\n" ;
			//out << obj.root << endl;
			//Link* curr = obj.Head;
			Ivalue* value_current = root->head->val;
			//Ivalue* listCur = obj.root;
			if (value_current != nullptr && value_current->getType() == 2)
			{
				//st_ivalue.push(value_current);
				lists.push(currentList);
				currentList = value_current;
			}
			else
				st_ivalue.push(value_current);
			//st_ivalue.push(value_current);
			//lists.push(currentList);
			//bool fb;
			//keys = value_current->getKey();
			//out << "\""<< value_current->getKey() << "\"" << ":" << " " <<"{" << endl;//здесь может быть ключ не так выводится
			while (value_current != nullptr) {



				if (value_current->getKey() == keys) {
					str += " => ";
				}
				str += "\"" + value_current->getKey() + "\"" + ":" + " ";
				//string tmp1 = value_current->getKey();
				if (value_current->getType() == 1) {
					str += "\"" + value_current->getVal() + '"' + "\n";
					//cout
					//currentList->next(f);
					Ivalue* i = value_current;
					//int j = 0;
					//if (value_current->getType() == 1) {
					//fb = true;
					//}
					//else  fb = false;
					//if(currentList->has_next())

					value_current = currentList->next(f);

					if (value_current == nullptr) {//
						if (st_ivalue.top() == root->get_cur())//или размер стека равен 1
							break;


						st_ivalue.pop();
						/*if(currentList!=root)
							str+= "}\n";*/
							/*if (i->getType() == 1)
								str += "}\n";*/

						lists.pop();
						currentList->stock();
						if (lists.empty()) {
							str += "}\n";
							break;
						}
						currentList = lists.top();
						if (currentList->has_next() && currentList->get_cur()->getType() == 2) {
							str += "},\n";
						}
						else if (currentList->has_next() && currentList->get_cur()->getType() == 1) {
							str += ",\n";
						}
						else
							str += "}\n";
						/*else if(currentList->has_next() && currentList->get_cur()->getType() == 1)
							str += ",\n";*/


						value_current = currentList->next(f);

						/*currentList->next(f);
						value_current = currentList->get_cur();*/

						if (value_current != nullptr) {
							//if (/*value_current->getType() == 2*/i->getType() == 2 || (currentList->has_next() && currentList != root))
							//	str += "},\n";
							//if (i->getType() == 1)
							//	str += ",\n";

							//else str += "}\n";
							if (value_current->getType() == 2) {

								//if(lists.top()!=currentList)
								//lists.push(currentList);

								if (lists.empty())
									lists.push(currentList);
								else  if (lists.top() != currentList/*&&currentList!=root*/)// {
									lists.push(currentList);

								//value_current = value_current->get_cur();

								if (value_current->getType() == 2)
									currentList = value_current;
							}

							//if (/*value_current->getType() ==1*/i->getType() == 1)
							//	str += ",\n";
							/*if (value_current->getType() == 2)
								str += "},\n";
							if (value_current->getType() == 1)
								str += ",\n";*/
						}
						else {
							while ((value_current == nullptr)) {
								lists.pop();
								if (lists.empty()) {
									str += "}\n";
									root->stock();
									return str;

								}
								


								if (!st_ivalue.empty())
									st_ivalue.pop();
								if (!lists.empty()) {
									currentList = lists.top();
									value_current = currentList->next(false);
									if (value_current != nullptr)
										st_ivalue.push(value_current);
								}
							}
							if (value_current->getType() == 2) {
								//lists.push(value_current);
								currentList = value_current;
								str += "},\n";
							}
							else if (value_current->getType() == 1)
								str += ",\n";





						}
					}
					else {
						/*if(lists.size()==0)
						if (currentList->next(f) == nullptr) {
							cout << "}" << endl;
							break;
						}*/
						st_ivalue.pop();
						if (/*value_current->getType() == 2*/i->getType() == 2 || (currentList->has_next() && currentList != root))
							str += "},\n";
						if (/*value_current->getType() ==1*/i->getType() == 1)
							str += ",\n";
					}
					if (st_ivalue.empty())
						st_ivalue.push(value_current);
					else if (value_current != nullptr && st_ivalue.top() != value_current)
						st_ivalue.push(value_current);

					/*if(curr->getKey()!= curr->val->getKey()) //у звена не должно быть ключа тогда
					out << "\"" << curr->getKey() << "\"" << ":" << " " << "{" << endl;*/
				}
				else if (value_current->getType() == 2) {
					str += "{\n";

					if (lists.empty())
						lists.push(currentList);
					else  if (lists.top() != currentList/*&&currentList!=root*/)// {
						lists.push(currentList);
					//if (lists.top() != value_current&&currentList!=root) {
						//lists.push(value_current);
					value_current = value_current->get_cur();
					//}
					if (value_current->getType() == 2)
						currentList = value_current;

					//lists.push(currentList);
					//out<<curr->


					st_ivalue.push(value_current);
					//}
					// тут надо бы функцию down наверно
				}
			}
			str += "}\n";
			root->stock();
			return str;
		
		
		}

		/*void back() {

		};*/ //next и back можем сделать в списке, а потом в джейсоне их использовать
		//для навигации по джейсону. 

		//friend ostream& operator <<(ostream& out, Json& obj) { //я бегу по звеньям, и читаю у них ключи, а надо читать ival
		//	//stack<Link*> st;
		//	bool f = false;
		//	ListValue* currentList = obj.root;
		//	stack<Ivalue*> st_ivalue;
		//	stack<ListValue*>lists;
		//	out << "{" << endl;
		//	//out << obj.root << endl;
		//	//Link* curr = obj.Head;
		//	Ivalue* value_current = obj.root->get_cur();
		//	//Ivalue* listCur = obj.root;
		//	st_ivalue.push(value_current);
		//	lists.push(currentList);
		//	//out << "\""<< value_current->getKey() << "\"" << ":" << " " <<"{" << endl;//здесь может быть ключ не так выводится
		//	while (value_current != nullptr) {
		//		//if(curr->val->getType()==1&&curr)
		//		out << "\"" << value_current->getKey() << "\"" << ":" << " ";
		//		//string tmp1 = value_current->getKey();
		//		if (value_current->getType() == 1) {
		//			out << "\"" << value_current->getVal() << '"' << endl;
		//			//cout
		//			//currentList->next(f);
		//			value_current = currentList->next(f);
		//			if (value_current == nullptr) {//
		//				if (st_ivalue.top() == obj.root->get_cur())//или размер стека равен 1
		//					break;
		//				st_ivalue.pop();
		//				cout << "}" << endl;
		//				lists.pop();
		//				currentList = lists.top();
		//				value_current = currentList->next(f);
		//				/*currentList->next(f);
		//				value_current = currentList->get_cur();*/
		//				if (value_current != nullptr)
		//					cout << "}," << endl;
		//				else cout << "}" << endl;
		//			}
		//			else {
		//				/*if(lists.size()==0)
		//				if (currentList->next(f) == nullptr) {
		//					cout << "}" << endl;
		//					break;
		//				}*/
		//				cout << "}," << endl;
		//			}
		//			st_ivalue.push(value_current);
		//			/*if(curr->getKey()!= curr->val->getKey()) //у звена не должно быть ключа тогда
		//			out << "\"" << curr->getKey() << "\"" << ":" << " " << "{" << endl;*/
		//		}
		//		else if (value_current->getType() == 2) {
		//			out << "{" << endl;
		//			//st.push(curr.)
		//			/*ListValue* lv;
		//			lv->set_key(curr->val->getKey());*/
		//			//ListValue* lv;
		//			//lv=
		//			//listCur.
		//			//out << curr->val << endl;
		//			//ListValue* lv;
		//			//curr = curr->val.
		//			value_current = value_current->get_cur();
		//			//out<<curr->
		//			lists.push(currentList);
		//			st_ivalue.push(value_current);
		//			// тут надо бы функцию down наверно
		//		}
		//	}
		//	out << "}" << endl;
		//	return out;
		//}

		friend ostream& operator <<(ostream& out, Json& obj) { //я бегу по звеньям, и читаю у них ключи, а надо читать ival
			//stack<Link*> st;
			bool f = false;
			ListValue* currentList = obj.root;
			stack<Ivalue*> st_ivalue;
			stack<ListValue*>lists;
			out << "{" << endl;
			//out << obj.root << endl;
			//Link* curr = obj.Head;
			Ivalue* value_current = obj.root->get_cur();
			//Ivalue* listCur = obj.root;
			st_ivalue.push(value_current);
			lists.push(currentList);
			//out << "\""<< value_current->getKey() << "\"" << ":" << " " <<"{" << endl;//здесь может быть ключ не так выводится
			while (value_current != nullptr) {
				//if(curr->val->getType()==1&&curr)
				out << "\"" << value_current->getKey() << "\"" << ":" << " ";
				//string tmp1 = value_current->getKey();
				if (value_current->getType() == 1) {
					out << "\"" << value_current->getVal() << '"' << endl;
					//cout
					//currentList->next(f);
					value_current = currentList->next(f);

					if (value_current == nullptr) {//
						//if (!lists.empty()) {
						if (lists.size() == 1 && !obj.root->has_next()) {
							break;
						}

						if ((st_ivalue.size() == 1 && st_ivalue.top() == obj.root->get_cur())) {//или размер стека равен 1
							break;//переделай, это костыльно
						}

						st_ivalue.pop();
						//cout << "}" << endl;

						//currentList = lists.top();
						lists.pop();
						currentList->stock();
						currentList = lists.top();

						value_current = currentList->next(f);

						/*currentList->next(f);
						value_current = currentList->get_cur();*/

						if (value_current != nullptr)
							cout << "}," << endl;
						else cout << "}" << endl;
					}
					else {
						/*if(lists.size()==0)
						if (currentList->next(f) == nullptr) {
							cout << "}" << endl;
							break;
						}*/
						cout << "}," << endl;
					}
					st_ivalue.push(value_current);
					/*if(curr->getKey()!= curr->val->getKey()) //у звена не должно быть ключа тогда
					out << "\"" << curr->getKey() << "\"" << ":" << " " << "{" << endl;*/
				}
				else if (value_current->getType() == 2) {
					out << "{" << endl;
					//st.push(curr.)
					/*ListValue* lv;
					lv->set_key(curr->val->getKey());*/
					//ListValue* lv;
					//lv=
					//listCur.

					//out << curr->val << endl;
					//ListValue* lv;

					//curr = curr->val.

					value_current = value_current->get_cur();

					//out<<curr->
					if (currentList != obj.root) {


						lists.push(currentList);

					}
					//st_ivalue.push(value_current);
					currentList = currentList->existList();
					if (currentList != nullptr) {
						lists.push(currentList);
						//value_current = currentList;
						//st_ivalue.push(value_current);
					}
					while (currentList == nullptr) {
						if (lists.empty())
							break;

						//currentList = lists.top();
						lists.pop();
						currentList->stock();
						currentList = lists.top();//
						//cout << "}\n";
						if (!currentList->has_next()) {
							currentList = nullptr;
							//cout << "}\n";

						}
					}
					// тут надо бы функцию down наверно
				}
			}
			out << "}" << endl;

			return out;
		}

		friend istream& operator >> (istream& in, Json& obj) {

			stack <ListValue*> Stack;
			ListValue* currentList = obj.root;
			/*Link* Current_link =obj.Head;
			Link* end_link = obj.End;*/
			Ivalue* curval = obj.get_cur();//у меня последний это
			/*if (currentList->get_head() == nullptr)
				currentList->addVal();*/
				//currentList->get_head() = new Link();
				//obj.ST.push(currentList.);
			Stack.push(currentList);
			//obj.heap.push(curval);
			string tmp;
			string curkey;
			in >> tmp;
			cout << tmp << endl;
			string sep = "$";
			while (tmp != sep) {
				/*if (tmp == "{")
				{*/
				in >> tmp;
				cout << tmp << " ";

				while (tmp == "}") {

					if (!Stack.empty()) {
						Stack.top()->stock();
						Stack.pop();
						if (!Stack.empty()) {
							currentList = Stack.top();
							//curval = currentList->next(true);
							curval = currentList->get_cur();
							// 
								//Current_link= obj.Stack.top().  // здесь надо присвоить новое начало и новый конец 
						}
						else return in;
						in >> tmp;
					}
					else {
						return in;
					}
					cout << "\n" << tmp;
				}
				if (tmp == "},") {
					Stack.top()->stock();
					Stack.pop();
					currentList = Stack.top();
					cout << "\n";
					in >> tmp;
					cout << tmp << " ";
				}
				int a;
				string tmp2;
				curkey = tmp;//запоминаю ключ
				a = curkey.length();

				tmp2 = curkey.substr(1, a - 3);

				//for (int i = 1; i < a - 2; i++) {
				//	tmp2[i - 1] = curkey[i];  //убираю кавычки и двоеточие
				//}



				//if (currentList->getKey()=="")//можно убрать
				//	currentList->set_key(tmp2);// ключ главного



				/*if (currentList->get_head() == nullptr) {
					currentList->get_head() = new Link();
				}*/
				//currentList.
				/*if (currentList->get_cur()!=nullptr )
					if(currentList->get_cur())
					currentList->get_cur()->set_key(tmp2);*/
					/*if (currentList->get_cur()->getKey() == "" && currentList->get_end() == currentList->get_head())
						currentList->get_end()->Key = tmp2;*/
						//if (currentList->get_end()->empty())
						//	if (currentList->get_end()->val!=nullptr)
						//	if(currentList->get_end()->val->getKey() == "")//берется не то значение, похоже что где то что то со звеньями
						//	currentList->get_end()->val->set_key(tmp2);//ключ последнего(текущего) звена

				in >> tmp;

				if (tmp == "{") {
					cout << " " << tmp << "\n";
					if (currentList->get_cur() != nullptr) //{
						if (currentList->has_next())
							currentList->MoveNext();
					currentList->addList(tmp2);
					currentList = currentList->getLast();
					Stack.push(currentList);
					//obj.ST.push(currentList);
					curval = currentList->get_cur();
					/*}
					else {

					}*/
					//currentList->get_cur()->set_key(tmp2);//
					in >> tmp;
					cout << tmp << " ";
					string curkey2 = tmp;//запоминаю ключ
					int b = curkey2.length();
					string tmp3 = curkey2.substr(1, b - 2);


					//for (int i = 1; i < a - 2; i++) {
					//	tmp3[i - 1] = curkey2[i];  //убираю кавычки и двоеточие
					//}

					in >> tmp;
					if (tmp == "{") {
						cout << tmp << "\n";
						if (currentList->get_cur() != nullptr)
							if (currentList->has_next())
								currentList->MoveNext();
						currentList->addList(tmp3);//здесь надо бы tmp3

						//currentList->get_cur()->set_key(tmp2);
						currentList = currentList->getLast();//во внутреннем
						Stack.push(currentList);
						//obj.ST.push(currentList);
						curval = currentList->get_cur();
						//obj.heap.push(currentList->get_head());
					}
					else {
						cout << tmp << endl;
						a = tmp.length();
						string v = tmp.substr(1, a - 2);
						//for (int i = 1; i < a - 1; i++) {
						//	v[i - 1] = curkey[i];  //убираю кавычки и двоеточие
						//}
						currentList->addVal(tmp3, v);//tmp3
						//obj.heap.push(currentList->get_cur());
					}


				}
				else {
					cout << tmp << endl;
					a = tmp.length();
					string val = tmp.substr(1, a - 2);
					//for (int i = 1; i < a - 1; i++) {
					//	val[i - 1] = curkey[i];  //убираю кавычки и двоеточие
					//}
					currentList->addVal(tmp2, val);
					//obj.heap.push(currentList->get_cur());
				}
				/*if (currentList->get_end()->getKey() == "")
					currentList->get_end()->Key = tmp2;*/
					/*}
					else {
						throw - 1;
					}*/
					//ListValue.add(atoi(tmp.c_str));
					//in >> tmp;

			}
			obj.root->stock();
			return in;
		}
		friend class Listvalue;
	};
	//public ref  class NetIvalue abstract{
	//
	//	virtual int getType() = 0;
	//	virtual System::String^ getKey() = 0;
	//	//virtual Itervalue* itr() = 0; 
	//	virtual System::String^ getVal() = 0;
	//	virtual void set_key(string tmp) = 0;
	//	
	//	virtual Ivalue* next() = 0;
	//	virtual Ivalue* back() = 0;
	//	virtual Ivalue* get_cur() = 0;

	//};
	//public ref class NetValue :public NetIvalue{
	//	Value* val;
	//public:
	//	NetValue(){
	//		val = new Value();
	//	}

	//	NetValue(System::String^ _key, System::String^ _val) {
	//		std::string key = msclr::interop::marshal_as<std::string>(_key);
	//		std::string value = msclr::interop::marshal_as<std::string>(_val);
	//		val = new Value(key, value);
	//	}

	//	Ivalue* next() {
	//		return nullptr;
	//	};
	//	Ivalue* back() {
	//		return nullptr;
	//	};
	//	Ivalue* get_cur() {
	//		return nullptr;
	//	};
	//	int getType() {
	//		return val->getType();
	//	};

	//	System::String^ getKey() {
	//		return gcnew System::String((val->getKey()).c_str());
	//	};
	//	
	//	System::String^ getVal() {
	//	return gcnew System::String((val->getVal()).c_str());
	//	};

	//	void set_key(string tmp) {
	//		val->set_key(tmp);
	//	};

	//};
	//public ref class NetListValue :public NetIvalue {
	//	ListValue* lv;
	//public:
	//	NetListValue() {
	//		lv = new ListValue();
	//	}
	//	NetListValue(System::String^ _key, System::String^ _value)
	//	{
	//		std::string key = msclr::interop::marshal_as<std::string>(_key);
	//		std::string value = msclr::interop::marshal_as<std::string>(_value);
	//		lv = new ListValue(key, value);
	//	}
	//	Ivalue* next() {
	//		return lv->next(true);
	//	};
	//	void back() {
	//		return lv->back();
	//	};
	//	Ivalue* get_cur() {
	//		return lv->get_cur();
	//	};
	//	int getType() {
	//		return lv->getType();
	//	};
	//	System::String^ getKey() {
	//		return gcnew System::String((lv->getKey()).c_str());
	//	};

	//	System::String^ getVal() {
	//		return gcnew System::String((lv->getVal()).c_str());
	//	};

	//	void set_key(string tmp) {
	//		lv->set_key(tmp);
	//	};


	//};
	//public ref class Observer {

	//public:
	//	Observer() {}
	//	virtual void update() abstract;
	//};

	//public ref class NetJson {
	//	Json* json;
	//	//ListValue* root;
	//	Observer^ ob;
	//public:
	//	NetJson() {
	//		json = new Json;
	//		ob = nullptr;
	//	}
	//	void load(System::String^ filename) {
	//		json->load(msclr::interop::marshal_as<std::string>(filename));
	//	}

	//	void show() {
	//		cout << json;
	//	}
	//	/*NetListValue^ rootlv() {
	//		return json.
	//	}*/

	//	//System::String^ next() {
	//	//	return gcnew System::String((json->next()->getKey()).c_str());
	//	//	//return json->next()->getKey();
	//	//}
	//	void next() {
	//		//if(json.)
	//		json->next_for_netJS();
	//	}
	//	
	//	bool has_next() {
	//		return json->has_next();
	//	}

	//	void addObserver(Observer^ _ob) {
	//		ob = _ob;
	//		ob->update();
	//	}
	//	
	//	string getcur() {
	//		
	//		return json->get_cur()->getKey();
	//	}
	//	void back() {
	//		json->back();
	//	}
	//	void down() {
	//		json->down();
	//	}

	//	void add_in_start(System::String^ _key,System::String^ _value) {
	//		std::string key = msclr::interop::marshal_as<std::string>(_key);
	//		std::string value = msclr::interop::marshal_as<std::string>(_value);

	//		json->add_in_start(key,value);
	//	}
	//	void add_after(System::String^ _key, System::String^ _value) {
	//		std::string key = msclr::interop::marshal_as<std::string>(_key);
	//		std::string value = msclr::interop::marshal_as<std::string>(_value);

	//		json->add_after(key, value);
	//	}
	//	System::String^ getJsonString() { return gcnew System::String(json->getJSONString().c_str()); }
	//};
}
