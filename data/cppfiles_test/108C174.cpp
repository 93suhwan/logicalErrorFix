#include <bits/stdc++.h>
using namespace std;
void setIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
int64_t xyz = 1;
const int64_t N = 1e5 + 1;
int64_t n;
int64_t a[N];
int64_t b[N];
int64_t ao[N];
int64_t bo[N];
int64_t ans[N];
void run() {
  cin >> n;
  for (int64_t i = 1; i <= n; i++) ans[i] = 0;
  for (int64_t i = 1; i <= n; i++) cin >> a[i];
  for (int64_t i = 1; i <= n; i++) cin >> b[i];
  iota(ao + 1, ao + 1 + n, 1);
  iota(bo + 1, bo + 1 + n, 1);
  sort(ao + 1, ao + 1 + n, [](int64_t f, int64_t s) { return a[f] < a[s]; });
  sort(bo + 1, bo + 1 + n, [](int64_t f, int64_t s) { return b[f] < b[s]; });
  ans[ao[n]] = true;
  ans[bo[n]] = true;
  int64_t av = a[bo[n]];
  int64_t bv = b[ao[n]];
  for (int64_t ap = n - 1, bp = n - 1; ap || bp;) {
    if (ap && (ans[ao[ap]] || a[ao[ap]] > av)) {
      ans[ao[ap]] = true;
      bv = min(bv, b[ao[ap--]]);
      continue;
    }
    if (bp && (ans[bo[bp]] || b[bo[bp]] > bv)) {
      ans[bo[bp]] = true;
      av = min(av, a[bo[bp--]]);
      continue;
    }
    break;
  }
  for (int64_t i = 1; i <= n; i++) cout << ans[i];
  cout << "\n";
}
signed main() {
  setIO();
  cin >> xyz;
  while (xyz--) run();
  return 0;
}
