// A Dynamic Programming based C++ program to find minimum number operations to convert str1 to str2
#include <bits/stdc++.h>
using namespace std;

// Utility function to find the minimum of three numbers
int min(int x, int y, int z) { return min(min(x, y), z); }

int editDistDP(string s, string t){
    int m = s.size();
    int n = t.size();
    int dp[m + 1][n + 1];

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0)
				dp[i][j] = j; // Min. operations = j

			else if (j == 0)
				dp[i][j] = i; // Min. operations = i

			else if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + min(dp[i][j - 1], // Insert
							dp[i - 1][j], // Remove
							dp[i - 1][j - 1]); // Replace
		}
	}

	return dp[m][n];
}

int main(){
	string str1 = "sunday";
	string str2 = "saturday";

	cout << editDistDP(str1, str2);

	return 0;
}