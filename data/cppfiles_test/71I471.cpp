#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &os, const vector<T> &p) {
  os << "[";
  for (auto &it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
  return os << "(" << p.first << "," << p.second << ")";
}
template <class T>
bool umin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool umax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
void stugs() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
vector<string> ans;
void recur1(string s, char a, long long int x) {
  if (s.length() == x) {
    ans.push_back(s);
    return;
  }
  recur1(s += a, a, x);
}
void recur2(string s, char a, char b, long long int x) {
  if (s.length() == x) {
    ans.push_back(s);
    return;
  }
  string s1 = s, s2 = s;
  s1 += a;
  s2 += b;
  recur2(s1, a, b, x);
  recur2(s2, a, b, x);
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  ans.clear();
  string s = to_string(n);
  long long int x = s.length();
  string str = "";
  str += s[0];
  if (k == 1) {
    recur1(str, s[0], x);
  } else {
    for (char i = '0'; i <= '9'; i++) {
      recur2(str, s[0], i, x);
    }
  }
  {};
  long long int mn = 1e12, cn = 0;
  for (long long int i = 0; i < ans.size(); i++) {
    long long int x = stoi(ans[i].substr(0, ans[i].length()));
    if (x >= n) {
      long long int y = x - n;
      if (y < mn) {
        mn = y;
        cn = x;
      }
    }
  }
  cout << cn << endl;
}
int32_t main() {
  stugs();
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
