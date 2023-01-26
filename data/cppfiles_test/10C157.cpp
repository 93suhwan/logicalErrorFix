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
bool cmp(vector<long long> &a, vector<long long> &b) {
  return (long long)a.size() > (long long)b.size();
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n + 1);
  vector<vector<long long>> aa(n + 1);
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    aa[a[i]].push_back(i);
  }
  sort(aa.begin(), aa.end(), cmp);
  long long col = 1;
  vector<long long> ans(n + 1, 0);
  for (auto i : aa) {
    long long cnt = 0;
    for (auto j : i) {
      ans[j] = col;
      col++;
      cnt++;
      if (col == k + 1) {
        col = 1;
      }
      if (cnt == k) break;
    }
  }
  map<long long, long long> cc;
  for (long long i = 1; i <= n; i++) {
    if (ans[i] != 0) cc[ans[i]]++;
  }
  long long mini = 1e9;
  for (auto i : cc) {
    mini = min(mini, i.second);
  }
  vector<long long> cntt(n + 1, 0);
  for (long long i = 1; i <= n; i++) {
    if (cntt[ans[i]] < mini) {
      cntt[ans[i]]++;
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
