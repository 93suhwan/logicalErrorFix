#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &os, const vector<T> &p) {
  os << "[ ";
  for (auto &it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const unordered_set<T> &p) {
  os << "[ ";
  for (auto &it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &p) {
  os << "[ ";
  for (auto &it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const multiset<T> &p) {
  os << "[ ";
  for (auto &it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class S, class T>
ostream &operator<<(ostream &os, const unordered_map<S, T> &p) {
  os << "[ ";
  for (auto &it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const map<S, T> &p) {
  os << "[ ";
  for (auto &it : p) os << it << " ";
  return os << "]";
}
template <class T>
void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... S>
void dbs(string str, T t, S... s) {
  long long idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ", ";
  dbs(str.substr(idx + 1), s...);
}
long long cel(long long num, long long den) {
  if (num % den == 0)
    return num / den;
  else
    return 1 + num / den;
}
long long modExp(long long x, long long y, long long mod) {
  x %= mod, y %= (mod - 1);
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % mod;
    y /= 2, x = (x * x) % mod;
  }
  return res % mod;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long testcases = 1;
  cin >> testcases;
  for (long long testcase = 1; testcase <= testcases; testcase++) {
    string s;
    cin >> s;
    long long n = s.length(), count = 0;
    for (long long i = 0; i < n;) {
      while (i < n and s[i] == '1') i++;
      if (i == n or count >= 2) break;
      count++;
      while (i < n and s[i] == '0') i++;
    }
    cout << min(count, (long long)(2)) << endl;
  }
  return 0;
}
