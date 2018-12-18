#include "Main.h"

class AdvancedDp1
{
public:
	AdvancedDp1() {}

	int LongestPalindromicSequance(char* str) {
		//return LPS(str, 0, strlen(str) - 1);
		return LPS_DP(str);
	}
private:

	int LPS(char s[], int i, int j) {
		if (i == j)return 1;

		if (s[i] == s[j]) {
			if (i + 1 == j) return 2;
			return 2 + LPS(s, ++i, j--);
		}
		return max(LPS(s, i + 1, j), LPS(s, i, j - 1));
	}
	int LPS_DP(char *str) {
		int n = strlen(str), j;
		int t[101][101];
		for (int i = 0;i < n;++i)t[i][i] = 1;
		for (int cl = 2;cl <= n;++cl) {
			for (int i = 0;i < n - cl + 1;++i) {
				j = i + cl - 1;
				if (str[i] == str[j] && cl == 2)t[i][j] = 2;
				else if (str[i] == str[j])t[i][j] = t[i + 1][j - 1] + 2;
				else t[i][j] = max(t[i + 1][j], t[i][j - 1]);
			}
		}
		return t[0][n - 1];
	}
};
