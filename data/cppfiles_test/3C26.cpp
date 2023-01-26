#include <bits/stdc++.h>
using namespace std;
using VI = vector<int>;
int n;
string s;
int f(int i) {
  if (i == -1) return (n == 1 and s[0] == '0') or (n > 1 and s[0] != '0');
  int res = 0;
  if (i == n - 1) {
    if (isdigit(s[i])) {
      if (s[i] != '0' and s[i] != '5') return 0;
      return f(i - 1);
    } else {
      s[i] = '0';
      res += f(i - 1);
      s[i] = '5';
      res += f(i - 1);
      s[i] = '_';
    }
  } else if (i == n - 2) {
    if (s[n - 1] == '0') {
      if (isdigit(s[i])) {
        if (s[i] != '0' and s[i] != '5') return 0;
        return f(i - 1);
      } else {
        s[i] = '0';
        res += f(i - 1);
        s[i] = '5';
        res += f(i - 1);
        s[i] = '_';
      }
    } else {
      if (isdigit(s[i])) {
        if (s[i] != '2' and s[i] != '7') return 0;
        return f(i - 1);
      } else {
        s[i] = '2';
        res += f(i - 1);
        s[i] = '7';
        res += f(i - 1);
        s[i] = '_';
      }
    }
  } else {
    if (isdigit(s[i]))
      return f(i - 1);
    else {
      for (char c = '0'; c <= '9'; ++c) {
        s[i] = c;
        res += f(i - 1);
      }
      s[i] = '_';
    }
  }
  return res;
}
int main() {
  cin >> s;
  n = s.size();
  VI V;
  for (int i = 0; i < n; ++i)
    if (s[i] == 'X') V.push_back(i);
  if (V.empty())
    cout << f(n - 1) << endl;
  else {
    int res = 0;
    for (char c = '0'; c <= '9'; ++c) {
      for (int x : V) s[x] = c;
      res += f(n - 1);
    }
    cout << res << endl;
  }
}
