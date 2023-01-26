#include <bits/stdc++.h>
using namespace std;
long long a, b;
string s, t;
bool chk(string s) {
  int ss = 0;
  for (auto c : s) ss += c == 0;
  for (auto c : t) ss -= c == 0;
  if (ss) return 0;
  if (t.find(s) != t.npos) return 1;
  return 0;
}
int main() {
  cin >> a >> b;
  if (a == b) {
    cout << "YES\n";
    return 0;
  }
  while (a) s.push_back(a & 1), a >>= 1;
  while (b) t.push_back(b & 1), b >>= 1;
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  if (!t.back()) {
    cout << "NO\n";
    return 0;
  }
  string ss = s;
  ss.push_back(1);
  if (chk(ss)) {
    cout << "YES\n";
    return 0;
  }
  reverse(ss.begin(), ss.end());
  if (chk(ss)) {
    cout << "YES\n";
    return 0;
  }
  while (!s.back()) s.pop_back();
  if (chk(s)) {
    cout << "YES\n";
    return 0;
  }
  reverse(s.begin(), s.end());
  if (chk(s)) {
    cout << "YES\n";
    return 0;
  }
  cout << "NO\n";
}
