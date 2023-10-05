#pragma once
#include "Json.h"
#include <msclr/marshal_cppstd.h>

using namespace std;

namespace MyJson {
	class Json;

	public ref  class NetIvalue abstract {

		virtual int getType() = 0;
		virtual System::String^ getKey() = 0;
		//virtual Itervalue* itr() = 0; 
		virtual System::String^ getVal() = 0;
		virtual void set_key(string tmp) = 0;

		virtual Ivalue* next() = 0;
		virtual Ivalue* back() = 0;
		virtual Ivalue* get_cur() = 0;

	};
	public ref class NetValue :public NetIvalue {
		Value* val;
	public:
		NetValue() {
			val = new Value();
		}

		NetValue(System::String^ _key, System::String^ _val) {
			std::string key = msclr::interop::marshal_as<std::string>(_key);
			std::string value = msclr::interop::marshal_as<std::string>(_val);
			val = new Value(key, value);
		}

		Ivalue* next() {
			return nullptr;
		};
		Ivalue* back() {
			return nullptr;
		};
		Ivalue* get_cur() {
			return nullptr;
		};
		int getType() {
			return val->getType();
		};

		System::String^ getKey() {
			return gcnew System::String((val->getKey()).c_str());
		};

		System::String^ getVal() {
			return gcnew System::String((val->getVal()).c_str());
		};

		void set_key(string tmp) {
			val->set_key(tmp);
		};

	};
	public ref class NetListValue :public NetIvalue {
		ListValue* lv;
	public:
		NetListValue() {
			lv = new ListValue();
		}
		NetListValue(System::String^ _key, System::String^ _value)
		{
			std::string key = msclr::interop::marshal_as<std::string>(_key);
			std::string value = msclr::interop::marshal_as<std::string>(_value);
			lv = new ListValue(key, value);
		}
		Ivalue* next() {
			return lv->next(true);
		};
		void back() {
			return lv->back();
		};
		Ivalue* get_cur() {
			return lv->get_cur();
		};
		int getType() {
			return lv->getType();
		};
		System::String^ getKey() {
			return gcnew System::String((lv->getKey()).c_str());
		};

		System::String^ getVal() {
			return gcnew System::String((lv->getVal()).c_str());
		};

		void set_key(string tmp) {
			lv->set_key(tmp);
		};


	};
	public ref class Observer {

	public:
		Observer() {}
		virtual void update() abstract;


	};

	public ref class NetJson {
		Json* json;
		//ListValue* root;
		Observer^ ob;
	public:
		NetJson() {
			json = new Json;
			ob = nullptr;
		}
		void load(System::String^ filename) {
			json->load(msclr::interop::marshal_as<std::string>(filename));
		}

		void show() {
			cout << json;
		}
		/*NetListValue^ rootlv() {
			return json.
		}*/

		//System::String^ next() {
		//	return gcnew System::String((json->next()->getKey()).c_str());
		//	//return json->next()->getKey();
		//}
		void next() {
			//if(json.)
			json->next_for_netJS();
		}

		bool has_next() {
			return json->has_next();
		}

		void addObserver(Observer^ _ob) {
			ob = _ob;
			ob->update();
		}

		string getcur() {

			return json->get_cur()->getKey();
		}
		void back() {
			json->back();
		}
		void down() {
			json->down();
		}
		void converting_to_list() {
			json->converting_to_list();
		}
		void del() {
			json->del();
		}
		void add_in_start(System::String^ _key, System::String^ _value) {
			std::string key = msclr::interop::marshal_as<std::string>(_key);
			std::string value = msclr::interop::marshal_as<std::string>(_value);

			json->add_in_start(key, value);
		}
		void add_after(System::String^ _key, System::String^ _value) {
			std::string key = msclr::interop::marshal_as<std::string>(_key);
			std::string value = msclr::interop::marshal_as<std::string>(_value);

			json->add_after(key, value);
		}
		System::String^ getJsonString() { return gcnew System::String(json->getJSONString().c_str()); }
	};




}