#include "stdafx.h"
#include "CppUnitTest.h"
#include "../HashTable/HashTable.h"

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
				Assert::IsTrue(a.hash_fun(p)<20);
				p = p + (char)(i + (int)p[0]);
			}
			
		}
		
		TEST_METHOD(find)
		{
			HashTable a(20);
			string p = "1";
			Assert::IsTrue(a.find(p) == (-1));
			a.put(p);

			Assert::IsTrue(a.hash_fun(p) == a.find(p,true));
			
		}
		TEST_METHOD(put)
		{
			HashTable a(20);
			string p = "1";
			Assert::IsFalse(a.find(p)>=0);
			a.put(p);
			Assert::IsTrue(a.hash_fun(p) != a.find(p, false));
			Assert::IsTrue(a.find(p, false) >=0);
			a.put(p);
			Assert::IsTrue(a.find(p, false) >= 0);
			a.put(p);
			Assert::IsFalse(a.find(p, false) >= 0);

		}
	};
}