#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using ii = pair<int, int>;
const int N = 3e5 + 5, LG = 19, MOD = 1e9 + 7;
const double PI = acos(-1);
int n, q, k;
int second[N];
int a[N];
int tb[LG][N];
namespace solveLarge {
int a[N];
vector<ii> qr[N];
int minQuery(int l, int r) {
  int k = second[r - l + 1];
  return min(tb[k][l], tb[k][r - (1 << k) + 1]);
}
void init() {
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tb[0][i] = a[i];
  }
  for (int j = 1; j < LG; j++) {
    for (int i = 0; i + (1 << (j - 1)) < n; i++) {
      tb[j][i] = min(tb[j - 1][i], tb[j - 1][i + (1 << (j - 1))]);
    }
  }
  vector<ll> ans(q);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    qr[l].push_back(make_pair(r, i));
  }
  for (int i = 0; i < n; i++) {
    sort(qr[i].begin(), qr[i].end());
    int ptr = 0;
    ll curSum = 0;
    int curR = i;
    while (curR < n) {
      while (ptr < qr[i].size() && qr[i][ptr].first < curR) {
        ans[qr[i][ptr++].second] = curSum;
      }
      curSum += minQuery(i, curR);
      curR += k;
    }
    while (ptr < qr[i].size() && qr[i][ptr].first < curR) {
      ans[qr[i][ptr++].second] = curSum;
    }
  }
  for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}
}  // namespace solveLarge
namespace solveSmall {
vector<ii> qr[N];
void init() {
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> ans(q);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    qr[l].push_back(ii(r, i));
  }
  for (int mod = 0; mod < k; mod++) {
    vector<pair<int, ll> > stk;
    stk.push_back(make_pair(n, 0));
    vector<int> cnt(n + 1);
    int cur = (n - 1) % k;
    for (int i = n - 1; i >= 0; --i) {
      cnt[i] = cnt[i + 1] + (cur == mod);
      while (a[stk.back().first] >= a[i]) {
        stk.pop_back();
      }
      stk.push_back(make_pair(
          i,
          stk.back().second + 1ll * (cnt[i] - cnt[stk.back().first]) * a[i]));
      if (cur == mod) {
        for (auto x : qr[i]) {
          int l = i, r = x.first;
          int lo = 0, hi = stk.size() - 1;
          while (lo < hi) {
            int md = lo + (hi - lo) / 2;
            if (stk[md].first <= r) {
              hi = md;
            } else
              lo = md + 1;
          }
          ans[x.second] = stk.back().second - stk[lo].second;
          ans[x.second] +=
              1ll * a[stk[lo].first] * (cnt[stk[lo].first] - cnt[r + 1]);
        }
      }
      cur -= 1;
      if (cur < 0) {
        cur += k;
      }
    }
  }
  for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}
}  // namespace solveSmall
void doWork() {
  cin >> n >> q >> k;
  if (k >= 550) {
    solveLarge::init();
  } else {
    solveSmall::init();
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 2; i < N; i++) second[i] = second[i >> 1] + 1;
  int t = 1;
  while (t--) {
    doWork();
  }
  return 0;
}
