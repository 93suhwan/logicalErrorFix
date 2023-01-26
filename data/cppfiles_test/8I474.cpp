#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int INF = 1e9;
void _print(long long int a) { cerr << a; }
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
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
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
void swap(long long int &x, long long int &y) {
  long long int temp = x;
  x = y;
  y = temp;
}
long long int gcd(long long int a, long long int b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
void sieve(long long int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long int p = 2; p <= n; p++)
    if (prime[p]) cout << p << " ";
}
long long int fastExp(long long int b, long long int e, long long int m) {
  long long int result = e & 1 ? b : 1;
  while (e) {
    e >>= 1;
    b = (b * b) % m;
    if (e & 1) result = (result * b) % m;
  }
  return result;
}
long long int bin_search(long long int b, long long int n, long long int a[]) {
  long long int low = 0;
  long long int high = n;
  while (low < high) {
    long long int mid = (low + high) / 2;
    if (a[mid] <= b) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return low;
}
bool is_sqr(long long int x) {
  long long int y = (long long int)(sqrt(x) + 0.5);
  return y * y == x;
}
bool isPrime(long long int n) {
  for (long long int i = 2; i <= n / 2; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void solve() {
  long long int n;
  cin >> n;
  if (n % 3 == 0) {
    cout << n / 3 << " " << n / 3 << endl;
  } else
    cout << n / 3 << " " << n / 3 + 1 << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
