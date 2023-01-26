#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
struct node {
  int a, b;
} a[N];
inline bool cmp(const node &a, const node &b) {
  int v1 = max(a.a, a.b), v2 = max(b.a, b.b);
  if (v1 != v2) return v1 < v2;
  return a.a < b.a;
}
int n, d;
int main() {
  n = in(), d = in();
  for (int i = 1; i <= n; i++) a[i].a = in(), a[i].b = in();
  sort(a + 1, a + n + 1, cmp);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (d <= a[i].a) {
      ans++;
      d = max(d, a[i].b);
    }
  }
  cout << ans;
  return 0;
}
