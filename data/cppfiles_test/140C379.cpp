#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void _print(long long int t) { cerr << t; }
void _print(bool t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(deque<T> v);
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
void _print(deque<T> v) {
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
template <class T, class V>
void _print(multimap<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
const long long int inf = 1e18;
long long int mod_add(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long int mod_mul(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long int mod_sub(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
vector<long long int> sieve(long long int n) {
  long long int *arr = new long long int[n + 1]();
  vector<long long int> vect;
  for (long long int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (long long int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
template <class T>
T gcd(T a, T b) {
  while (a != 0) {
    T temp = a;
    a = b % a;
    b = temp;
  }
  return b;
}
template <class T>
T egcd(T a, T b, T &x, T &y) {
  T gcd, xt, yt;
  if (a == 0) {
    gcd = b;
    x = 0, y = 1;
  } else {
    gcd = egcd(b % a, a, xt, yt);
    x = yt - (b / a) * xt;
    y = xt;
  }
  return gcd;
}
template <class T>
T expo(T base, T exp) {
  T res = 1;
  base = base % 1000000007;
  while (exp > 0) {
    if (exp & 1) res = (res * base) % 1000000007;
    exp = exp >> 1;
    base = (base * base) % 1000000007;
  }
  return res;
}
template <class T>
T modinv(T a) {
  T x, y;
  egcd<T>(a, 1000000007, x, y);
  while (x < 0) x += 1000000007;
  while (x >= 1000000007) x -= 1000000007;
  return x;
}
template <class T>
T modinvfermat(T a) {
  return expo<T>(a, 1000000007 - 2, 1000000007);
}
template <class T>
bool rev(T a, T b) {
  return a > b;
}
template <class T>
long long int maxpower(T a, T b) {
  long long int ans = 0;
  while (a > 0 && a % b == 0) {
    ans++;
    a /= b;
  }
  return ans;
}
template <class T>
T mceil(T a, T b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
template <class T>
T lcm(T a, T b) {
  return (a * b) / gcd<T>(a, b);
}
void solve() {
  long long int n;
  cin >> n;
  long long int res = 0;
  set<long long int> r;
  for (long long int i = 1; i * i <= n; i++) {
    r.insert(i * i);
  }
  for (long long int i = 1; i * i * i <= n; i++) {
    r.insert(i * i * i);
  }
  cout << r.size() << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int test_case = 1;
  cin >> test_case;
  for (long long int _ = 1; _ <= test_case; _++) {
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
  }
  return 0;
}
