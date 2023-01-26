#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
struct NODE {
  int s, a;
} N[maxn];
bool cmp(NODE A, NODE B) {
  if (max(A.s, A.a) == max(B.s, B.a)) {
    return A.s < B.s;
  }
  return max(A.s, A.a) < max(B.s, B.a);
}
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &N[i].s, &N[i].a);
  }
  sort(N + 1, N + n + 1, cmp);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (N[i].s >= d) {
      d = max(d, N[i].a);
      ans++;
    }
  }
  printf("%d", ans);
}
