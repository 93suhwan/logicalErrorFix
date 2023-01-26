#include <bits/stdc++.h>
using namespace std;
mt19937_64 rnd(time(NULL));
const int N = 1000010;
const long long mod = 998244353;
vector<int> G[N];
vector<int> g[N];
int p[N];
int tin[N], tout[N];
int timer = 0;
void dfs0(int v, int pr) {
  p[v] = pr;
  tin[v] = ++timer;
  for (int to : G[v]) {
    if (to != pr) {
      g[v].push_back(to);
      dfs0(to, v);
    }
  }
  tout[v] = timer;
}
int n, q;
int ans[N];
bool good[N];
int dsu[N];
int get(int x) {
  if (!good[p[dsu[x]]]) {
    return dsu[x];
  }
  return dsu[x] = get(p[dsu[x]]);
}
int val[N];
int sum[N], cnt[N];
struct BIT {
  int T[N];
  void upd(int pos, int x) {
    for (; pos <= n; pos |= pos + 1) T[pos] += x;
  }
  int get(int pos) {
    int sum = 0;
    for (; pos >= 0; pos &= pos + 1, pos--) sum += T[pos];
    return sum;
  }
};
BIT T[2];
void add(int l, int r, int x, int i) {
  T[i].upd(l, x);
  T[i].upd(r + 1, -x);
}
void solve() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  cin >> q;
  dfs0(1, 0);
  vector<pair<pair<int, int>, int> > Q;
  for (int i = 1; i <= q; i++) {
    int v, k;
    cin >> v >> k;
    Q.push_back({{k, v}, i});
  }
  sort(Q.begin(), Q.end());
  reverse(Q.begin(), Q.end());
  for (int i = 1; i <= n; i++)
    good[i] = false, dsu[i] = i, sum[i] = g[i].size() - 1, cnt[i] = 1;
  set<pair<int, int> > st;
  for (int i = 1; i <= n; i++) st.insert({sum[i] / cnt[i], i});
  for (auto cur : Q) {
    int k = cur.first.first;
    int v = cur.first.second;
    while (!st.empty()) {
      int v = (*st.rbegin()).second;
      if (sum[v] / cnt[v] < k) break;
      st.erase(--st.end());
      good[v] = true;
      int pr = p[get(v)];
      T[0].upd(tin[p[pr]], -sum[v]);
      T[0].upd(tin[p[v]], sum[v]);
      T[1].upd(tin[p[pr]], -cnt[v]);
      T[1].upd(tin[p[v]], cnt[v]);
      if (pr) {
        st.erase({sum[pr] / cnt[pr], pr});
        sum[pr] += sum[v];
        cnt[pr] += cnt[v];
        st.insert({sum[pr] / cnt[pr], pr});
      }
    }
    int res = g[v].size() + T[0].get(tout[v]) - T[0].get(tin[v] - 1) -
              (T[1].get(tout[v]) - T[1].get(tin[v] - 1)) * k;
    ans[cur.second] = res;
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
