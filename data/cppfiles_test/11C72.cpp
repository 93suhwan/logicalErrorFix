#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = ' ';
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = -1;
  }
  while (isdigit(ch)) x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * f;
}
const int N = 2e5;
int n, f[200005], c[200005], ans;
void jia(int i, int x) {
  while (i <= 200001) {
    c[i] = max(c[i], x);
    i += i & -i;
  }
}
int he(int x) {
  int s = 0;
  while (x) {
    s = max(s, c[x]);
    x -= x & -x;
  }
  return s;
}
pair<int, int> a[200005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x = read();
    a[i] = {i - x, x};
  }
  sort(a + 1, a + n + 1);
  jia(1, 1);
  for (int i = 1; i <= n; i++) {
    if (a[i].first < 0) continue;
    f[i] = he(a[i].second);
    jia(a[i].second + 1, f[i] + 1);
    ans = max(ans, f[i]);
  }
  cout << ans;
}
