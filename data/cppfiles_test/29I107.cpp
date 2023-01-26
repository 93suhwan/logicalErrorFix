#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 2;
const int maxm = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int read() {
  int s = 0, w = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) {
    if (c == '-') w = -1;
  }
  for (; isdigit(c); c = getchar()) {
    s = (s << 3) + (s << 1) + (c ^ 48);
  }
  return (w == 1 ? s : -s);
}
struct fenwick {
  long long tree[maxn];
  void add(int pos, long long k) {
    for (; pos < maxn; pos += (pos) & (-pos)) tree[pos] += k;
  }
  long long query(int pos) {
    long long res = 0;
    for (; pos; pos -= (pos) & (-pos)) res += tree[pos];
    return res;
  }
  long long query(int l, int r) { return query(r) - query(l - 1); }
} f[2];
int n;
int a[maxn];
int main() {
  n = read();
  long long sum = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    ans += sum;
    long long temp = 0, cnt = 0;
    for (int j = a[i]; j < maxn; j += a[i]) {
      cnt++;
      temp += cnt * f[0].query(j, min(maxn - 1, j + a[i] - 1));
    }
    ans -= temp * a[i];
    f[0].add(a[i], 1);
    temp = (i - 1) * a[i];
    temp -= f[1].query(maxn - 1, a[i]);
    ans += temp;
    for (int j = a[i]; j < maxn; j += a[i]) {
      f[1].add(j, j);
      f[1].add(min(maxn - 1, j + a[i]), -j);
    }
    sum += a[i];
    printf("%lld\n", ans);
  }
  return 0;
}
