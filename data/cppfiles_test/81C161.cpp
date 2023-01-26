#include <bits/stdc++.h>
using namespace std;
void File() {
  char output[100] = "C:\\Users\\Emiya\\Desktop\\out.txt";
  freopen(output, "w", stdout);
}
const int maxn = 3e5 + 10;
char s[maxn];
int v[maxn];
vector<int> pos[maxn + 1 << 1];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) {
      if (s[i] == '+')
        v[i] = 1;
      else
        v[i] = -1;
      if ((i - 1) & 1) v[i] *= -1;
      v[i] += v[i - 1];
      pos[v[i] + maxn].clear();
    }
    pos[0 + maxn].clear();
    pos[0 + maxn].push_back(0);
    for (int i = 1; i <= n; ++i) pos[v[i] + maxn].push_back(i);
    for (int tt = 1; tt <= m; ++tt) {
      int lf, rt;
      scanf("%d %d", &lf, &rt);
      int pos_0 = lf - 1, sv = v[lf - 1] + maxn;
      pos_0 = pos[sv][upper_bound(pos[sv].begin(), pos[sv].end(), rt) -
                      pos[sv].begin() - 1];
      if (pos_0 == rt)
        printf("0\n");
      else
        printf("%d\n", (rt - pos_0) & 1 ? 1 : 2);
    }
  }
  return 0;
}
