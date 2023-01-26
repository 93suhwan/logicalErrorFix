#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
const long long mod = 1e9 + 7;
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
void _print(unordered_set<T> v) {
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
  if (a > b) {
    return gcd(b, a);
  }
  if (a == 0) {
    return b;
  }
  return gcd(a, b % a);
}
int __gcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = __gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long binary_ex(long long a, long long b, long long m) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = (ans * 1LL * a) % m;
    }
    a = (a * 1LL * a) % m;
    b >>= 1;
  }
  return ans;
}
void pleaseAC() {
  vector<long long> arr(7);
  for (long long i = (0); i < (7); ++i) {
    cin >> arr[i];
  }
  cout << arr[0] << " " << arr[1] << " " << arr[6] - (arr[0] + arr[1]) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    pleaseAC();
  }
  return 0;
}
