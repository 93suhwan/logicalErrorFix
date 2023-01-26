#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, a[1010];
const int LZJAKIOI = 30;
namespace solver {
int n, tot, tmp[45];
short coef[5000000][17];
ll a[45], ans[45];
vector<pair<ll, int>> mp[17];
int solve() {
  int m = (n - 1) / 2;
  function<void(int, int, ll)> dfs1 = [&](int pos, int cur, ll sum) {
    if (pos > m) {
      if (cur < 0) return;
      mp[cur].emplace_back(sum, ++tot);
      copy(tmp + 1, tmp + m + 1, coef[tot] + 1);
      return;
    }
    for (int i : {-1, 0, 1}) {
      tmp[pos] = i, dfs1(pos + 1, cur + i, sum + i * a[pos]);
    }
  };
  dfs1(1, 0, 0);
  for (int i = 0; i <= m; i++) {
    stable_sort(mp[i].begin(), mp[i].end());
  }
  function<void(int, int, ll)> dfs2 = [&](int pos, int cur, ll sum) {
    if (pos > n) {
      cur *= -1, sum *= -1;
      if (cur < 0 || cur > m) return;
      auto it =
          lower_bound(mp[cur].begin(), mp[cur].end(), std::make_pair(sum, 0));
      if (it == mp[cur].end() || it->first ^ sum) return;
      int cnt = 1, id = it->second;
      vector<int> V1, V2;
      vector<bool> chk(n + 1);
      for (int i = 1; i <= m; i++) {
        if (coef[id][i] > 0) V1.push_back(i), chk[i] = 1;
        if (coef[id][i] < 0) V2.push_back(i), chk[i] = 1;
      }
      for (int i = m + 1; i <= n; i++) {
        if (tmp[i] > 0) V1.push_back(i), chk[i] = 1;
        if (tmp[i] < 0) V2.push_back(i), chk[i] = 1;
      }
      if (V1.empty() || V2.empty()) return;
      printf("YES\n");
      for (int i = 0; i < V2.size() - 1; i++) {
        ans[cnt + 1] = a[V1[i]] - ans[cnt], cnt++;
        ans[cnt + 1] = a[V2[i]] - ans[cnt], cnt++;
      }
      ans[cnt + 1] = a[V1.back()] - ans[cnt], cnt++;
      for (int i = 1; i <= n; i++)
        if (!chk[i]) {
          ans[cnt + 1] = a[i] - ans[cnt], cnt++;
        }
      for (int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
      }
      for (int i = min(::n, LZJAKIOI) + 1; i <= ::n; i++) printf("%d ", ::a[i]);
      exit(0);
    }
    for (int i : {-1, 0, 1}) {
      tmp[pos] = i, dfs2(pos + 1, cur + i, sum + i * a[pos]);
    }
  };
  dfs2(m + 1, 0, 0);
  printf("No\n");
  exit(0);
}
};  // namespace solver
void solve_all_odd() {
  solver::n = min(n, LZJAKIOI);
  for (int i = (1); i <= (min(n, LZJAKIOI)); i++) solver::a[i] = a[i];
  solver::solve();
}
int main() {
  cin >> n;
  for (int i = (1); i <= (n); i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  int m = unique(a + 1, a + n + 1) - a - 1;
  if (m > n * (n - 1) / 2) return puts("NO"), 0;
  if (m <= n - 1) {
    puts("YES");
    cout << 0 << " ";
    for (int i = (1); i <= (m); i++) cout << a[i] << " ";
    for (int i = (1); i <= (n - m - 1); i++) cout << "0 ";
    cout << endl;
    return 0;
  }
  int even = 0, odd = 0;
  for (int i = (1); i <= (n); i++) {
    if (a[i] & 1)
      odd++;
    else
      even++;
  }
  if (even == 2 && odd == 1) return puts("NO"), 0;
  if (even > 0) {
    vector<int> ev, od;
    for (int i = (1); i <= (n); i++) {
      if (a[i] & 1)
        od.push_back(a[i]);
      else
        ev.push_back(a[i]);
    }
    int p = ev.back();
    ev.pop_back();
    int sum;
    if (ev.size() >= 2)
      sum = ev[0] + ev[1];
    else
      sum = od[0] + od[1];
    int diff = (sum - p) / 2;
    puts("YES");
    cout << diff << " ";
    for (int k : ev) cout << k - diff << " ";
    for (int k : od) cout << k - diff << " ";
    cout << endl;
  } else
    solve_all_odd();
  return 0;
}
