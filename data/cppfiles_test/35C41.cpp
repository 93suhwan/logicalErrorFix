#include <bits/stdc++.h>
using std::pair;
using std::vector;
const int MAX_N = 1000005, MAX_V = 1000005, MAX_PN = 78499;
int v[MAX_V], p[MAX_PN], pn = 0;
int a[MAX_N];
char opt[MAX_N];
int req[MAX_N];
int n;
vector<int> vec[MAX_V];
pair<int, int> stk[MAX_N];
inline void chkmn(int &a, int b) {
  if (a > b) a = b;
}
void eulerSieve(int n = 1000000) {
  for (int i = 2; i <= n; ++i) {
    if (!v[i]) v[i] = p[++pn] = i;
    for (int j = 1; 1ll * i * p[j] <= n; ++j) {
      v[i * p[j]] = p[j];
      if (i % p[j] == 0) break;
    }
  }
}
void ins(int pos) {
  req[pos] = pos;
  for (int x = a[pos]; x > 1; x /= v[x]) vec[v[x]].push_back(pos);
}
void del(int pos) {
  req[pos] = pos;
  for (int x = a[pos]; x > 1; x /= v[x]) {
    if (vec[v[x]].empty()) {
      req[pos] = 0;
      return;
    }
    chkmn(req[pos], vec[v[x]].back());
    vec[v[x]].pop_back();
  }
}
int main() {
  eulerSieve();
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= n; ++i) scanf(" %c", opt + i);
  for (int i = 1; i <= n; ++i)
    if (opt[i] == '*')
      ins(i);
    else
      del(i);
  long long ans = 0;
  for (int i = n, top = 0; i; --i) {
    int cnt = 1;
    while (top and req[i] <= stk[top].first) cnt += stk[top--].second;
    stk[++top] = pair<int, int>(req[i], cnt);
    if (req[i] == i) ans += cnt;
  }
  printf("%lld\n", ans);
  return 0;
}
