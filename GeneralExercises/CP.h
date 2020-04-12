#pragma once

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
#define sz(v) ((int)((v).size()))
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#define MAX 101
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

struct edge
{
	int from, to, w;
	edge(int from, int to, int w) :from(from), to(to), w(w) {
	}
	bool operator < (const edge &e)const {
		return w > e.w;
	}
};

struct UnionFind {

	VI rank, parent;
	int forests;

	UnionFind(int n) {
		rank = VI(n), parent = VI(n);
		forests = n;
		REP(i, n)parent[i] = i, rank[i] = 1;
	}

	int find_set(int x) {
		//while(x!=parent[x]) x=parent[x];
		if (x == parent[x])return x;
		return parent[x] = find_set(parent[x]);
	}

	void link(int x, int y) {
		if (rank[x] > rank[y])swap(x, y);
		parent[x] = y;
		if (rank[x] == rank[y])rank[y]++;
	}

	bool union_sets(int x, int y) {
		x = find_set(x), y = find_set(y);
		if (x != y) {
			link(x, y);
			forests--;
		}
		return x != y;
	}
};