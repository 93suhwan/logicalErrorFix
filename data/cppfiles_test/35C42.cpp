#include <bits/stdc++.h>
using namespace std;
int a[1000000 + 5];
char b[1000000 + 5];
int las[1000000 + 5];
void get_prime() {
  int n = 1000000;
  for (int i = 2; i <= n; i++)
    if (!las[i]) {
      las[i] = i;
      if (i > 1000) continue;
      for (int j = i * i; j <= n; j += i) las[j] = i;
    }
}
int pre[1000000 + 5];
vector<int> p[1000000 + 5];
void add(int x, int id) {
  pre[id] = id;
  while (x != 1) p[las[x]].push_back(id), x /= las[x];
}
void del(int x, int id) {
  pre[id] = id;
  while (x != 1) {
    if (!p[las[x]].size()) {
      pre[id] = 0;
      return;
    }
    pre[id] = min(pre[id], p[las[x]].back());
    p[las[x]].pop_back();
    x /= las[x];
  }
}
vector<pair<int, int> > Q;
int main() {
  int n, i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%s", b + 1);
  get_prime();
  for (i = 1; i <= n; i++)
    if (b[i] == '*')
      add(a[i], i);
    else
      del(a[i], i);
  long long ans = 0;
  for (i = n; i >= 1; i--) {
    int cnt = 1;
    while (!Q.empty() && Q.back().first >= pre[i])
      cnt += Q.back().second, Q.pop_back();
    Q.push_back(make_pair(pre[i], cnt));
    if (pre[i] == i) ans += cnt;
  }
  printf("%lld\n", ans);
}
