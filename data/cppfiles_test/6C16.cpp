#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
const long long mod = 1e9 + 7;
vector<int> G[MAX], s[MAX], p;
int a[MAX], phi[MAX], cnt[MAX];
long long res[MAX];
bool vis[MAX];
void init() {
  for (int i = 1; i < MAX; i++) {
    for (int j = i; j < MAX; j += i) {
      G[j].push_back(i);
    }
  }
  phi[1] = 1;
  for (int i = 2; i < MAX; i++) {
    if (!vis[i]) {
      p.push_back(i);
      phi[i] = i - 1;
    }
    for (unsigned j = 0; j < p.size() && i * p[j] < MAX; j++) {
      vis[i * p[j]] = true;
      if (i % p[j] == 0) {
        phi[i * p[j]] = phi[i] * p[j];
        break;
      } else {
        phi[i * p[j]] = phi[i] * (p[j] - 1);
      }
    }
  }
}
int main() {
  init();
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      s[i].push_back(a[j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    memset(cnt, 0, sizeof(cnt));
    for (unsigned j = 0; j < s[i].size(); j++) {
      int x = s[i][j];
      for (unsigned k = 0; k < G[x].size(); k++) {
        int t = G[x][k];
        res[i] = (res[i] + 1LL * (2 * cnt[t] + 1) * phi[t] % mod) % mod;
        cnt[t]++;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + res[i] * phi[i] % mod) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
