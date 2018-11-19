#include "stdafx.h"
#include "CppUnitTest.h"
#include "../source/HashTable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableTest
{		
	TEST_CLASS(HashTab)
	{
	public:
		
		TEST_METHOD(fun_hash)
		{
			HashTable a(20);
			string p = "1";
			for (int i = 0; i < 1000; i++) {
				Assert::IsTrue(a.hash_fun(p)<=20);
				p = p + char(i);
			}
			
		}
		TEST_METHOD(seek_slot)
		{
			HashTable a(20);
			string p = "1";
			a.put(p);
			Assert::IsTrue(a.hash_fun(p) != a.seek_slot(p));
			for (int i = 0; i < 10; i++) {
				a.put(p);
			}
			Assert::IsFalse(a.seek_slot(p));
		}
		TEST_METHOD(find)
		{
			HashTable a(20);
			string p = "1";
			Assert::IsFalse(a.find(p));
			a.put(p);

			Assert::IsTrue(a.hash_fun(p) == a.find(p));
			
		}
		TEST_METHOD(put)
		{
			HashTable a(20);
			string p = "1";
			Assert::IsFalse(a.find(p));
			a.put(p);
			Assert::IsTrue(a.hash_fun(p) != a.seek_slot(p));
			Assert::IsTrue(a.seek_slot(p)>0);
			a.put(p);
			Assert::IsTrue(a.seek_slot(p) > 0);
			a.put(p);
			Assert::IsFalse(a.seek_slot(p));

		}
	};
}