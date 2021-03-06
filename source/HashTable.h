#pragma once
#ifndef _HashTable_
#define _HashTable_

using namespace std;
#include<string>
#include<cmath>

class HashTable {

public:

	HashTable(int size):size(size) {
		this->valuearr = new string[this->size];
		this->boolarr = new bool[this->size] {false};
		
	}


	
	int hash_fun(string &value) 
	{
		int res = 0;
		int a = 7;
		int c = 13;
		for (int i = 0; i < value.size(); i++)
		{
			res = abs( ((int(value.at(i))+res) * c) + a)  ;

		}
		return res% this->size;
	}
	




	


	void put(string & value) {
		if(this->find(value, false) >=0)
		{
			this->valuearr[this->find(value, false)] = value;
			this->boolarr[this->find(value, false)] = true;
		}
	}
	int find(string & value,bool val=true) {
		int res = this->hash_fun(value);
		for (int i = 0; i <= this->step; i++)
		{

			if (this->boolarr[(res + (i*this->step))%this->size] == val) {
				return (res + (i*this->step)) % this->size;
			}
			
		}
		return -1;
	}


private:

	

	bool *boolarr;
	string *valuearr;
	int size;
	int step = 2;
};




#endif // !1






