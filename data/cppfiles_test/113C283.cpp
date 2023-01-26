#include <bits/stdc++.h>
#pragma GCC optimize("-O2")
using namespace std;
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
template <typename T, typename U>
istream& operator>>(istream& is, pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U> p) {
  os << p.first << ' ' << p.second;
  return os;
}
long long digits(long long a) {
  long long d = 0;
  while (a) {
    a /= 10;
    d++;
  }
  return d;
}
void solve() {
  long long x1, x2, p1, p2, s1 = 0, s2 = 0;
  cin >> x1 >> p1 >> x2 >> p2;
  s1 = digits(x1);
  s2 = digits(x2);
  if (s1 + p1 < s2 + p2) {
    cout << "<";
    return;
  } else if (s1 + p1 > s2 + p2) {
    cout << ">";
    return;
  }
  bool order = true;
  if (x1 > x2) {
    swap(x1, x2);
    swap(s1, s2);
    order = false;
  }
  while (s1 != s2) {
    x1 *= 10;
    s1++;
  }
  if (x1 < x2) {
    cout << (order ? "<" : ">");
  } else if (x1 == x2) {
    cout << (order ? "=" : "=");
  } else if (x1 > x2) {
    cout << (order ? ">" : "<");
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  cin >> T;
  for (long long i = 0; i < T - 1; i++) {
    solve();
    cout << '\n';
  }
  solve();
  return 0;
}
