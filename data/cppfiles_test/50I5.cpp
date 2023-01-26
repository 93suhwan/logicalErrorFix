#include <bits/stdc++.h>
using namespace std;
struct segtree {
  vector<long long> v;
  void init(long long n) {
    long long curr = 1;
    while (curr < n) {
      curr = curr * 2;
    }
    for (long long i = 0; i < 2 * curr; i++) {
      v.push_back(0);
    }
  }
  void update(long long lx, long long rx, long long curr, long long i,
              long long z) {
    if (rx - lx == 1) {
      v[curr] = z;
      return;
    }
    long long m = (lx + rx) / 2;
    if (i < m) {
      update(lx, m, 2 * curr + 1, i, z);
    } else {
      update(m, rx, 2 * curr + 2, i, z);
    }
    if ((m - lx) % 2 == 0) {
      v[curr] = v[2 * curr + 1] + v[2 * curr + 2];
    } else {
      v[curr] = v[2 * curr + 1] - v[2 * curr + 2];
    }
    if (v[curr] < 0) {
      v[curr] += 998244353;
    }
    v[curr] %= 998244353;
  }
  long long getans(long long lx, long long rx, long long curr, long long l,
                   long long r) {
    if (lx >= l && rx <= r) {
      if ((lx - l) % 2) {
        return 998244353 - v[curr];
      }
      return v[curr];
    }
    if (l >= rx || lx >= r) {
      return 0;
    }
    long long m = (lx + rx) / 2;
    return (getans(lx, m, 2 * curr + 1, l, r) +
            getans(m, rx, 2 * curr + 2, l, r)) %
           998244353;
  }
};
int32_t main() {
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    pair<long long, long long> a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    stack<long long> s;
    long long prev_l[n];
    memset(prev_l, -1, sizeof(prev_l));
    for (long long i = n - 1; i >= 0; i--) {
      while (!s.empty() && a[s.top()] > a[i]) {
        prev_l[s.top()] = i;
        s.pop();
      }
      s.push(i);
    }
    struct segtree st;
    st.init(n);
    long long dp[n];
    dp[0] = a[0].first;
    dp[0] %= 998244353;
    st.update(0, n, 0, 0, dp[0]);
    for (long long i = 1; i < n; i++) {
      if (a[i] > a[i - 1]) {
        dp[i] = dp[i - 1] * (a[i].first - 1);
        st.update(0, n, 0, i, dp[i]);
        continue;
      }
      if (prev_l[i] != -1) {
        long long gg = st.getans(0, n, 0, prev_l[i], i);
        if ((i - prev_l[i]) % 2) {
          long long opop = a[i].first * gg;
          opop %= 998244353;
          opop += (998244353 - dp[prev_l[i]]);
          opop %= 998244353;
          dp[i] = opop;
          st.update(0, n, 0, i, dp[i]);
        } else {
          gg = 998244353 - gg;
          long long opop = a[i].first * gg;
          opop %= 998244353;
          opop += (dp[prev_l[i]]);
          opop %= 998244353;
          dp[i] = opop;
          st.update(0, n, 0, i, dp[i]);
        }
      } else {
        long long gg = st.getans(0, n, 0, 0, i);
        if ((i) % 2 == 0) {
          gg = (998244353 - gg);
          long long opop = (gg + 1) * a[i].first;
          opop %= 998244353;
          dp[i] = opop;
          st.update(0, n, 0, i, dp[i]);
        } else {
          long long opop = (gg - 1) * a[i].first;
          opop %= 998244353;
          dp[i] = opop;
          st.update(0, n, 0, i, dp[i]);
        }
      }
    }
    cout << dp[n - 1];
  }
}
