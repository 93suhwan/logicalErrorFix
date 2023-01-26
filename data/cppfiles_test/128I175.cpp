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
int mod_add(int a, int b, int m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
int mod_mul(int a, int b, int m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
int mod_sub(int a, int b, int m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
const long long mxm = 2 * 1e5;
long long M = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
long long expo(long long a, long long b, long long m) {
  if (b == 0) {
    return 1;
  }
  if (b % 2 == 0) {
    long long temp = expo(a, b / 2, m);
    return (temp % m * temp % m) % m;
  } else {
    long long temp = expo(a, b / 2, m);
    return (a % m * temp % m * temp % m) % m;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long c = 1;
    long long a, b;
    if ((n - 1) % 2 == 0) {
      a = (n - 1) / 2 + 1;
      b = (n - 1) / 2 - 1;
      if (a % 2 == 0) {
        c = 3;
        a = (n - 3) / 2 + 1;
        b = (n - 3) / 2 - 1;
      }
    } else {
      a = (n - 1) / 2;
      b = (n - 1) - (n - 1) / 2;
    }
    cout << a << ' ' << b << ' ' << c << "\n";
  }
  return 0;
}
