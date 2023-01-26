#include <bits/stdc++.h>
const int U = 1000002;
const int N = 150005;
const int P = 80000;
int n, a[N], q, idx[U];
bool notp[U];
int p[P], tot;
std::vector<int> divs[U];
int uset[N + P];
int find(int x) { return x == uset[x] ? x : uset[x] = find(uset[x]); }
std::set<std::pair<int, int>> connect;
signed main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", a + i), idx[a[i]] = i;
  notp[1] = 1;
  for (int i = 2; i < U; i++) {
    if (!notp[i]) p[++tot] = i;
    for (int j = 1; j <= tot && i * p[j] < U; j++) {
      notp[i * p[j]] = 1;
      if (i % p[j] == 0) break;
    }
  }
  for (int i = 1; i <= tot; i++)
    for (int j = p[i]; j < U; j += p[i]) divs[j].push_back(i);
  for (int i = 1; i < n + P; i++) uset[i] = i;
  for (int i = 1; i <= n; i++)
    for (auto x : divs[a[i]]) uset[find(i)] = find(n + x);
  for (int i = 1; i <= n; i++) {
    for (auto x : divs[a[i]])
      for (auto y : divs[a[i] + 1]) connect.emplace(find(x + n), find(y + n));
    for (auto x : divs[a[i] + 1])
      for (auto y : divs[a[i] + 1]) connect.emplace(find(x + n), find(y + n));
  }
  while (q--) {
    int s, t;
    scanf("%d%d", &s, &t);
    if (find(s) == find(t))
      puts("0");
    else if (connect.count(std::make_pair(find(s), find(t))))
      puts("1");
    else if (connect.count(std::make_pair(find(t), find(s))))
      puts("1");
    else
      puts("2");
  }
  return 0;
}
