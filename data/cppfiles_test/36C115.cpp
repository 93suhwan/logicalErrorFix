#include <bits/stdc++.h>
using namespace std;
struct Node {
  int val;
  int idx;
} now;
queue<Node> q;
int t;
int n;
int num[105];
int ans[105];
int tot;
int sum;
bool is_prime(int x) {
  if (x == 1) return true;
  int bound = sqrt(x);
  for (int i = 2; i <= bound; ++i) {
    if (!(x % i)) return false;
  }
  return true;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    while (!q.empty()) q.pop();
    memset(ans, 0, sizeof ans);
    sum = 0;
    tot = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", num + i);
      sum += num[i];
      if (!(num[i] & 1))
        ans[tot++] = i;
      else {
        now.idx = i;
        now.val = num[i];
        q.push(now);
      }
    }
    if (!is_prime(sum)) {
      printf("%d\n", n);
      for (int i = 1; i <= n; ++i) {
        if (i != 1) printf(" ");
        printf("%d", i);
      }
      printf("\n");
      continue;
    } else {
      printf("%d\n", n - 1);
      for (int i = 0; i < tot; ++i) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]);
      }
      while (q.size() > 1) {
        printf(" %d", q.front().idx);
        q.pop();
      }
      printf("\n");
    }
  }
  return 0;
}
