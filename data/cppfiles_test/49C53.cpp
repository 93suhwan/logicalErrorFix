#include <bits/stdc++.h>
const int N = 2e6;
long long read() {
  long long a = 0;
  int op = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') op = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    a = (a << 3) + (a << 1) + (48 ^ ch);
    ch = getchar();
  }
  return a * op;
}
int n;
int a[N];
std::vector<int> tr[N];
struct Q {
  int id, l, k;
};
std::vector<Q> mnt[N];
int ans[N];
std::list<int>::iterator it[N];
std::list<int> s[N];
int sum[N];
int ct[N];
void dfs(int now) {
  sum[ct[a[now]]]--;
  s[ct[a[now]]].erase(it[a[now]]);
  ct[a[now]]++;
  s[ct[a[now]]].push_front(a[now]);
  it[a[now]] = s[ct[a[now]]].begin();
  for (auto [id, l, k] : mnt[now]) {
    k += sum[l - 1];
    if (k > n) {
      ans[id] = -1;
      continue;
    }
    ans[id] = *s[std::lower_bound(sum, sum + n + 1, k) - sum].begin();
  }
  for (int to : tr[now]) dfs(to);
  s[ct[a[now]]].erase(it[a[now]]);
  ct[a[now]]--;
  s[ct[a[now]]].push_front(a[now]);
  it[a[now]] = s[ct[a[now]]].begin();
  sum[ct[a[now]]]++;
}
void solve() {
  n = read();
  int m = read();
  for (int i = 0; i <= n; i++) sum[i] = n;
  s[0].clear();
  for (int i = 1; i <= n; i++) {
    s[0].push_front(i);
    it[i] = s[0].begin();
  }
  for (int i = 1; i <= n; i++) tr[i].clear();
  for (int i = 1; i <= n; i++) mnt[i].clear();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 2; i <= n; i++) tr[read()].push_back(i);
  for (int i = 1; i <= m; i++) {
    Q q;
    q.id = i;
    int v = read();
    q.l = read();
    q.k = read();
    mnt[v].push_back(q);
  }
  dfs(1);
  for (int i = 1; i <= m; i++) printf("%d%c", ans[i], i == m ? '\n' : ' ');
}
int main() {
  int t = read();
  while (t--) solve();
}
