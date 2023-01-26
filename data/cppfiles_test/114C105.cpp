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
  long long n;
  cin >> n;
  vector<vector<long long>> a;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    vector<long long> temp(x);
    for (long long j = 0; j < x; j++) cin >> temp[j];
    a.push_back(temp);
  }
  set<vector<long long>> vis;
  set<vector<long long>> banned;
  long long m;
  cin >> m;
  for (long long i = 0; i < m; i++) {
    vector<long long> temp(n);
    for (long long j = 0; j < n; j++) {
      cin >> temp[j];
      temp[j]--;
    }
    banned.insert(temp);
  }
  set<pair<long long, vector<long long>>> st;
  long long s = 0;
  vector<long long> temp;
  for (long long i = 0; i < n; i++) {
    s += a[i][(long long)a[i].size() - 1];
    temp.push_back((long long)a[i].size() - 1);
  }
  st.insert({s, temp});
  vis.insert(temp);
  while (!st.empty()) {
    auto [val, vec] = *prev(st.end());
    st.erase(prev(st.end()));
    if (banned.find(vec) == banned.end()) {
      for (auto i : vec) cout << i + 1 << " ";
      return;
    }
    for (long long i = 0; i < n; i++) {
      if (vec[i] - 1 >= 0) {
        long long newval = val - a[i][vec[i]] + a[i][vec[i] - 1];
        vector<long long> newvec = vec;
        newvec[i]--;
        if (vis.find(newvec) == vis.end()) {
          st.insert({newval, newvec});
          vis.insert(newvec);
        }
      }
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
}
