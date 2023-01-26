#include <bits/stdc++.h>
using namespace std;
void show(long long t) { cerr << t; }
void show(int t) { cerr << t; }
void show(string t) { cerr << t; }
void show(char t) { cerr << t; }
void show(long double t) { cerr << t; }
void show(double t) { cerr << t; }
void show(unsigned long long t) { cerr << t; }
template <class Y, class V>
void show(pair<Y, V> p);
template <class Y>
void show(vector<Y> v);
template <class Y>
void show(set<Y> v);
template <class Y>
void show(multiset<Y> v);
template <class Y, class V>
void show(map<Y, V> v);
template <class Y, class V>
void show(pair<Y, V> p) {
  cerr << "{";
  show(p.first);
  cerr << ",";
  show(p.second);
  cerr << "}";
}
template <class Y>
void show(set<Y> v) {
  cerr << "[ ";
  for (Y i : v) {
    show(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class Y>
void show(vector<Y> v) {
  cerr << "[ ";
  for (Y i : v) {
    show(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class Y, class V>
void show(map<Y, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    show(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class Y>
void show(multiset<Y> v) {
  cerr << "[ ";
  for (Y i : v) {
    show(i);
    cerr << " ";
  }
  cerr << "]";
}
template <typename Head, typename... Tail>
void show(Head H, Tail... T) {
  cerr << H << ' ';
  show(T...);
}
const long long inf = 1e18;
const long long mod = 1e9 + 7;
const long long N = 2e5 + 1;
bool ispalin(string s) {
  long long len = s.length();
  for (long long i = 0; i < len; i++) {
    if (s[i] != s[len - i - 1]) {
      return false;
    }
  }
  return true;
}
long long add(long long a, long long b, long long m) {
  long long res = (a % m + b % m) % m;
  if (res < 0) {
    res += m;
  }
  return res;
}
long long mul(long long a, long long b, long long m) {
  long long res = (a % m * b % m) % m;
  if (res < 0) {
    res += m;
  }
  return res;
}
long long power(long long a, long long b, long long m) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a, m);
    }
    a = mul(a, a, m);
    b >>= 1;
  }
  return res % m;
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a);
    }
    a = (a * a);
    b >>= 1;
  }
  return res;
}
long long binpow(long long a, long long b, long long m) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % m;
    }
    a = (a * a) % m;
    b >>= 1;
  }
  return res % m;
}
bool isprime(long long n) {
  if (n <= 1) {
    return false;
  }
  if (n <= 3) {
    return true;
  }
  if (n % 2 == 0 || n % 3 == 0) {
    return false;
  }
  for (long long i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
long long lcm(long long a, long long b) {
  long long l = (a * b) / gcd(a, b);
  return l;
}
long long CEIL(long long a, long long b) { return (a / b + (a % b != 0)); }
long long inv(long long a, long long m) { return power(a, m - 2, m); }
long long C(long long n, long long r) {
  if (n < r) return 0;
  if (n == r) return 1;
  if (r > n - r) r = n - r;
  long long ans = 1;
  for (long long i = 1; i <= r; i++) ans *= n - r + i, ans /= i;
  return ans;
}
bool isPowerOfTwo(long long x) { return x && (!(x & (x - 1))); }
bool isPerfectSq(long long x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
long long fact(long long n, long long m) {
  long long f = 1;
  for (long long i = 1; i <= n; i++) f = (f * i) % m;
  return f % m;
}
long long fact_pow(long long n, long long k) {
  long long res = 0;
  while (n) {
    n /= k;
    res += n;
  }
  return res;
}
void solve() {
  long long c, d;
  cin >> c >> d;
  if (c < d) swap(c, d);
  if ((c - d) % 2)
    cout << "-1" << '\n';
  else if (c == 0 && d == 0)
    cout << "0" << '\n';
  else if (c == d)
    cout << "1" << '\n';
  else
    cout << "2" << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
