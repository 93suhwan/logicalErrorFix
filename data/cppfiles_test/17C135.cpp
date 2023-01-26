#include <bits/stdc++.h>
using namespace std;
long double EPS = 1e-9;
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
long long cel(long long a, long long b) {
  if (a <= 0) return a / b;
  return ((a - 1) / b + 1);
}
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  return (b == 0) ? a : gcd(b, a % b);
}
long long MIN(long long a, int b) {
  long long ans;
  (a >= b) ? ans = b : ans = a;
  return ans;
}
long long MAX(long long a, int b) {
  long long ans;
  (a >= b) ? ans = a : ans = b;
  return ans;
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long po(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) {
      ans = (ans * x) % 1000000007;
    }
    y >>= 1;
    x = (x * x) % 1000000007;
  }
  return ans;
}
vector<int> cnt(200005, 0);
void merge(int l, int r, int k, vector<int> &v, vector<int> &C) {
  vector<int> temp(k - l + 2, 0);
  int p1 = l, p2 = r, p = 0;
  while (p1 <= (r - 1) && p2 <= k) {
    if (v[C[p2]] < v[C[p1]]) {
      cnt[C[p2]] += (r - p1);
      temp[p] = C[p2];
      p++;
      p2++;
    } else {
      temp[p] = C[p1];
      p++;
      p1++;
    }
  }
  while (p1 <= (r - 1)) {
    temp[p] = C[p1];
    p++;
    p1++;
  }
  while (p2 <= k) {
    temp[p] = C[p2];
    p++;
    p2++;
  }
  for (int i = l; i < k + 1; i++) {
    C[i] = temp[i - l];
  }
}
void merges(int i, int j, vector<int> &v, vector<int> &C) {
  int m = (i + j) / 2;
  if (i == j) return;
  merges(i, m, v, C);
  merges(m + 1, j, v, C);
  merge(i, m + 1, j, v, C);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, t, x, y, k, m;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> v(n), C(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      C[i] = i;
    }
    merges(0, n - 1, v, C);
    long long ans = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      int g = cnt[i], l = i - (cnt[i] + mp[v[i]]);
      mp[v[i]]++;
      ans += min(g, l);
    }
    cout << ans << "\n";
    for (int i = 0; i < n + 1; i++) cnt[i] = 0;
  }
  return 0;
}
