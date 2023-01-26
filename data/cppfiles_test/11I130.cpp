#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
namespace Seg {
int f[N << 1];
inline void Init() {
  for (int i = 0; i < N << 1; ++i) f[i] = -1e9;
}
inline void Update(int x, int y) {
  for (int i = N + x; i; i >>= 1) f[i] = max(f[i], y);
}
inline int Ask(int x, int y) {
  int ans = -1e9;
  for (int l = N + x - 1, r = N + y + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
    if (~l & 1) ans = max(ans, f[l ^ 1]);
    if (r & 1) ans = max(ans, f[r ^ 1]);
  }
  return ans;
}
}  // namespace Seg
int n;
pair<int, int> p[N];
int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; ++i) {
    scanf("%d", &x);
    p[i] = pair<int, int>(x, i - x + 2e5);
  }
  Seg::Init();
  Seg::Update(2e5, 0);
  sort(p + 1, p + n + 1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int f = Seg::Ask(1, p[i].second) + 1;
    ans = max(ans, f);
    Seg::Update(p[i].second, f);
  }
  printf("%d\n", ans);
  return 0;
}
