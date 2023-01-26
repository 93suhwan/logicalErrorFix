#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 7;
const int maxn = 5e4 + 7;
const int inf = 1e6 + 10;
const double pp = 1e-6;
template <class type>
inline void read(type &k) {
  k = 0;
  type t = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') t = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    k = k * 10 + ch - '0';
    ch = getchar();
  }
  k *= t;
}
inline long long gcd(long long x, long long y) {
  return y == 0 ? x : gcd(y, x % y);
}
long long qpow(long long a, long long b) {
  long long aa = 1;
  while (b) {
    if (b % 2 == 1) aa = (aa * a);
    a = (a * a);
    b /= 2;
  }
  return aa;
}
int a[MAXN], b[MAXN], tmp[MAXN];
long long merge_sort(int q[], int l, int r) {
  if (l >= r) return 0;
  int mid = l + r >> 1;
  long long res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
  int k = 0, i = l, j = mid + 1;
  while (i <= mid && j <= r)
    if (q[i] <= q[j])
      tmp[k++] = q[i++];
    else {
      res += mid - i + 1;
      tmp[k++] = q[j++];
    }
  while (i <= mid) tmp[k++] = q[i++];
  while (j <= r) tmp[k++] = q[j++];
  for (i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
  return res;
}
int main() {
  int t;
  read(t);
  while (t--) {
    int n;
    bool flag = false;
    read(n);
    for (int i = 1; i <= n; i++) {
      read(a[i]);
      b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    int now = 1;
    for (int i = 1; i <= n; i++) {
      if (i != 1 && b[i] == b[i - 1]) flag = true;
    }
    int ans = merge_sort(a, 1, n);
    printf((ans % 2) && !flag ? "NO\n" : "YES\n");
  }
}
