#include "CP.h"

class UnionFindDisjointSets {
public:
	int sets = 0;
	VI par, rank;
	UnionFindDisjointSets(int n) {
		par.resize(n);
		rank.resize(n);
		REP(i, n) {
			par[i] = i;
			rank[i] = 1;
			sets++;
		}
	}
	int findSet(int s) {
		return (par[s] == s) ? s : (par[s] = findSet(par[s]));
	}
	void UnionSet(int x, int y) {

		x = findSet(x);
		y = findSet(y);
		if (x != y) {
			if (rank[x] > rank[y]) swap(x, y);
			par[x] = y;
			if (rank[x] == rank[y])y++;
			sets--;
		}
	}
};