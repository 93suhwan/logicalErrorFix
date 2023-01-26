#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
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
inline long long mod(long long x) {
  return (x % 1000000007 + 1000000007) % 1000000007;
}
inline long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
inline long long sub(long long a, long long b) {
  return mod(mod(a) - mod(b) + 1000000007);
}
inline long long mul(long long a, long long b) { return mod(mod(a) * mod(b)); }
inline long long power(long long a, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = mul(r, a);
    a = mul(a, a);
    p >>= 1;
  }
  return r;
}
inline long long modInv(long long a) { return power(a, 1000000007 - 2); }
inline long long divi(long long a, long long b) { return mul(a, modInv(b)); }
inline long long fact(long long a) {
  long long r = 1;
  while (a) {
    r = mul(r, a);
    a--;
  }
  return r;
}
inline long long ncr(long long n, long long r) {
  return mul(mul(fact(n), modInv(fact(n - r))), modInv(fact(r)));
}
inline long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}
inline long long ceil(long long x, long long y) {
  if (x % y == 0) {
    return x / y;
  }
  return x / y + 1;
}
void solve() {
  vector<long long> arr(3);
  for (long long i = 0; i < 3; i++) cin >> arr[i];
  sort((arr).begin(), (arr).end());
  if (arr[2] == (arr[0] + arr[1])) {
    cout << "YES"
         << "\n";
  } else {
    if (arr[0] == arr[1] and arr[2] % 2 == 0) {
      cout << "YES"
           << "\n";
    } else if (arr[1] == arr[2] and arr[0] % 2 == 0) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
