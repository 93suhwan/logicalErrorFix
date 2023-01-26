#include <bits/stdc++.h>
using namespace std;
bool check(int x, string s) {
  string num = "";
  while (x) {
    num += x % 10 + '0';
    x /= 10;
  }
  if (!num.size()) num += '0';
  int _x = -1;
  reverse(num.begin(), num.end());
  if (num.length() != s.length()) return 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '_') continue;
    if (s[i] == 'X') {
      if (_x == -1) _x = num[i];
      if (_x != num[i]) return 0;
    } else if (s[i] != num[i])
      return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int res = 0;
  for (int i = 0; i <= pow(10, s.length()) + 1; i += 25) res += check(i, s);
  cout << res;
  return 0;
}
