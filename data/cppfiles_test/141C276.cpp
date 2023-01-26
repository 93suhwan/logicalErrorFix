#include <bits/stdc++.h>
using namespace std;
long long powe(long long base, long long rep) {
  if (!rep) return 1;
  long long x = powe(base, rep / 2);
  long long ans = x * x;
  if (rep % 2) ans *= base;
  return ans;
}
long long to_num(string s) {
  long long ans = 0;
  for (int i = (long long)s.size() - 1, cnt = 0; i >= 0; i--, cnt++) {
    ans += (s[i] - '0') * powe(10, cnt);
  }
  return ans;
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    string a, s;
    cin >> a >> s;
    string b = "";
    int p1 = (long long)s.size() - 1;
    int flag = 0;
    for (int i = (long long)a.size() - 1; i >= 0; i--) {
      if (a[i] > s[p1]) {
        if (p1 <= 0) {
          flag = 1;
          break;
        }
        string c = "";
        c += s[p1 - 1];
        c += s[p1];
        p1 -= 2;
        long long x = to_num(c);
        string check = to_string(x - (a[i] - '0'));
        if ((long long)check.size() >= 2) {
          flag = 1;
          break;
        }
        b += check;
      } else {
        if (p1 == -1) {
          flag = 1;
          break;
        }
        b += to_string(s[p1] - a[i]);
        p1--;
      }
    }
    if (flag)
      cout << -1 << "\n";
    else {
      while (p1 >= 0) b += s[p1], p1--;
      reverse(b.begin(), b.end());
      int i = 0;
      for (; i < (long long)b.size(); i++) {
        if (b[i] != '0') break;
      }
      for (; i < (long long)b.size(); i++) cout << b[i];
      cout << "\n";
    }
  }
}
