#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
inline void debugMode() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
const int N = 2e6 + 6;
const int MOD = 1e9 + 7;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;
int search(int x) {
  if (x > 0) {
    cout << "? ";
    for (int i = 0; i < n - 1; i++) cout << 1 << ' ';
    cout << 1 + x << endl;
  } else {
    x = abs(x);
    cout << "? ";
    for (int i = 0; i < n - 1; i++) cout << 1 + x << ' ';
    cout << 1 << endl;
  }
  int num;
  cin >> num;
  return num;
}
int main() {
  cin >> n;
  set<pair<int, int>> st;
  vector<int> ans(n + 1);
  st.insert({0, n});
  for (int i = 1;; i++) {
    int index = search(i);
    if (index == 0) break;
    st.insert({i, index});
  }
  for (int i = -1;; i--) {
    int index = search(i);
    if (index == 0) break;
    st.insert({i, index});
  }
  int cnt = 1;
  for (auto u : st) ans[u.second] = cnt++;
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
