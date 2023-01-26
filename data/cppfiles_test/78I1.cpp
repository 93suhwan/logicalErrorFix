#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
vector<int> sieve(int n) {
  int *arr = new int[n + 1]();
  vector<int> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (long long j = (long long(i) * long long(i)); j <= n; j += i)
        arr[j] = 1;
    }
  return vect;
}
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
  long long n, k, m, a, b, c, total = 0, sum = 0, mn = INT_MAX, mx = INT_MIN;
  cin >> n;
  vector<long long> arr(n);
  vector<long long> ans;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<vector<long long>> v;
  for (int j = 0; j < n; j++) {
    vector<long long> se;
    for (int i = 1; i <= 30; i++) {
      if (arr[j] & (1 << i)) {
        se.push_back(1);
      } else {
        se.push_back(0);
      }
    }
    v.push_back(se);
  }
  vector<long long> thi;
  for (int i = 0; i < v[0].size(); i++) {
    long long cnt = 0;
    for (int j = 0; j < v.size(); j++) {
      cnt += v[j][i];
    }
    thi.push_back(cnt);
  }
  for (int i = 1; i <= n; i++) {
    bool fl = 1;
    for (int j = 0; j < thi.size(); j++) {
      if (thi[j] % i != 0) {
        fl = 0;
        break;
      }
    }
    if (fl) {
      ans.push_back(i);
    }
  }
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
