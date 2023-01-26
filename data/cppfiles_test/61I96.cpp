#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long int t) { cerr << t; }
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
template <typename T>
T exgcd(T a, T b, T &x, T &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  T x1, y1;
  T d = exgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
template <typename T>
T modpow(T x, T n, T p) {
  if (n == 0) return 1 % p;
  T y = 0;
  if (n % 2 == 0) {
    y = modpow(x, n / 2, p);
    y = (y * y) % p;
  } else {
    y = x % p;
    y = (y * modpow(x, n - 1, p)) % p;
  }
  return (int)((y + p) % p);
}
template <typename T>
T modinv(T a, T m) {
  T x, y;
  exgcd(a, m, x, y);
  return (x % m + m) % m;
}
template <typename T>
bool isPrime(T n) {
  if (n < 2) return 0;
  if (n <= 3) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  for (T i = 5; i * i <= n; i += 6)
    if ((n % i) == 0 || (n % (i + 2)) == 0) return 0;
  return 1;
}
const long long maxNN = 100005;
long long fact[maxNN];
void pre(long long M) {
  fact[0] = 1;
  for (int i = 1; i < maxNN; i++) fact[i] = (i * fact[i - 1]) % M;
}
long long nCr(long long n, long long r, long long M) {
  long long ans = 1;
  ans = (ans * fact[n]) % M;
  ans = (ans * modinv(fact[n - r], M)) % M;
  ans = (ans * modinv(fact[r], M)) % M;
  return M;
}
void func() {
  long long n;
  cin >> n;
  string str;
  cin >> str;
  string ans = "";
  for (int i = 0; i < n; i++) {
    if (str[i] == '?') {
      if (i == 0) {
        if (str[i + 1] == 'B') {
          ans += 'R';
          str[i] = 'R';
        } else if (str[i + 1] == 'R') {
          ans += 'B';
          str[i] = 'B';
        } else {
          ans += 'B';
          str[i] = 'B';
        }
      } else if (i == n - 1) {
        if (str[i - 1] == 'B') {
          ans += 'R';
          str[i] = 'R';
        } else if (str[i - 1] == 'R') {
          ans += 'B';
          str[i] = 'B';
        } else {
          ans += 'B';
          str[i] = 'B';
        }
      } else {
        if (str[i - 1] == 'B' && str[i + 1] == 'R') {
          ans += 'B';
          str[i] = 'B';
        } else if (str[i - 1] == 'B' && str[i + 1] == 'B') {
          ans += 'R';
          str[i] = 'R';
        } else if (str[i - 1] == 'B' && str[i + 1] == '?') {
          ans += 'R';
          str[i] = 'R';
        } else if (str[i - 1] == 'R' && str[i + 1] == 'B') {
          ans += 'R';
          str[i] = 'R';
        } else if (str[i - 1] == 'R' && str[i + 1] == 'R') {
          ans += 'B';
          str[i] = 'B';
        } else if (str[i - 1] == 'R' && str[i + 1] == '?') {
          ans += 'B';
          str[i] = 'B';
        }
      }
    } else
      ans += str[i];
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) func();
}
