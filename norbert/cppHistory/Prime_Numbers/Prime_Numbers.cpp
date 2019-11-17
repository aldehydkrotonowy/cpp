////////////////////////////////////////////////////////////////////////////////////
// Prime Number Generator
// author: Gonzales Cenelia
// homepage: www.ai-search.4t.com
// Threw history,prime numbers has always be a great fascination for mathematicians.
// Even in modern times,primes numbers continues to fascinate many people.
// Probably the main reason why prime numbers continues to create such great interest
// would be because of the difficulty to prove that any given arbitrary number is prime.
// This is call the primality test. Most of the test for primality are probalistic rather
// than deterministic,because probalistic test are much more quicker than the deterministic
// ones. When testing the primality of a given number,one of the theorem that is very
// largely used is Fermat's little theorem: if "p" is a prime number that is not a factor
// of a given integer "a",then pow(a, p - 1) = 1 (mod p) or pow(a, p - 1) % p = 1
// One of the main application of prime numbers nowadays is chryptography,the RSA algorithm
// for encrypting and decrypting messages is based on prime numbers. //****************
//***********************************************************************
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cassert>
using std::fstream;
using std::vector;

vector<int> prime_number_list;
unsigned int list_size = 0;

bool isPrime(int nNum);

int main()
{
	int thisNumber;
	fstream fout("prime numbers.txt", std::ios::out);
	if(fout.fail())
	{
		std::cerr << "Error while opening \"prime numbers.txt\"" << std::endl;
		assert(fout.good());
	}
	// generating the first 10000 prime numbers and saving them
	// as a table into  a file
	fout << "Prime Number Table (first 10000 prime numbers)\n\n";
	for(int i = 2; list_size < 10000; ++i)
	{
		thisNumber = i;
		list_size = prime_number_list.size();
		if(isPrime(thisNumber))
		{
			prime_number_list.push_back(thisNumber);
			fout.width(10);
			fout << thisNumber;
			if((list_size + 1) % 10 == 0)
			{
				fout << std::endl;
			}
		}
	}
	fout.flush();
	fout.close();
	return 0;
}

//======================================================
// simple test for primality,it uses a "division test"
// each number is tested for primality by using 
// the previous stored prime numbers as divisors.
// the test is repeated till one of the following 
// situations occures: a factor was found,so the number 
// is composite. The current divisor is bigger than the 
// square root of the number to be tested,
// so this number is prime.
//======================================================
bool isPrime(int nNum)
{
	int maxFactor = sqrt(nNum), thisFactor;
	bool bRetVal = true;
	for(int i = 0; i < list_size; ++i)
	{
		thisFactor = prime_number_list[i];
		if(thisFactor > maxFactor)
		{
			break;
		}
		if(nNum % thisFactor == 0)
		{
			bRetVal = false;
			break;
		}
	}
	return bRetVal;
}