#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int t, n, k;
int a[maxn], num[maxn];
int NUM[maxn], vis[maxn];
struct node {
  int val;
  int pos;
  int color;
} it[maxn];
struct nnode {
  int l, r;
} pos[maxn];
bool cmp1(node a, node b) {
  if (num[a.val] != num[b.val])
    return num[a.val] > num[b.val];
  else if (a.val != b.val)
    return a.val < b.val;
  else
    return a.pos < b.pos;
}
bool cmp2(node a, node b) { return a.pos < b.pos; }
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int ans = 0;
    memset(NUM, 0, sizeof(NUM));
    memset(vis, 0, sizeof(vis));
    memset(pos, 0, sizeof(pos));
    int nnum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      it[i].val = a[i];
      it[i].pos = i;
      it[i].color = 0;
      num[i] = 0;
    }
    for (int i = 1; i <= n; i++) num[a[i]]++;
    for (int i = 1; i <= n; i++) {
      if (num[i]) {
        NUM[nnum++] = i;
        ans += min(num[i], k);
      }
    }
    int cnt = ans / k;
    sort(it + 1, it + 1 + n, cmp1);
    int all = cnt * k;
    int last = 0;
    for (int i = 1; i <= n; i++) {
      int nn = num[it[i].val], nnn = it[i].val;
      if (nn >= k) {
        int col = 1, j;
        for (j = i; j < i + k; j++) it[j].color = col++;
        while (it[j].val == nnn) j++;
        i = j - 1;
        all -= k;
      } else {
        last = i;
        break;
      }
    }
    for (int i = last; i <= n; i++) {
      if (all == 0) break;
      if ((i - last + 1) % k == 0)
        it[i].color = k;
      else
        it[i].color = (i - last + 1) % k;
      all--;
    }
    sort(it + 1, it + 1 + n, cmp2);
    for (int i = 1; i <= n; i++) {
      printf("%d ", it[i].color);
    }
    printf("\n");
  }
  return 0;
}
