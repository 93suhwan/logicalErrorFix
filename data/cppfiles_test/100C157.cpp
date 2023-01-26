#include <bits/stdc++.h>
using namespace std;
double EPS = 1e-9;
const long long PL = (long long)2e18;
long long mod = 1000000007;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
long long dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
long long diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
long long minn(long long a, long long b, long long c) {
  if (a < b && a < c) return a;
  if (b < a && b < c) return b;
  return c;
}
void primes(long long n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i++) {
        prime[i] = false;
      }
    }
  }
}
bool issorted(long long a[], long long b[], long long n) {
  for (long long i = 0; i < n; i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long binarySearch(long long arr[], long long l, long long r, long long x) {
  while (l <= r) {
    long long m = l + (r - l) / 2;
    if (arr[m] == x) return m;
    if (arr[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}
bool isPerfectSquare(long long x) {
  long long left = 1, right = x;
  while (left <= right) {
    long long mid = (left + right) / 2;
    if (mid * mid == x) {
      return true;
    }
    if (mid * mid < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return false;
}
long long square(long long n) {
  if (n == 0) return 0;
  if (n < 0) n = -n;
  long long x = n >> 1;
  if (n & 1)
    return ((square(x) << 2) + (x << 2) + 1);
  else
    return (square(x) << 2);
}
long long power(long long a, long long b, long long P = mod) {
  long long res = 1;
  for (; b; b >>= 1, a = 1ll * a * a % P)
    if (b & 1) res = 1ll * res * a % P;
  return res;
}
void permute(string s, long long l, long long r, set<string> &perm) {
  if (l == r) {
    perm.insert(s);
  } else {
    for (long long i = l; i <= r; i++) {
      swap(s[l], s[i]);
      permute(s, l + 1, r, perm);
      swap(s[l], s[i]);
    }
  }
}
class Offset {
 public:
  multiset<long long> st;
  long long delta;
  long long fetch() { return (*st.begin()) + delta; }
  void decrease(long long x) { delta -= x; }
  void add(long long x) { st.insert(x - delta); }
  void rem() { st.erase(st.begin()); }
};
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  multiset<long long> ms(a.begin(), a.end());
  Offset obj;
  for (long long i = 0; i < n; i++) {
    obj.add(a[i]);
  }
  sort(a.begin(), a.end());
  long long res = a[0];
  for (long long i = 0; i < n; i++) {
    long long temp = obj.fetch();
    res = max(res, temp);
    obj.decrease(temp);
    obj.rem();
  }
  cout << res << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
