#include <bits/stdc++.h>
using namespace std;
void File() {
  char output[100] = "C:\\Users\\Emiya\\Desktop\\out.txt";
  freopen(output, "w", stdout);
}
const int maxn = 3e5 + 10;
char s[maxn];
int v[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    scanf("%d%d%s", &n, &m, s + 1);
    unordered_map<int, vector<int>> pos;
    for (int i = 1; i <= n; ++i) {
      v[i] = v[i - 1] + (i % 2 ? 1 : -1) * (s[i] == '+' ? 1 : -1);
      pos[v[i] + v[i - 1]].push_back(i);
    }
    for (int tt = 1; tt <= m; ++tt) {
      int lf, rt;
      scanf("%d %d", &lf, &rt);
      if (v[rt] == v[lf - 1]) {
        printf("0\n");
        continue;
      } else if ((rt - lf + 1) & 1)
        printf("1\n");
      else
        printf("2\n%d ", lf++);
      int vv = v[rt] + v[lf - 1];
      auto it = pos[vv];
      printf("%d\n", *lower_bound(it.begin(), it.end(), lf));
    }
  }
  return 0;
}
