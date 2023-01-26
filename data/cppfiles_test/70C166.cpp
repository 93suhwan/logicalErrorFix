#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
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
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
bool revsort(long long a, long long b) { return a > b; }
const int MAXN = 1e9 + 5;
vector<int> a;
void solve() {
  string t;
  cin >> t;
  bool vis[26];
  int n = ((int)(t).size());
  for (int i = 0; i < int(26); ++i) vis[i] = false;
  map<char, int> mpp;
  vector<char> uniq;
  for (int i = n - 1; i >= 0; i--) {
    if (!(vis[t[i] - 'a'])) {
      vis[t[i] - 'a'] = true;
      uniq.push_back(t[i]);
    }
    mpp[t[i]]++;
  }
  reverse((uniq).begin(), (uniq).end());
  int len = 0;
  for (int i = 1; i <= ((int)(mpp).size()); ++i) {
    if (mpp[uniq[i - 1]] % i) {
      cout << -1 << '\n';
      return;
    }
    len += mpp[uniq[i - 1]] / i;
  }
  string ans = t.substr(0, len);
  string chk(ans);
  string s;
  for (int i = 0; i < ((int)(mpp).size()); ++i) {
    s += chk;
    string temp;
    for (int j = 0; j < ((int)(chk).size()); j++) {
      if (chk[j] != uniq[i]) {
        temp += chk[j];
      }
    }
    chk = temp;
  }
  if (s != t) {
    cout << -1 << '\n';
    return;
  }
  string order;
  for (int i = 0; i < ((int)(mpp).size()); ++i) {
    order += uniq[i];
  }
  cout << ans << " " << order << '\n';
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
