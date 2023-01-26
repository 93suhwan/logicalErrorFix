#include <bits/stdc++.h>
using namespace std;
string bin(long long x) {
  stack<string> st;
  while (x) {
    st.push(to_string(x & 1));
    x /= 2;
  }
  string ret;
  while (!st.empty()) {
    ret += st.top();
    st.pop();
  }
  return ret;
}
bool test(string x, string y) {
  for (int i = 0; i < y.size(); i++) {
    if (y.substr(i, x.size()) == x) {
      for (int j = i; j < i + x.size(); j++) {
        y[j] = '1';
      }
      for (auto j : y) {
        if (j == '0') return false;
      }
      return true;
    }
  }
  return false;
}
int main() {
  long long x, y;
  cin >> x >> y;
  if (x == y) return cout << "YES\n", 0;
  string sx = bin(x), sy = bin(y);
  string ssx(sx);
  while (ssx.back() == '0') ssx.pop_back();
  reverse(ssx.begin(), ssx.end());
  sx += "1";
  bool flag[4] = {false};
  flag[0] = test(sx, sy);
  reverse(sx.begin(), sx.end());
  flag[1] = test(sx, sy);
  flag[2] = test(ssx, sy);
  reverse(ssx.begin(), ssx.end());
  flag[3] = test(ssx, sy);
  if (flag[0] || flag[1] || flag[2] || flag[3]) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
