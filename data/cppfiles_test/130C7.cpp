#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
const long long MAX_N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long etf(long long n) {
  if (n == 1) return 1;
  long long phi = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      phi = phi - phi / i;
    }
  }
  if (n > 1) phi = phi - phi / n;
  return phi;
}
void solve() {
  long long n;
  cin >> n;
  long long a[n + 1];
  long long b[n + 1];
  memset(a, -1, sizeof(a));
  ;
  memset(b, 0, sizeof(b));
  ;
  long long x = 0, im = 0, cr = 0;
  for (long long i = 1; i <= n; i += 3) {
    cout << '?' << ' ' << i << ' ' << i + 1 << ' ' << i + 2 << endl;
    cin >> a[i];
  }
  for (long long i = 1; i <= n - 3; i += 3) {
    if (a[i] != a[i + 3]) {
      cout << '?' << ' ' << i + 1 << ' ' << i + 2 << ' ' << i + 3 << endl;
      cin >> a[i + 1];
      cout << '?' << ' ' << i + 2 << ' ' << i + 3 << ' ' << i + 4 << endl;
      cin >> a[i + 2];
      if (a[i] != a[i + 1]) {
        if (a[i]) {
          cr = i;
          im = i + 3;
        } else {
          cr = i + 3;
          im = i;
        }
      }
      if (a[i + 1] != a[i + 2]) {
        if (a[i + 1]) {
          cr = i + 1;
          im = i + 4;
        } else {
          cr = i + 4;
          im = i + 1;
        }
      }
      if (a[i + 2] != a[i + 3]) {
        if (a[i]) {
          cr = i + 2;
          im = i + 5;
        } else {
          cr = i + 5;
          im = i + 2;
        }
      }
      break;
    }
  }
  b[cr] = 1;
  for (long long i = 1; i <= n; i += 3) {
    if (i == cr || i == im) {
      cout << '?' << ' ' << im << ' ' << cr << ' ' << i + 1 << endl;
      cin >> b[i + 1];
      cout << '?' << ' ' << im << ' ' << cr << ' ' << i + 2 << endl;
      cin >> b[i + 2];
      continue;
    }
    if (i + 1 == cr || i + 1 == im) {
      cout << '?' << ' ' << im << ' ' << cr << ' ' << i << endl;
      cin >> b[i];
      cout << '?' << ' ' << im << ' ' << cr << ' ' << i + 2 << endl;
      cin >> b[i + 2];
      continue;
    }
    if (i + 2 == cr || i + 2 == im) {
      cout << '?' << ' ' << im << ' ' << cr << ' ' << i << endl;
      cin >> b[i];
      cout << '?' << ' ' << im << ' ' << cr << ' ' << i + 1 << endl;
      cin >> b[i + 1];
      continue;
    }
    if (a[i]) {
      long long x, y;
      cout << '?' << ' ' << im << ' ' << i << ' ' << i + 1 << endl;
      cin >> x;
      if (x) {
        b[i] = 1;
        b[i + 1] = 1;
        cout << '?' << ' ' << im << ' ' << cr << ' ' << i + 2 << endl;
        cin >> b[i + 2];
      } else {
        b[i + 2] = 1;
        cout << '?' << ' ' << im << ' ' << cr << ' ' << i << endl;
        cin >> y;
        if (y) {
          b[i] = 1;
          b[i + 1] = 0;
        } else {
          b[i] = 0;
          b[i + 1] = 1;
        }
      }
    } else {
      long long x, y;
      cout << '?' << ' ' << cr << ' ' << i << ' ' << i + 1 << endl;
      cin >> x;
      if (!x) {
        b[i] = 0;
        b[i + 1] = 0;
        cout << '?' << ' ' << im << ' ' << cr << ' ' << i + 2 << endl;
        cin >> b[i + 2];
      } else {
        b[i + 2] = 0;
        cout << '?' << ' ' << im << ' ' << cr << ' ' << i << endl;
        cin >> y;
        if (y) {
          b[i] = 1;
          b[i + 1] = 0;
        } else {
          b[i] = 0;
          b[i + 1] = 1;
        }
      }
    }
  }
  long long cnt = 0;
  for (long long i = 1; i <= n; i++) {
    if (!b[i]) cnt++;
  }
  cout << '!' << ' ' << cnt << ' ';
  for (long long i = 1; i <= n; i++) {
    if (!b[i]) cout << i << ' ';
  }
  cout << endl;
}
int32_t main() {
  long long tc = 1;
  cin >> tc;
  for (long long t = 1; t <= tc; t++) {
    solve();
  }
}
