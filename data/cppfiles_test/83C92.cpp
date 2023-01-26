#include <bits/stdc++.h>
using namespace std;
const long long INF = 4500000000000000000;
long long dx[4] = {-1, 1, 0, 0};
long long dy[4] = {0, 0, -1, 1};
const long long MOD = 998244353;
void radixsort(vector<long long>& p, vector<long long>& c) {
  long long n = p.size();
  vector<long long> p_new(n), cnt(n + 1);
  for (long long x : c) cnt[x + 1]++;
  for (long long i = 1; i < n; ++i) cnt[i] += cnt[i - 1];
  for (long long x : p) p_new[cnt[c[x]]++] = x;
  p = p_new;
}
struct segtree {
  long long size;
  vector<long long> nums;
  void init(long long n) {
    size = 1;
    while (size < n) size *= 2;
    nums.resize(size * 2);
  }
  void set(long long idx, long long val) {
    for (nums[idx += size] = val; idx > 1; idx /= 2) {
      nums[idx / 2] = min(nums[idx], nums[idx ^ 1]);
    }
  }
  long long read(long long l, long long r) {
    long long ret = INF;
    for (l += size, r += size; l < r; l /= 2, r /= 2) {
      if (l % 2) ret = min(ret, nums[l++]);
      if (r % 2) ret = min(ret, nums[--r]);
    }
    return ret;
  }
};
signed main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    s += "$";
    n++;
    vector<long long> p(n), c(n);
    vector<pair<char, long long>> a(n);
    for (long long i = 0; i < n; i++) {
      a[i] = {s[i], i};
    }
    sort(a.begin(), a.end());
    for (long long i = 0; i < n; i++) {
      p[i] = a[i].second;
    }
    c[p[0]] = 0;
    for (long long i = 1; i < n; i++) {
      if (a[i].first == a[i - 1].first)
        c[p[i]] = c[p[i - 1]];
      else
        c[p[i]] = c[p[i - 1]] + 1;
    }
    long long k = 0;
    while ((1 << k) < n) {
      for (long long i = 0; i < n; i++) {
        p[i] = (p[i] - (1 << k) + n) % n;
      }
      radixsort(p, c);
      vector<long long> newc(n);
      newc[p[0]] = 0;
      for (long long i = 1; i < n; i++) {
        pair<long long, long long> prev = {c[p[i - 1]],
                                           c[(p[i - 1] + (1 << k)) % n]};
        pair<long long, long long> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
        if (now == prev)
          newc[p[i]] = newc[p[i - 1]];
        else
          newc[p[i]] = newc[p[i - 1]] + 1;
      }
      c = newc;
      k++;
    }
    vector<long long> lcp(n);
    k = 0;
    for (long long i = 0; i < n - 1; i++) {
      long long pi = c[i];
      long long j = p[pi - 1];
      while (s[i + k] == s[j + k]) {
        k++;
      }
      lcp[pi] = k;
      k = max(k - 1, 0ll);
    }
    segtree seg;
    seg.init(n);
    for (long long i = 1; i < n; i++) {
      seg.set(i - 1, lcp[i]);
    }
    n--;
    vector<long long> dp(n);
    for (long long i = n - 1; i >= 0; i--) {
      dp[i] = n - i;
      for (long long j = i + 1; j < n; j++) {
        if (s[j] == s[i]) {
          if (c[i] < c[j]) {
            dp[i] = max(dp[i], dp[j] + n - i - seg.read(c[i], c[j]));
          }
        }
        if (s[j] > s[i]) dp[i] = max(n - i + dp[j], dp[i]);
      }
    }
    long long ans = -1;
    for (long long a : dp) ans = max(ans, a);
    cout << ans << '\n';
  }
}
