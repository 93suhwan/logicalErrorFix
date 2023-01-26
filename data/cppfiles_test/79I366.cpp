#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
const int MX = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const db PI = acos((db)-1);
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
mt19937 rng((uint32_t)steady_clock::now().time_since_epoch().count());
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T, class func>
T first_true(T lo, T hi, func first) {
  hi++;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo) / 2;
    first(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}
template <class T, class func>
T last_true(T lo, T hi, func first) {
  lo--;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo + 1) / 2;
    first(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}
template <class T>
void remove_duplicates(vector<T>& v) {
  sort((v).begin(), (v).end());
  v.erase(unique((v).begin(), (v).end()), end(v));
}
void setIO(str S = "") {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(15);
  if ((int)((S).size()) > 0) {
    freopen(S.c_str(), "r", stdin);
    freopen(S.c_str(), "w", stdout);
  }
}
namespace factorizer {
bool is_prime(int64_t n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int64_t i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
std::bitset<15000105> prime;
void sieve(int n) {
  prime.set();
  prime[0] = prime[1] = false;
  for (int64_t p = 2; p * p <= n; ++p) {
    if (prime[p]) {
      for (int64_t i = p * p; i <= n; i += p) {
        prime[i] = false;
      }
    }
  }
}
std::vector<int> mu;
void mobius(int n) {
  mu = std::vector<int>(n + 1);
  mu[0] = 0, mu[1] = 1;
  for (int64_t i = 1; i <= n; ++i) {
    if (mu[i]) {
      for (int64_t j = 2 * i; j <= n; j += i) {
        mu[j] -= mu[i];
      }
    }
  }
}
std::vector<int64_t> primelist;
bool __primes_generated__ = false;
void generate_primes(int n) {
  __primes_generated__ = true;
  sieve(n + 1);
  for (int64_t i = 2; i <= n; ++i)
    if (prime[i]) primelist.push_back(i);
}
template <class T>
std::vector<T> factors(T n) {
  if (__primes_generated__ == false) assert(false);
  std::vector<pair<T, int>> facts;
  for (auto& p : primelist) {
    if (p * p > n) break;
    if (n % p == 0) {
      int t = 0;
      while (n % p == 0) n /= p, t++;
      facts.push_back({p, t});
    }
  }
  if (n > 1) facts.push_back({n, 1});
  return facts;
}
}  // namespace factorizer
using namespace factorizer;
void run_case(int tc = 0) {
  int n;
  cin >> n;
  str second;
  cin >> second;
  for (int i = 0; i < n; ++i) {
    if (!is_prime(second[i] - '0')) {
      cout << "1\n" << (char)second[i] << "\n";
      return;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      str num = to_string(second[i]);
      num += second[j];
      if (!is_prime(stoi(num))) {
        cout << 2 << "\n" << num << "\n";
        return;
      }
    }
  }
}
int32_t main() {
  setIO();
  generate_primes(111);
  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; ++t) run_case(t);
}
