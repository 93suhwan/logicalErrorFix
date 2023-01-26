#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int MAX_N = 21;
const long long MOD = 1000000007;
const int INF = 0x3f3f3f3f;
int n, k;
int lef[1 << MAX_N], rig[1 << MAX_N], mnval[1 << MAX_N], level[1 << MAX_N],
    mn[1 << MAX_N], mx[1 << MAX_N], ans[1 << MAX_N];
int st[MAX_N], nums[1 << MAX_N];
int main(int argc, const char* argv[]) {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n >> k;
  for (int i = (0); i < (1 << k); i++) lef[i] = 2 * i + 1, rig[i] = 2 * i + 2;
  for (int i = (0); i < (1 << (k + 1)); i++) mn[i] = INF, mx[i] = -INF;
  for (int i = (1); i < (1 << (k + 1)); i++) {
    level[i] = level[(i - 1) / 2] + 1;
    st[level[i]] = max(st[level[i]], i);
    mnval[i] = mnval[(i - 1) / 2] + ((!(i & 1)) << (k - level[i]));
  }
  for (int i = (0); i < (n); i++) {
    int x;
    cin >> x;
    int curr = 0;
    mn[0] = min(mn[0], x), mx[0] = max(mx[0], x);
    for (int j = (k)-1; j >= (0); j--) {
      if (x & (1 << j))
        curr = rig[curr];
      else
        curr = lef[curr];
      mn[curr] = min(mn[curr], x - mnval[curr]);
      mx[curr] = max(mx[curr], x - mnval[curr]);
    }
  }
  for (int i = (0); i < ((1 << (k + 2))); i++) ans[i] = INF;
  for (int i = (st[k - 1] + 1) - 1; i >= (0); i--) {
    ans[i] = min(ans[lef[i]], ans[rig[i]]);
    ans[i] =
        min(ans[i], ((mn[rig[i]] != INF && mx[lef[i]] != -INF)
                         ? (mn[rig[i]] + (1 << (k - level[i] - 1)) - mx[lef[i]])
                         : (INF)));
  }
  nums[0] = ans[0];
  for (int i = (1); i < (1 << k); i++) {
    int x = i ^ (i - 1);
    for (int j = (0); j < (k); j++)
      if (x & (1 << j)) {
        int y = st[j];
        while (~y) {
          if (level[y] == j) swap(lef[y], rig[y]);
          mn[y] = min(mn[lef[y]], mn[rig[y]] + (1 << (k - level[y] - 1)));
          mx[y] = mx[rig[y]] + (1 << (k - level[y] - 1));
          if (mx[rig[y]] == -INF) mx[y] = mx[lef[y]];
          ans[y] = min(ans[lef[y]], ans[rig[y]]);
          ans[y] =
              min(ans[y],
                  ((mn[rig[y]] != INF && mx[lef[y]] != -INF)
                       ? (mn[rig[y]] + (1 << (k - level[y] - 1)) - mx[lef[y]])
                       : (INF)));
          y--;
        }
      }
    int y = 0;
    for (int j = (0); j < (k); j++)
      if (i & (1 << j)) y += (1 << (k - j - 1));
    nums[y] = ans[0];
  }
  for (int i = (0); i < (1 << k); i++) cout << nums[i] << ' ';
  cout << endl;
  return 0;
}
