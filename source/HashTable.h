#pragma once
#ifndef _HashTable_
#define _HashTable_

using namespace std;
#include<string>


class HashTable {

public:

	HashTable(unsigned int size):size(size+1) {
		this->valuearr = new string[this->size];
		this->boolarr = new bool[this->size] {false};
		
	}


	
	unsigned int hash_fun(string &value) 
	{
		unsigned int res = 1;
		for (unsigned int i = 0; i < value.size(); i++)
		{
			res = res +unsigned int(value.at(i))*(i+1);

		}
		res = res % this->size;
		return res;
	}
	




	unsigned int seek_slot(string & value) {
		return this->find(value,false);
	}


	void put(string & value) {
		this->valuearr[this->seek_slot(value)] = value;
		this->boolarr[this->seek_slot(value)] = true;
	}
	unsigned int find(string & value,bool val=true) {
		unsigned int res = this->hash_fun(value);
		for (unsigned int i = 0; i <= this->step; i++)
		{

			if (this->boolarr[(res + (i*this->step))%this->size] == val) {
				return (res + (i*this->step)) % this->size;
			}
			
		}
		return 0;
	}


private:

	

	bool *boolarr;
	string *valuearr;
	unsigned int size;
	unsigned int step = 2;
};




#endif // !1






