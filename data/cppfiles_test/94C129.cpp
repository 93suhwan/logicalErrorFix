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
void JAI_SHREE_RAM() {
  long long n, k;
  cin >> n >> k;
  k++;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ;
  ;
  long long ans = 0;
  long long val = 0;
  for (int i = 1; i < n; i++) {
    long long p = 1;
    long long v = a[i - 1];
    for (int i = 0; i < v; i++) {
      p *= 10;
    };
    long long dif = a[i] - a[i - 1];
    long long x = 9;
    for (int i = 1; i < dif; i++) x = x * 10 + 9;
    ans += x;
    if (k >= ans) {
      val += p * x;
    } else {
      ans -= x;
      long long y = abs(k - ans);
      val += p * y;
      cout << val << "\n";
      return;
    }
  }
  long long rem = (k - ans);
  ;
  long long p = 1;
  for (int i = 0; i < a[n - 1]; i++) p *= 10;
  val += rem * p;
  cout << val << "\n";
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
