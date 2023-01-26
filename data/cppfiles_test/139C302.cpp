#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
bool flip(int i, int j, vector<vector<int>> &dp) {
  if (i == 0) return false;
  if (dp[i][j] != -1) return dp[i][j];
  bool answer = false;
  if (i >= 1) answer |= !flip(i - 1, !j, dp);
  if (i >= 2) answer |= !flip(i - 2, !j, dp);
  return dp[i][j] = answer;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    if (str.size() % 2 != 0) {
      cout << "NO"
           << "\n";
      continue;
    }
    long long int n = str.size();
    long long int i = 0, j = n / 2;
    bool flag = false;
    while (i < n / 2 && j < n) {
      if (str[i] != str[j]) {
        flag = true;
        break;
      }
      i++;
      j++;
    }
    if (flag)
      cout << "NO";
    else
      cout << "YES";
    cout << "\n";
  }
  return 0;
}
