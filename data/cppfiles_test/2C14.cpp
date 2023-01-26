#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(51);
const long long MOD = 1e9 + 7, N = 2e5 + 10;
long long t[N];
long long add(long long a, long long b) {
  return a + b >= MOD ? a + b - MOD : a + b;
}
long long sub(long long a, long long b) {
  return a - b < 0 ? a - b + MOD : a - b;
}
long long mul(long long a, long long b) { return (a * b % MOD); }
void inc(long long i, long long d) {
  for (; i < N; i = (i | (i + 1))) {
    t[i] += d;
  }
}
long long get(long long r) {
  long long ans = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) {
    ans += t[r];
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> a(n), pr(n + 1), ind(k);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    pr[i + 1] = (pr[i] + a[i]) % k;
  }
  if (pr.back() == 0) {
    vector<long long> cnt(k);
    for (long long i = 1; i <= n; i++) {
      cnt[pr[i]] = add(cnt[pr[i]], m);
    }
    long long ans = 0;
    for (long long i = 0; i < k; i++) {
      ans = add(ans, mul(cnt[i], sub(cnt[i], 1)));
    }
    cout << add(ans, 1) << endl;
    return 0;
  }
  long long now = 0, ans = 0;
  for (long long i = 0; i < k; i++) {
    ind[now] = i;
    now = (now + pr.back()) % k;
  }
  for (long long i = n - 1; i >= 0; i--) {
    inc(ind[pr[i + 1]], 1);
    long long now = mul(get(k - 1), m / k);
    long long r = ind[pr[i]], l = r - m % k + 1;
    if (l < 0) {
      now = add(now, sub(get(k - 1), get(k + l - 1)));
      now = add(now, get(r));
    } else {
      now = add(now, sub(get(r), get(l - 1)));
    }
    ans = add(ans, mul(now, m));
  }
  for (long long i = 0; i < N; i++) t[i] = 0;
  for (long long i = 1; i < n; i++) {
    inc(ind[pr[i]], 1);
    long long now = mul(get(k - 1), m / k);
    long long r = ind[(pr[i] - pr.back() + k) % k], l = r - m % k + 1;
    if (l < 0) {
      now = add(now, sub(get(k - 1), get(k + l - 1)));
      now = add(now, get(r));
    } else {
      now = add(now, sub(get(r), get(l - 1)));
    }
    ans = add(ans, mul(now, m));
  }
  if (pr.back() * m % k == 0) {
    ans = sub(ans, mul(n, m) - 1);
  }
  cout << ans << endl;
  return 0;
}
