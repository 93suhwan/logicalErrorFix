#include <bits/stdc++.h>
const double eps = 1e-15;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e6 + 10;
using namespace std;
vector<int> v[101];
int vis[maxn], n;
char s[maxn], p;
void init() {
  int n = 10;
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= 5; j++) {
      if (i % j) {
        v[j].push_back(i);
        break;
      }
    }
  }
  for (int i = 1; i <= 5; i++) {
    if (v[i].size()) {
      for (auto j : v[i]) vis[j] = i;
    }
  }
}
void solve() {
  set<int> st;
  scanf("%d", &n);
  getchar(), p = getchar();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] != p) st.insert(vis[i]);
  }
  printf("%d\n", st.size());
  for (auto k : st) printf("%d ", k);
  if (st.size()) puts("");
}
int main() {
  init();
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
