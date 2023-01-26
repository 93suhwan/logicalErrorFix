#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
long long int traverse(string s, long long int j, long long int x) {
  long long int ans = 0;
  long long int n = s.size();
  if (j == n - 1) {
    if (s[j] == 'X' && x != -1) {
      s[j] = x + '0';
    } else if (s[j] == 'X' || s[j] == '_') {
      if (s[j - 1] == '7' || s[j - 1] == '2')
        s[j] = '5';
      else if (s[j - 1] == '5' || s[j - 1] == '0')
        s[j] = '0';
      else
        return 0;
      return 1;
    }
    long long int r = stoi(s);
    return r % 25 == 0 ? 1 : 0;
  }
  if (j == 0) {
    if (s[j] == 'X') {
      for (long long int i = 1; i < 10; i++) {
        s[j] = '0' + i;
        ans += traverse(s, j + 1, i);
      }
      return ans;
    } else if (s[j] == '_') {
      for (long long int i = 1; i < 10; i++) {
        s[j] = '0' + i;
        ans += traverse(s, j + 1, x);
      }
      return ans;
    } else {
      return traverse(s, j + 1, x);
    }
  }
  if (n - j > 3) {
    if (s[j] == 'X' && x == -1) {
      s[j] = '1';
      ans = 6 * traverse(s, j + 1, 1);
      s[j] = '2';
      ans += traverse(s, j + 1, 2);
      s[j] = '0';
      ans += traverse(s, j + 1, 0);
      s[j] = '5';
      ans += traverse(s, j + 1, 5);
      s[j] = '7';
      ans += traverse(s, j + 1, 7);
    } else if (s[j] == 'X') {
      s[j] = '0' + x;
      ans = traverse(s, j + 1, x);
    } else if (s[j] == '_') {
      s[j] = '1';
      ans = 10 * traverse(s, j + 1, x);
    } else {
      ans = traverse(s, j + 1, x);
    }
    return ans;
  }
  if (s[j] != 'X' && s[j] != '_') return traverse(s, j + 1, x);
  if (s[j] == 'X' && x != -1) {
    s[j] = '0' + x;
    return traverse(s, j + 1, x);
  }
  if (s[j] == 'X') {
    for (long long int i = (j == 0 ? 1 : 0); i < 10; i++) {
      s[j] = '0' + i;
      ans += traverse(s, j + 1, i);
    }
    return ans;
  }
  if (s[j] == '_') {
    for (long long int i = (j == 0 ? 1 : 0); i < 10; i++) {
      s[j] = '0' + i;
      ans += traverse(s, j, x);
    }
    return ans;
  }
  return ans;
}
long long int check(string s) {
  if (s.size() > 1) return 0;
  for (char i : s)
    if (!(i == '0' || i == 'X' || i == '_')) return 0;
  return 1;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  long long int n = s.size();
  if (s[0] == '0') {
    cout << (s.size() == 1 ? 1 : 0) << "\n";
    return 0;
  }
  long long int ans = check(s);
  ans += traverse(s, 0, -1);
  cout << ans << "\n";
  return 0;
}
