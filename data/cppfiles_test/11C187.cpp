#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(bool t) { cerr << t; }
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
long long dirs8[] = {0, -1, -1, 0, 1, -1, 1, 1, 0};
long long dirs4[] = {0, 1, 0, -1, 0};
long long dirs2[] = {0, 1, 0};
long long fact(long long n) {
  long long ans = 1;
  while (n) (ans *= n--) %= 1000000007;
  return ans;
}
long long nCr(long long n, long long r) {
  long double res = 1;
  for (long long i = 1; i <= r; ++i) res = res * (n - r + i) / i;
  return (long long)(res + 0.01);
}
vector<long long> prefixSum(vector<long long> &a) {
  long long n = ((long long)(a).size());
  vector<long long> ans(n + 1);
  for (long long i = 0; i < n; ++i) ans[i + 1] = ans[i] + a[i];
  return ans;
}
long long fexpo(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) (ans *= a) %= 1000000007, --b;
    (a *= a) %= 1000000007, b >>= 1;
  }
  return ans;
}
long long inv(long long n) { return fexpo(n, 1000000007 - 2); }
bool isPrime(long long &n) {
  for (long long i = 2; i * i <= n; ++i)
    if (n % i == 0) return 0;
  return 1;
}
bool inside(long long i, long long r, long long j = 0, long long c = 1) {
  return i >= 0 && i < r && j >= 0 && j < c;
}
bool isPal(string &s, long long lo = 0, long long hi = -1) {
  hi = (hi + 2 * ((long long)(s).size())) % ((long long)(s).size());
  long long i = lo, j = hi;
  while (i < j)
    if (s[i++] != s[j--]) return 0;
  return 1;
}
long long up(long long a, long long b) { return (a + b - 1) / b; }
vector<long long> sieve;
void createSieve(long long mxN) {
  sieve.resize(mxN + 1, 1);
  sieve[0] = 0;
  sieve[1] = 0;
  for (long long i = 2; i * i <= mxN; ++i)
    if (sieve[i])
      for (long long j = i * i; j <= mxN; j += i) sieve[j] = 0;
}
void read(long long &t) { cin >> t; }
void read(string &t) { cin >> t; }
void read(char &t) { cin >> t; }
template <typename T, typename V>
void read(pair<T, V> &p) {
  read(p.first);
  read(p.second);
}
template <typename T>
void read(vector<T> &v) {
  for (T &it : v) read(it);
}
vector<long long> fac;
vector<long long> ifac;
long long combi(long long n, long long r) {
  if (r > n) return 0;
  long long ans = 1;
  (ans *= fac[n]) %= 1000000007;
  (ans *= ifac[r]) %= 1000000007;
  (ans *= ifac[n - r]) %= 1000000007;
  return ans;
}
vector<string> poss;
void precalculate() {
  long long n = 63;
  long long k = 1;
  while (n--) {
    poss.push_back(to_string(k));
    k <<= 1;
  }
}
bool cmp(long long a, long long b) {
  if (a < 0 && b < 0)
    return a > b;
  else
    return a < b;
}
long long getmaxcol(vector<long long> a, long long k) {
  for (long long i = ((long long)(a).size()) - 1; i >= 0; --i) {
    if (a[i] == k) return i;
  }
  return -1;
}
void argon17(long long tt) {
  long long n;
  cin >> n;
  vector<string> a(n);
  read(a);
  vector<vector<long long>> cnt(n, vector<long long>(26, 0));
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < ((long long)(a[i]).size()); ++j) {
      cnt[i][a[i][j] - 'a']++;
    }
  }
  vector<vector<long long>> kk(26, vector<long long>(n));
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < 26; ++j)
      kk[j][i] = 2 * cnt[i][j] - ((long long)(a[i]).size());
  };
  long long ans = 0, fj = -1;
  for (long long j = 0; j < 26; ++j) {
    long long here = 0, cc = 0;
    ;
    for (long long i = 0; i < n; ++i) {
      if (kk[j][i] > 0) {
        here++;
        cc += kk[j][i];
      }
    };
    ;
    if (here) {
      for (long long i = 0; i < n; ++i) {
        if (kk[j][i] == 0) ++here;
      }
    };
    ;
    sort((kk[j]).begin(), (kk[j]).end(), cmp);
    for (long long i = 0; i < n; ++i) {
      if ((kk[j][i] < 0) && (cc + kk[j][i] > 0)) {
        ++here;
        cc += kk[j][i];
      }
    };
    ;
    if (here > ans) {
      ans = here;
      fj = j;
    }
  }
  cout << ans << '\n';
  ;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(12);
  srand(time(0));
  long long tc = 1;
  cin >> tc;
  for (long long t = 1; t <= tc; ++t) {
    argon17(t);
  }
}
