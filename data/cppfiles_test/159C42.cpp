#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 2;
long long spf[N], val[N];
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
T rand(T a, T b) {
  return uniform_int_distribution<T>(a, b)(rng);
}
template <class T>
T rand() {
  return uniform_int_distribution<T>()(rng);
}
long long getrand() { return rand(0ll, LONG_LONG_MAX); }
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  memset(spf, -1, sizeof spf);
  for (long long i = 2; i < N; i++) {
    if (spf[i] != -1) continue;
    val[i] = getrand();
    for (long long j = i; j < N; j += i) {
      if (spf[j] == -1) spf[j] = i;
    }
  }
  long long n, sum = 0;
  cin >> n;
  vector<long long> a(n + 1);
  a[0] = a[1] = 0;
  for (long long i = 2; i <= n; i++) {
    a[i] = a[i - 1];
    long long c = i;
    while (c > 1) {
      a[i] ^= val[spf[c]];
      c /= spf[c];
    }
    sum ^= a[i];
  }
  vector<long long> ans(n, 0);
  long long mn = 0;
  {
    long long x = n;
    vector<long long> res(n + 1, 1);
    if (n % 2) res[n] = 0, x--;
    res[x / 2] = 0;
    if ((x % 4)) res[2] = 0;
    res[0] = 0;
    if (n == 1) res[n] = 1;
    if (accumulate(res.begin(), res.end(), 0) > mn) {
      mn = accumulate(res.begin(), res.end(), 0);
      ans = res;
    }
  }
  {
    for (long long i = 1; i <= n; i++) {
      if (a[i] == sum) {
        vector<long long> res(n + 1, 1);
        res[0] = 0;
        res[i] = 0;
        if (accumulate(res.begin(), res.end(), 0) > mn) {
          mn = accumulate(res.begin(), res.end(), 0);
          ans = res;
        }
        break;
      }
    }
  }
  {
    map<long long, long long> m;
    for (long long i = 1; i <= n; i++) {
      if (m.count(sum ^ a[i])) {
        vector<long long> res(n + 1, 1);
        res[0] = 0;
        res[i] = 0;
        res[m[sum ^ a[i]]] = 0;
        if (accumulate(res.begin(), res.end(), 0) > mn) {
          mn = accumulate(res.begin(), res.end(), 0);
          ans = res;
        }
        break;
      }
      m[a[i]] = i;
    }
  }
  cout << mn << '\n';
  for (long long i = 1; i <= n; i++) {
    if (ans[i]) cout << i << ' ';
  }
}
