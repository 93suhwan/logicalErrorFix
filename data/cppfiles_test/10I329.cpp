#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
const long long N = 1e6 + 5;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n + 1);
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<long long> cnt(n + 1, k);
  vector<long long> ans(n + 1, 0);
  long long col = 1;
  for (long long i = 1; i <= n; i++) {
    if (cnt[a[i]] >= 1) {
      ans[i] = col;
      cnt[a[i]]--;
      col++;
      if (col == k + 1) col = 1;
    }
  }
  map<long long, long long> mp;
  for (long long i = 1; i <= n; i++) {
    if (ans[i] == 0) continue;
    ;
    mp[ans[i]]++;
  }
  long long mini = 1e9;
  for (auto i : mp) {
    mini = min(mini, i.second);
  }
  vector<long long> cc(n + 1, mini);
  for (long long i = 1; i <= n; i++) {
    if (ans[i] == 0) continue;
    ;
    if (cc[ans[i]] > 0) {
      cc[ans[i]]--;
    } else {
      ans[i] = 0;
    }
  }
  for (long long i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
