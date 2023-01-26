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
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long mexpo(long long a, long long b, long long m) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b = b >> 1;
  }
  return res;
}
vector<int> prime;
void seive(long long n) {
  int lp[n + 1];
  for (int i = 2; i <= n; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      prime.push_back(i);
    }
    for (int j = 0;
         j < (int)prime.size() && prime[j] <= lp[i] && i * prime[j] <= n; ++j)
      lp[i * prime[j]] = prime[j];
  }
}
int main() {
  clock_t begin = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int T;
  cin >> T;
  while (T--) {
    int m;
    cin >> m;
    int a[m], b[m];
    for (int i = 0; i <= m - 1; i++) {
      cin >> a[i];
    }
    for (int i = 0; i <= m - 1; i++) {
      cin >> b[i];
    }
    int sufa[m], prefb[m];
    sufa[m - 1] = 0;
    prefb[0] = 0;
    for (int i = m - 2; i >= 0; i--) {
      sufa[i] = sufa[i + 1] + a[i + 1];
    }
    for (int i = 1; i <= m - 1; i++) {
      prefb[i] = prefb[i - 1] + b[i - 1];
    }
    int idx = -1;
    int i = 0;
    int val = 0;
    int total = INT_MAX;
    while (i < m) {
      if (min(total, max(prefb[i], sufa[i])) != total) {
        total = max(prefb[i], sufa[i]);
        idx = i;
      }
      i++;
    }
    total = max(prefb[idx], sufa[idx]);
    cout << total << "\n";
  }
  return 0;
}
