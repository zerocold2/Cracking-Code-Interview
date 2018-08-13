
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi = acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }
/**********************************************/

/****** Template of Fast I/O Methods *********/
template <typename T> inline void write(T x)
{
	int i = 20;
	char buf[21];
	// buf[10] = 0;
	buf[20] = '\n';

	do
	{
		buf[--i] = x % 10 + '0';
		x /= 10;
	} while (x);
	do
	{
		putchar(buf[i]);
	} while (buf[i++] != '\n');
}

template <typename T> inline T readInt()
{
	T n = 0, s = 1;
	char p = getchar();
	if (p == '-')
		s = -1;
	while ((p<'0' || p>'9') && p != EOF && p != '-')
		p = getchar();
	if (p == '-')
		s = -1, p = getchar();
	while (p >= '0'&&p <= '9') {
		n = (n << 3) + (n << 1) + (p - '0');
		p = getchar();
	}

	return n * s;
}
/************************************/



class ArrayAndStrings
{
public:
	/*
	* 1.1	Implement an algorithm to determine if a string has all unique characters What if you
			can not use additional data structures?
	*/

	static bool Unique_Character(string str)
	{
		sort(str.begin(), str.end());
		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] == str[i + 1])return false;
		}
		return true;
	}

	/*
	 * 1.2	Write code to reverse a C-Style String (C-String means that “abcd” is represented as
			fve characters, including the null character )
	 */
	static char* ReverseC_String(char str[])
	{
		int len = strlen(str);
		if (len <= 2) return str;
		int left = 0;
		int right = len - 1;
		while (left < right)
		{
			char tmp = str[left];
			str[left] = str[right];
			str[right] = tmp;
			left++;
			right--;
		}
		return str;
	}

	/*
	 * 1.3  Design an algorithm and write code to remove the duplicate characters in a string
			without using any additional buﬀer NOTE: One or two additional variables are fne
			An extra copy of the array is not
			FOLLOW UP
			Write the test cases for this method
	 */
	static char* Remove_Dubkicate(char str[])
	{

		return str;
	}
};


