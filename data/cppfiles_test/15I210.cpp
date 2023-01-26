#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long b[1000012], t, n, m, k, ccnt,
    pos = 0, sum = 0, minn2 = INT_MAX, sum2, cnt = 0, cnt1 = 0, cnt2 = 0, x, y,
    cnt3 = 0, cnt4 = 0, cnt5 = 0, cnt6 = 0, cnt7 = 0, a[1000005], a2[1000005],
    x1, y7, x2, y2, x3, y3, bbb;
long long c[1000005], z, d, l2, r2, temcnt, le[1000005], ri[1000005],
    ok[2000005], cl, cr, gan, fst, pre[1000005], mxl[1000005], mxr[1000005],
    uu[100005], vv[100005];
long long c3[2005][2005], c4[1000005], kk[1000005];
long long pos1 = 0, pos2 = 0, tem, tem2, l, r, ans, mod = 998244353, tw[100005],
          th[100005], ee, loc[1000005], te[100005], vis[1000005], ne[200005],
          pr[200005];
long long minn = LONG_MAX, maxx2, posb, mid;
long long c10, c11, c20, c21, dp[105][105][105], dp2[105][105], ans1, ans2,
    maxx, st[200005][5], dis[105][105];
bool ia, ib;
string s1, s, s2, s3, t1, t2;
char ch, ch2, cc2[1005][1005];
vector<long long> v[1000005];
pair<long long, long long> p[1000005];
pair<long long, long long> p1, p2;
map<pair<long long, long long>, long long> mp;
long long fpow(long long aa, long long bb) {
  if (bb == 0) {
    return 1;
  } else if (bb < 0) {
    return 0;
  }
  long long kk1 = aa;
  long long kk2 = 1;
  while (bb > 1) {
    if (bb % 2) {
      kk2 *= kk1;
      kk2 %= mod;
    }
    kk1 *= kk1;
    kk1 %= mod;
    bb = bb / 2;
  }
  return (kk1 * kk2) % mod;
}
long long co(long long x, long long y) {
  long long ans = 1;
  long long ans2 = 1;
  if (x == y || y == 0) {
    return 1;
  } else {
    for (long long i = x - y + 1; i <= x; i++) {
      ans = ans * i;
      ans = ans % mod;
    }
    for (long long i = 1; i <= y; i++) {
      ans2 = ans2 * i;
      ans2 = ans2 % mod;
    }
    ans2 = fpow(ans2, mod - 2);
    ans2 = (ans2 * ans) % mod;
    return ans2;
  }
}
long long summ(long long x) {
  long long ans = 0, pos = 0;
  long long maxx;
  x++;
  long long xx = x;
  for (long long i = 0;; i++) {
    if (tw[i] > x) {
      maxx = i;
      break;
    }
  }
  for (long long i = maxx - 1; i >= 0; i--) {
    if (xx >= tw[i]) {
      th[i] = 1;
      xx -= tw[i];
    } else {
      th[i] = 0;
    }
  }
  for (long long i = maxx - 1; i >= 0; i--) {
    if (th[i]) {
      ans += v[i][pos];
      pos = 2 * pos + 2;
    } else {
      pos *= 2;
    }
  }
  return ans;
}
void modify(long long x, long long m) {
  v[0][x] += m;
  for (long long i = 1; i <= cnt2; i++) {
    v[i][x / 2] += m;
    x /= 2;
  }
}
void dfs(long long x, long long y) {
  vis[y] = 1;
  for (long long i = 0; i < v[y].size(); i++) {
    if (!vis[v[y][i]]) {
      dis[x][v[y][i]] = dis[x][y] + 1;
      dfs(x, v[y][i]);
    }
  }
}
void dfs2(long long x, long long z, long long y) {
  dp[x][z][dis[x][y]]++;
  vis[y] = 1;
  for (long long i = 0; i < v[y].size(); i++) {
    if (!vis[v[y][i]]) {
      dfs2(x, z, v[y][i]);
    }
  }
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  mod = 1000000007;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) {
      v[i].clear();
    }
    for (long long i = 0; i < n - 1; i++) {
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
    }
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= n; j++) {
        vis[j] = 0;
      }
      dis[i][i] = 0;
      dfs(i, i);
    }
    for (long long i = 0; i <= n; i++) {
      for (long long j = 0; j <= n; j++) {
        for (long long kk = 0; kk <= n; kk++) {
          dp[i][j][kk] = 0;
        }
      }
    }
    if (k == 2) {
      cout << (n * (n - 1) / 2) % mod << '\n';
    } else {
      for (long long i = 1; i <= n; i++) {
        for (long long j = 0; j < v[i].size(); j++) {
          for (long long kk = 0; kk <= n; kk++) {
            vis[kk] = 0;
          }
          x = v[i][j];
          vis[i] = 1;
          dfs2(i, j, x);
        }
      }
      for (long long i = 1; i <= n; i++) {
        if (v[i].size() >= k) {
          for (long long j = 1; j <= n; j++) {
            for (long long kk = 0; kk < v[i].size(); kk++) {
              a[kk + 1] = dp[i][kk][j];
            }
            for (long long kk = 0; kk <= v[i].size(); kk++) {
              for (long long tl = 0; tl <= k; tl++) {
                dp2[kk][tl] = 0;
              }
            }
            dp2[0][0] = 1;
            for (long long kk = 1; kk <= v[i].size(); kk++) {
              dp2[kk][0] = 1;
              for (long long tl = 1; tl <= k; tl++) {
                dp2[kk][tl] = dp2[kk - 1][tl];
              }
              for (long long tl = 0; tl <= k - 1; tl++) {
                dp2[kk][tl + 1] += (dp2[kk - 1][tl] * a[kk]);
                dp2[kk][tl + 1] %= mod;
              }
            }
            ans += dp2[v[i].size()][k];
            ans %= mod;
          }
        }
      }
      cout << ans << '\n';
    }
  }
}
