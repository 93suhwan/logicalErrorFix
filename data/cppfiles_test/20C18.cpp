#include <bits/stdc++.h>
using namespace std;
const int max_n = 103, inf = 1000111222;
int m[max_n * max_n];
int cnt[max_n * max_n];
int n, k;
int mx;
int lst[max_n];
bool used[max_n];
pair<int, int> res[max_n];
int get_max(int from, int to) {
  int ans = cnt[from];
  for (int i = from + 1; i <= to; ++i) {
    ans = cnt[i] > ans ? cnt[i] : ans;
  }
  return ans;
}
void add1(int from, int to) {
  for (int i = from; i <= to; ++i) {
    ++cnt[i];
  }
}
vector<pair<int, int>> solve() {
  vector<pair<int, int>> ans;
  memset(used, 0, sizeof(used));
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i <= n; ++i) {
    lst[i] = -1;
    res[i] = make_pair(-1, -1);
  }
  for (int i = 0; i < n * k; ++i) {
    int cur = m[i];
    if (used[cur]) {
      continue;
    }
    int pr = lst[cur];
    lst[cur] = i;
    if (pr == -1) {
      continue;
    }
    int tp = get_max(pr, i);
    if (tp == mx) {
      continue;
    }
    used[cur] = true;
    res[cur] = make_pair(pr, i);
    add1(pr, i);
  }
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      return ans;
    }
  }
  for (int i = 0; i < n; ++i) {
    ans.push_back(res[i]);
  }
  return ans;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n * k; ++i) {
    cin >> m[i];
    --m[i];
  }
  mx = (n + k - 2) / (k - 1);
  vector<pair<int, int>> ans = solve();
  if (ans.empty()) {
    reverse(m, m + n * k);
    ans = solve();
    if (ans.empty()) {
      exit(228);
    }
    for (int i = 0; i < n; ++i) {
      ans[i].first = (n * k - 1 - ans[i].first);
      ans[i].second = (n * k - 1 - ans[i].second);
      swap(ans[i].first, ans[i].second);
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << "\n";
  }
  return 0;
}
