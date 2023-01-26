#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int INF = 1e9 + 5;
const int MOD = 1000000007;
const int MOD1 = 998244353;
double pi = 2 * acos(0.0);
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
template <typename T1, typename T2>
using safe_map = unordered_map<T1, T2, custom_hash>;
long long int GCD(long long int a, long long int b) {
  if (b > a) {
    return GCD(b, a);
  }
  if (b == 0) {
    return a;
  }
  return GCD(b, a % b);
}
void extendgcd(long long int a, long long int b, long long int* v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  long long int x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
}
long long int LCM(long long int a, long long int b) {
  return ((long long int)a * b) / GCD(a, b);
}
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
long long int mod_pow(long long int x, long long int n, int m = MOD) {
  if (x == 0 && n == 0) return 0;
  long long int res = 1;
  while (n > 0) {
    if (n % 2) res = (res * x) % m;
    x = (x * x) % m;
    n /= 2;
  }
  return res;
}
long long int mod_inverse(long long int x, long long int m = MOD) {
  return mod_pow(x, m - 2, m);
}
mt19937 rng;
int getRandomNumber(int l, int r) {
  uniform_int_distribution<int> dist(l, r);
  return dist(rng);
}
bool prime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
vector<int> PRIME_FACTOR(int n) {
  vector<int> f;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      f.push_back(i);
      n /= i;
    }
  }
  if (n > 1) f.push_back(n);
  return f;
}
long long getcount(long long int n, int k) {
  long long int res = (n >> (k + 1)) << k;
  if ((n >> k) & 1) res += n & ((1ll << k) - 1);
  return res;
}
void _print(long long int t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
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
void _print(safe_map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void solve() {
  int n, m, rb, cb, rd, cd;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  if (rb == rd || cb == cd) {
    cout << 0;
  } else if (cd - cb > 0) {
    if (rd > rb) {
      cout << min(cd - cb, rd - rb);
    } else
      cout << cd - cb;
  } else {
    if (rd > rb) {
      cout << min(abs((rd - rb)), abs((cb - cd))) + (m - cb) * 2;
      ;
    }
    cout << abs((cb - cd)) + (m - cb) * 2;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  int _ = 1;
  while (t--) {
    cerr << "Case #" << _ << ": ";
    solve(), cout << '\n';
    cerr << '\n', _++;
  }
  return 0;
}
