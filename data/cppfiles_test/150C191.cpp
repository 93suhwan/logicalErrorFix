#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long INF = 9e18;
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while (!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(vector<string> __attribute__((unused)) args,
               __attribute__((unused)) long long idx,
               __attribute__((unused)) long long LINE_NUM) {
  cout << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, long long idx, long long LINE_NUM, Head H,
               Tail... T) {
  if (idx > 0)
    cout << ", ";
  else
    cout << "Line(" << LINE_NUM << ") ";
  stringstream ss;
  ss << H;
  cout << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
template <typename T>
using min_prq = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[ ";
  for (long long i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1) os << ", ";
  }
  os << " ]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[ ";
  for (auto it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << " ]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
  os << "[ ";
  for (auto it : v) os << it << ", ";
  os << " ]\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  os << "{ ";
  for (auto it : v) os << it.first << " : " << it.second << ", ";
  os << " }\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const multimap<T, S>& v) {
  os << "{ ";
  for (auto it : v) os << it.first << " : " << it.second << ", ";
  os << " }\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << "(";
  os << v.first << ", " << v.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, priority_queue<T> p) {
  os << "[ ";
  while (!p.empty()) {
    os << p.top() << " ,";
    p.pop();
  }
  os << " ]\n";
  return os;
}
namespace math_help {
long long gcd(long long a, long long b) {
  long long c;
  while (b) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}
long long lcm(long long a, long long b) { return (a * (b / gcd(a, b))); }
const long long MAX_N = 1e6 + 1;
long long fact[MAX_N], invf[MAX_N];
long long modpow(long long a, long long p = M - 2, long long MOD = M) {
  long long result = 1;
  a = a % MOD;
  if (a == 0) return 0;
  while (p > 0) {
    if (p & 1) {
      result = a * result % MOD;
    }
    a = a * a % MOD;
    p >>= 1;
  }
  return result;
}
long long modinv(long long n, long long p) { return modpow(n, p - 2, p); }
void factPrecompute() {
  fact[0] = invf[0] = 1;
  for (long long i = 1; i < MAX_N; i++) {
    fact[i] = fact[i - 1] * i % M;
    invf[i] = modpow(fact[i], M - 2, M);
  }
}
long long nCk(long long n, long long k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * invf[k] % M * invf[n - k] % M;
}
vector<long long> sieve(long long n) {
  vector<long long> is_prime(n + 1, 1);
  for (long long i = 2; i * i <= n; i++)
    if (is_prime[i])
      for (long long j = i * i; j <= n; j += i) is_prime[j] = 0;
  return is_prime;
}
}  // namespace math_help
using namespace math_help;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long(i) = (0); (i) <= (n - 1); ++(i)) {
    cin >> v[i];
  }
  long long maxy = *max_element((v).begin(), (v).end());
  long long max3 = maxy / 3, ans = INF;
  for (long long(o) = (0); (o) <= (2); ++(o)) {
    for (long long(t) = (0); (t) <= (2); ++(t)) {
      for (long long(three) = (max3 - 4); (three) <= (max3); ++(three)) {
        long long ok = 1, coins = o + t + three;
        for (long long(i) = (0); (i) <= (n - 1); ++(i)) {
          long long pos = 0;
          for (long long(oo) = (0); (oo) <= (o); ++(oo)) {
            for (long long(tt) = (0); (tt) <= (t); ++(tt)) {
              long long rem = v[i] - (oo + 2 * tt);
              if (rem >= 0 and rem % 3 == 0 and rem / 3 <= three) {
                pos = 1;
                break;
              }
            }
          }
          if (pos == 0) {
            ok = 0;
            break;
          }
        }
        if (ok) {
          ans = min(ans, coins);
        }
      }
    }
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  for (long long(T) = (1); (T) <= (t); ++(T)) {
    solve();
    cout << "\n";
  }
  return 0;
}
