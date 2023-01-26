#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000")
using namespace std;
template <class T>
ostream &operator<<(ostream &out, vector<T> v) {
  bool first = true;
  for (auto &it : v) {
    out << (first ? "" : " ") << it;
    first = false;
  }
  return out;
}
template <class T>
ostream &operator<<(ostream &out, set<T> s) {
  bool first = true;
  for (auto &it : s) {
    out << (first ? "" : " ") << it;
    first = false;
  }
  return out;
}
template <class T, class Q>
ostream &operator<<(ostream &out, pair<T, Q> p) {
  out << p.first << " " << p.second;
  return out;
}
string to_string(string s) { return "\"" + s + "\""; }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(vector<A> v) {
  string s = "{";
  if (!v.empty()) s += to_string(v.front());
  for (int(i) = (1); (i) < (v.size()); (i)++) s += " ," + to_string(v[i]);
  s += "}";
  return s;
}
template <typename A, typename B>
string to_string(map<A, B> mp) {
  string s = "{";
  bool first = true;
  for (auto p : mp) {
    if (!first) s += ", ";
    first = false;
    s += to_string(p);
  }
  s += "}";
  return s;
}
template <typename A>
string to_string(set<A> st) {
  string s = "{";
  bool first = true;
  for (auto p : st) {
    if (!first) s += ", ";
    first = false;
    s += to_string(p);
  }
  s += "}";
  return s;
}
void initiate() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
bool can(vector<long long> v, long long mid) {
  vector<long long> b(v.size(), 0);
  for (int i = v.size() - 1; i >= 2; i--) {
    if (v[i] + b[i] < mid) return false;
    long long rem = (b[i] + v[i]) - mid;
    rem = min(v[i], rem);
    long long div = rem / 3;
    b[i - 2] += 2 * div;
    b[i - 1] += div;
  }
  if (v[0] + b[0] < mid || v[1] + b[1] < mid) return false;
  return true;
}
int main() {
  initiate();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int(i) = 0; (i) < (n); (i)++) cin >> v[i];
    long long low = 0;
    long long high = 1LL << 60;
    while (low < high) {
      long long mid = (low + high + 1) / 2;
      if (can(v, mid))
        low = mid;
      else
        high = mid - 1;
    }
    cout << low << '\n';
  }
}
