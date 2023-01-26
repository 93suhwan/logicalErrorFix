#include <bits/stdc++.h>
using namespace std;
void c_p_c() {
  clock_t begin = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void c_p_c2() {
  clock_t begin = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long log(long long n) {
  long long ctr = 0;
  while (n) {
    ctr += 1;
    n >>= 1;
  }
  return ctr;
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long l, r;
  cin >> l >> r;
  long long len = r - l + 1;
  long long start = l;
  long long nxt = binpow(2, log2(l) + 1);
  long long ans = INT_MAX;
  while (true) {
    if (nxt < r) {
      long long currLen = nxt - start;
      ans = min(ans, len - currLen);
    } else if (nxt > r) {
      long long currLen = r - start + 1;
      ans = min(ans, len - currLen);
      break;
    }
    start = nxt;
    nxt *= 2;
  }
  ans = min(ans, len / 2);
  cout << ans << '\n';
}
int32_t main() {
  c_p_c();
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
  }
  c_p_c2();
}
