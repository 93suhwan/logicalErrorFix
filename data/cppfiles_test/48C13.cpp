#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3fll;
const double pi = acos(-1.0);
int read() {
  int a = 0;
  int d = 1;
  char c;
  while (c = getchar(), c < '0' || c > '9')
    if (c == '-') d = -1;
  a = a * 10 + c - 48;
  while (c = getchar(), c >= '0' && c <= '9') a = a * 10 + c - 48;
  a *= d;
  return a;
}
int a[N];
int c[N];
map<int, bool> mp;
int ans;
;
void msort(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  msort(l, mid);
  msort(mid + 1, r);
  int i = l;
  int j = mid + 1;
  int idx = l;
  while (i <= mid && j <= r) {
    if (a[i] <= a[j])
      c[idx++] = a[i++];
    else {
      ans += mid - i + 1;
      c[idx++] = a[j++];
    }
  }
  while (i <= mid) c[idx++] = a[i++];
  while (j <= r) c[idx++] = a[j++];
  for (int k = l; k <= r; k++) a[k] = c[k];
}
signed main() {
  int t = read();
  while (t--) {
    mp.clear();
    int n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    bool f1 = false;
    bool f2 = false;
    for (int i = 1; i <= n; i++) {
      if (a[i] < a[i - 1]) f1 = true;
      if (mp[a[i]]) {
        f2 = true;
        break;
      }
      mp[a[i]] = true;
    }
    if (!f1 || f2) {
      puts("YES");
      continue;
    }
    if (n < 3) {
      puts("NO");
      continue;
    }
    ans = 0;
    msort(1, n);
    if (ans % 2 == 0)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
