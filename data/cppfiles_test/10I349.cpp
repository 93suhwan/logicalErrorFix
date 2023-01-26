#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
const long long MOD = 998244353;
const double EPS = 1e-8;
const double PI = acos(-1.0);
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
void solve() {
  int n, k;
  cin >> n >> k;
  map<int, int> mp, m2;
  vector<int> arr(n), ans(n);
  for (int i = 0; i < n; ++i) cin >> arr[i];
  for (int i = 0; i < n; ++i) {
    if (mp.find(arr[i]) == mp.end()) {
      ans[i] = 1;
      mp[arr[i]] = 2;
    } else {
      if (mp[arr[i]] > k) {
        ans[i] = -1;
      } else {
        ans[i] = mp[arr[i]];
        mp[arr[i]]++;
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    if (ans[i] != -1) cnt++;
  cnt = cnt / k;
  cnt = cnt * k;
  ;
  ;
  int p = cnt / k;
  int c = 0;
  vector<int> f(k + 1);
  for (int i = 0; i < n; ++i) {
    if (ans[i] == -1 || cnt <= 0) {
      ans[i] = -1;
      continue;
    }
    ans[i] = c++;
    f[ans[i] + 1]++;
    c %= (k);
    ;
    cnt--;
  }
  for (int i = 1; i <= k; ++i) {
    assert(f[i] == p);
  }
  for (int i = 0; i < n; ++i) cout << ans[i] + 1 << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
