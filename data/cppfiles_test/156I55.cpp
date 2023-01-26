#include <bits/stdc++.h>
using namespace std;
template <typename T>
void _print(T x, bool end_line = 1, bool bracket = 0) {
  if (bracket) cout << "{ ";
  cout << x;
  if (bracket) cout << " }";
  if (end_line) cout << '\n';
}
void _print(string x, bool end_line = 1, bool bracket = 0) {
  if (bracket) cout << "{ ";
  cout << "\"";
  cout << x;
  cout << "\"";
  if (bracket) cout << " }";
  if (end_line) cout << '\n';
}
void _print(char x, bool end_line = 1, bool bracket = 0) {
  if (bracket) cout << "{ ";
  cout << "\'";
  cout << x;
  cout << "\'";
  if (bracket) cout << " }";
  if (end_line) cout << '\n';
}
template <typename T>
void _print(set<T> &s, bool end_line = 1) {
  cout << "{ ";
  for (auto ele : s) {
    _print(ele, 0);
    cout << " ,";
  }
  cout << "}";
  if (end_line) cout << "\n";
}
template <typename T>
void _print(multiset<T> &s, bool end_line = 1) {
  cout << "{ ";
  for (auto ele : s) {
    _print(ele, 0);
    cout << " ,";
  }
  cout << "}";
  if (end_line) cout << "\n";
}
template <typename T, typename S>
void _print(pair<T, S> &p, bool end_line = 1) {
  cout << "{ ";
  _print(p.first, 0);
  cout << " , ";
  _print(p.second, 0);
  cout << " }";
  if (end_line) cout << "\n";
}
template <typename T>
void _print(vector<T> &A, bool end_line = 1) {
  cout << "{ ";
  for (auto ele : A) {
    _print(ele, false);
    cout << " ,";
  }
  cout << "}";
  if (end_line) cout << '\n';
}
template <typename T>
void _print(vector<vector<T>> &A) {
  if (A.size()) {
    _print(A[0]);
  }
  for (long long i = 1; i < A.size(); i++) {
    if (i == (long long)A.size() - 1) {
      cout << "      ";
      _print(A[i]);
    } else {
      cout << "      ";
      _print(A[i]);
    }
  }
}
template <typename T, typename S>
void _print(map<T, S> &mp) {
  cout << '\n';
  for (auto ele : mp) {
    _print(ele.first, 0);
    cout << " -> ";
    _print(ele.second);
  }
}
template <typename T, typename S>
void _print(unordered_map<T, S> &mp) {
  cout << '\n';
  for (auto ele : mp) {
    _print(ele.first, 0);
    cout << " -> ";
    _print(ele.second);
  }
}
long long power(long long x, long long y, long long p = (long long)1e9 + 7) {
  long long res = 1LL;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (1LL * res * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return res;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  long long p = sqrt(n);
  for (long long i = 5; i <= p; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long gcdExtended(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = gcdExtended(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long modInverse(long long b, long long m = (long long)1e9 + 7) {
  long long x, y;
  long long g = gcdExtended(b, m, &x, &y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}
long long mod_sum(long long a, long long b, long long M = (long long)1e9 + 7) {
  return ((a % M + b % M) % M + M) % M;
}
long long mod_mul(long long a, long long b, long long M = (long long)1e9 + 7) {
  return ((1LL * (a % M) * (b % M)) % M + M) % M;
  ;
}
long long mod_diff(long long a, long long b, long long M = (long long)1e9 + 7) {
  return ((a % M - b % M) % M + M) % M;
}
void inp(vector<long long> &A, long long idx = 0) {
  for (long long i = idx; i < A.size(); i++) cin >> A[i];
}
void to_binary(long long n, long long dig = 6) {
  string ans = "";
  long long orig = n;
  while (n > 0) {
    ans += (char)((n & 1) + '0');
    n >>= 1;
  }
  while (ans.size() < dig) {
    ans += '0';
  }
  reverse(ans.begin(), ans.end());
  cout << orig << ": " << ans << '\n';
}
long long max_n = 2e5 + 1;
vector<long long> seive(max_n + 20, 1);
void make_seive(long long max_n) {
  seive[0] = 0;
  seive[1] = 0;
  for (long long i = 2; i * i <= max_n; i++) {
    if (seive[i])
      for (long long j = i * i; j <= max_n; j += i) seive[j] = 0;
  }
}
long long max_N = 2e5 + 1;
vector<long long> min_prime(max_n + 20, 0);
void make_min_prime(long long max_N) {
  for (long long i = 2; i <= max_N; i++) {
    if (seive[i])
      for (long long j = i; j <= max_N; j += i) min_prime[j] = i;
  }
}
inline void solve() {
  long long n;
  cin >> n;
  long long x;
  cin >> x;
  vector<long long> A(n);
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> A[i];
    sum += A[i];
  }
  sort(A.begin(), A.end());
  long long s = -1e15, e = A[0];
  vector<long long> prefix(n);
  for (long long i = 0; i < n; i++)
    prefix[i] = (i - 1 >= 0 ? prefix[i - 1] : 0) + A[i];
  long long ans = 1e15;
  long long total = prefix[n - 1];
  while (s <= e) {
    long long mid = (s + e) / 2;
    long long moves = (A[0] - mid);
    long long sum = total - A[0] + mid;
    for (long long i = n - 1; i >= 1 && sum > x; i--) {
      sum -= A[i];
      sum += mid;
      moves++;
    }
    if (sum <= x) {
      ans = min(ans, moves);
      s = mid + 1;
    } else {
      e = mid - 1;
    }
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(12) << fixed;
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
