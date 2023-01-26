#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
const int inf = 0x3f3f3f3f;
struct edge {
  int l, r, w;
} f[MAXN];
bool cmp(edge x, edge y) { return x.w < y.w; }
struct Node {
  int l;
  int r;
  long long sum;
  long long lazy;
} node[MAXN << 2];
void push_down(int num) {
  if (node[num].lazy != 0) {
    int lazy = node[num].lazy;
    node[num << 1].sum += lazy;
    node[num << 1].lazy += lazy;
    node[num << 1 | 1].sum += lazy;
    node[num << 1 | 1].lazy += lazy;
    node[num].lazy = 0;
  }
}
void build(int left, int right, int num) {
  node[num].l = left;
  node[num].r = right;
  node[num].lazy = 0;
  if (left == right) {
    node[num].sum = 0;
    return;
  }
  int mid = (left + right) >> 1;
  build(left, mid, num << 1);
  build(mid + 1, right, num << 1 | 1);
  node[num].sum = min(node[num << 1].sum, node[num << 1 | 1].sum);
}
void updata2(int left, int right, int val, int num) {
  if (left <= node[num].l && node[num].r <= right) {
    node[num].sum += val;
    node[num].lazy += val;
    return;
  }
  push_down(num);
  int mid = (node[num].l + node[num].r) >> 1;
  if (mid >= left) {
    updata2(left, right, val, num << 1);
  }
  if (mid < right) {
    updata2(left, right, val, num << 1 | 1);
  }
  node[num].sum = min(node[num << 1].sum, node[num << 1 | 1].sum);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &f[i].l, &f[i].r, &f[i].w);
  }
  sort(f + 1, f + 1 + n, cmp);
  build(2, m, 1);
  int l = 1, r = 0;
  int cha = 1e9;
  while (1) {
    while (node[1].sum == 0 && r < n) {
      r++;
      updata2(f[r].l + 1, f[r].r, 1, 1);
    }
    while (node[1].sum != 0 && l <= r) {
      cha = min(cha, f[r].w - f[l].w);
      updata2(f[l].l + 1, f[l].r, -1, 1);
      l++;
    }
    if (r == n) break;
  }
  printf("%d\n", cha);
}
