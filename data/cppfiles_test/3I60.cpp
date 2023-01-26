#include <bits/stdc++.h>
using namespace std;
long long dp[10][25][12];
bool memo[10][25][12];
string s;
long long f(int index, int res, int choosen) {
  if (index == s.size()) {
    return res == 0;
  }
  if (memo[index][res][choosen]) {
    return dp[index][res][choosen];
  }
  if (s[index] == 'X' && choosen == 10) {
    int ans = 0;
    for (int i = (index == 0); i <= 9; i++) {
      ans += f(index + 1, (res * 10 + i) % 25, i);
    }
    return dp[index][res][choosen] = ans;
  }
  if (s[index] == '_') {
    int ans = 0;
    for (int i = (index == 0); i <= 9; i++) {
      ans += f(index + 1, (res * 10 + i) % 25, choosen);
    }
    return dp[index][res][choosen] = ans;
  }
  int i = (s[index] == 'X') ? choosen : s[index] - '0';
  return dp[index][res][choosen] = f(index + 1, (res * 10 + i) % 25, choosen);
}
int main() {
  cin >> s;
  if (s[0] == '0' && s.size() > 1) {
    cout << 0 << "\n";
  } else {
    cout << f(0, 0, 10) << "\n";
  }
}
