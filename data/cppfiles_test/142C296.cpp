#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 4;
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
long long po(long long x, long long n) {
  long long ans = 1;
  while (n) {
    if (n % 2 == 1) ans = ans * x;
    x = x * x;
    n = n / 2;
  }
  return ans;
}
long long lo(long long k) {
  long long ans = 0;
  while (k > 1) {
    k = k / 2;
    ans++;
  }
  return ans;
}
void JAI_SHREE_RAM() {
  long long n, m;
  cin >> n >> m;
  vector<vector<long long>> a(n, vector<long long>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  long long ch = m - 1;
  if (ch >= n) {
    long long ans = LLONG_MAX;
    for (int i = 0; i < m; i++) {
      long long mx = -100000000000000ll;
      for (int j = 0; j < n; j++) {
        mx = max(a[j][i], mx);
      }
      ans = min(ans, mx);
    }
    cout << ans << "\n";
    return;
  }
  vector<pair<long long, long long>> p;
  long long row = 0;
  long long val = -100000000000000ll;
  for (int i = 0; i < n; i++) {
    vector<pair<long long, long long>> v;
    for (int j = 0; j < m; j++) {
      v.push_back({a[i][j], j});
    }
    sort(v.begin(), v.end(), greater<pair<long long, long long>>());
    if (v[1].first > val) {
      val = v[1].first;
      row = i;
    }
  }
  set<long long> col;
  vector<pair<long long, long long>> temp;
  for (int i = 0; i < m; i++) temp.push_back({a[row][i], i});
  sort(temp.begin(), temp.end(), greater<pair<long long, long long>>());
  col.insert(temp[0].second);
  col.insert(temp[1].second);
  ;
  long long ans = min(temp[1].first, temp[0].first);
  ;
  ;
  for (int i = 0; i < m; i++) {
    if (col.find(i) != col.end()) continue;
    long long mx = -100000000000000ll;
    for (int j = 0; j < n; j++) {
      mx = max(a[j][i], mx);
    }
    ans = min(ans, mx);
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt = 1;
  cin >> tt;
  for (int i = 1; i < tt + 1; i++) {
    JAI_SHREE_RAM();
  }
}
