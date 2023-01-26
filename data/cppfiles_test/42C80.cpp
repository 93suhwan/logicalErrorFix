#include <bits/stdc++.h>
using namespace std;
int n;
int rquery(int* arr, int v) {
  int ans = 0;
  while (v) {
    ans += arr[v];
    if (ans >= 1000000007) ans -= 1000000007;
    v -= ((v) & (-(v)));
  }
  return ans;
}
int query(int* arr, int l, int r) {
  return (((rquery(arr, r) - rquery(arr, l - 1)) % 1000000007) + 1000000007) %
         1000000007;
}
void modify(int* arr, int loc, int val) {
  while (loc <= 2 * n) {
    arr[loc] += val;
    if (arr[loc] >= 1000000007) arr[loc] -= 1000000007;
    loc += ((loc) & (-(loc)));
  }
}
int a[400005], b[400005];
int taskid[400005];
bool isleft[400005];
bool inset[400005];
int stat_l[400005], stat_r[400005];
int reach[400005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", a + i, b + i);
    taskid[a[i]] = taskid[b[i]] = i;
    isleft[a[i]] = true;
  }
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    int s;
    scanf("%d", &s);
    inset[s] = true;
  }
  int oncnt = 0;
  for (int i = 2 * n; i >= 1; i--) {
    if (!isleft[i]) continue;
    int id = taskid[i];
    bool on = inset[id];
    if (!on) {
      int num = query(stat_r, a[id] + 1, b[id] - 1);
      if (num < oncnt) on = true;
    }
    if (on) {
      oncnt++;
      modify(stat_l, a[id], 1);
      modify(stat_r, b[id], 1);
      inset[id] = true;
    }
  }
  int ans = 0;
  for (int i = 2 * n; i >= 1; i--) {
    if (!isleft[i]) continue;
    int id = taskid[i];
    int reachv = rquery(reach, b[id]);
    reachv++;
    if (reachv >= 1000000007) reachv -= 1000000007;
    modify(reach, b[id] + 1, reachv);
    if (inset[id]) ans += reachv;
    if (ans >= 1000000007) ans -= 1000000007;
  }
  printf("%d\n", ans);
  return 0;
}
