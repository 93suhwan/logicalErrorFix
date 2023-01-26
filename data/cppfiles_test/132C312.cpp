#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
template <typename T>
void inline read(T &x) {
  int f = 1;
  x = 0;
  char s = getchar();
  while (s<'0' | s> '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s <= '9' && s >= '0')
    x = (x << 3) + (x << 1) + (s ^ 48), s = getchar();
  x *= f;
}
long long n, m, x, y, a[N], b[N];
vector<long long> G[N];
inline void run() {
  for (long long i = (long long)(1); i <= (long long)(7); i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 8);
  cout << a[1] << " " << a[2] << " " << a[7] - a[1] - a[2] << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  long long T;
  for (cin >> T; T > 0; T--) run();
  return 0;
}
