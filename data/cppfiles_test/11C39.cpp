#include <bits/stdc++.h>
struct Node {
  int val;
  int idx;
};
const int maxn = 2e5 + 10;
int n;
Node arr[maxn];
int b[maxn], cnt;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i].idx);
    arr[i].val = i - arr[i].idx;
  }
  std::sort(arr + 1, arr + 1 + n, [](const Node &a, const Node &b) {
    if (a.val == b.val) return a.idx < b.idx;
    return a.val < b.val;
  });
  for (int i = 1; i <= n; i++) {
    if (arr[i].val < 0) continue;
    int dex = std::lower_bound(b + 1, b + cnt + 1, arr[i].idx) - b;
    b[dex] = arr[i].idx;
    cnt = std::max(cnt, dex);
  }
  printf("%d\n", cnt);
  return 0;
}
