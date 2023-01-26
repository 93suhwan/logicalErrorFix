#include <bits/stdc++.h>
using namespace std;
namespace IO {
inline int read() {
  int w = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    w = (w << 1) + (w << 3) + (ch ^ 48);
    ch = getchar();
  }
  return w * f;
}
}  // namespace IO
using namespace IO;
namespace CL {
const int maxn = 5e5 + 5;
int n, D, ans;
pair<int, int> a[maxn];
inline int main() {
  n = read(), D = read();
  for (int i = 1; i <= n; i++) a[i].first = read(), a[i].second = read();
  sort(a + 1, a + 1 + n, [](pair<int, int> a, pair<int, int> b) -> bool {
    if (max(a.first, a.second) != max(b.first, b.second))
      return max(a.first, a.second) < max(b.first, b.second);
    return a.first < b.first;
  });
  for (int i = 1; i <= n; i++)
    if (a[i].first >= D) ans++, D = max(D, a[i].second);
  printf("%d\n", ans);
  return 0;
}
}  // namespace CL
signed main() { return CL::main(); }
