#include<iostream>
#include<string>
#include"HashTable.h"


using namespace std;




int main() {


	HashTable a(20);
	string p = "1";
	for (int i = 0; i < 1000; i++) {
		if(a.hash_fun(p)>20){
		cout<<a.hash_fun(p)<<endl;}
		p = p + char(i);
	}
	return 0;
}