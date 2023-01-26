#include <bits/stdc++.h>
using namespace std;
void swap(long long &x, long long &y) {
  long long temp = x;
  x = y;
  y = temp;
}
void google(long long t) { cout << "Case #" << t << ": "; }
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long expom(long long x, long long y, long long m) {
  if (y == 0) return 1;
  x = x % m;
  if (y % 2 == 0) return expom(x * x, y / 2, m) % m;
  return (x * expom(x * x, y / 2, m)) % m;
}
inline long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
inline long long ceil(long long a, long long b) {
  return (a % b == 0) ? a / b : a / b + 1;
}
long long dx[] = {1, 0, -1, 0};
long long dy[] = {0, 1, 0, -1};
vector<long long> pri(200000 + 6);
void prime_factorization_sieve() {
  pri[1] = 1;
  for (long long i = 2; i <= 200000 + 5; i++) {
    pri[i] = -1;
  }
  for (long long i = 2; i <= 200000 + 5; i++) {
    if (pri[i] == -1) {
      for (long long j = i; j <= 200000 + 5; j += i) {
        if (pri[j] == -1) pri[j] = i;
      }
    }
  }
}
vector<long long> get_factors(long long n) {
  vector<long long> res;
  while (pri[n] != 1) {
    res.push_back(pri[n]);
    n = n / pri[n];
  }
  return res;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> arr(n + 1);
  for (long long i = 1; i <= n; i++) cin >> arr[i];
  stack<pair<long long, long long>> st;
  long long ans = INT_MIN;
  for (long long i = 1; i <= n; i++) {
    if (st.size() == 0) {
      st.push({arr[i], i});
    } else if (st.size() != 0 && st.top().first <= arr[i]) {
      ans = ((ans) < (st.top().second * i - k * (st.top().first | arr[i]))
                 ? (st.top().second * i - k * (st.top().first | arr[i]))
                 : (ans));
    }
    st.push({arr[i], i});
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
