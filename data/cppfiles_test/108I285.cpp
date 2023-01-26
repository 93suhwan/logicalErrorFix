#include <bits/stdc++.h>
using namespace std;
long long i, j, p, q, n, m, t, k, ans;
bool b[100006];
struct Pic {
  long long first, second, ind, prf, prs;
} a[100006];
bool fff(Pic a, Pic b) { return (a.first < b.first); }
bool fff1(Pic a, Pic b) { return (a.second < b.second); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    fill(b + 1, b + n + 1, 0);
    p = 0;
    ans = 0;
    for (i = 1; i <= n; i++) {
      cin >> a[i].first;
      a[i].ind = i;
    }
    b[q] = 1;
    for (i = 1; i <= n; i++) cin >> a[i].second;
    sort(a + 1, a + n + 1, fff);
    for (i = 1; i <= n; i++) a[i].prs = max(a[i - 1].prs, a[i].second);
    p = a[n].ind;
    sort(a + 1, a + n + 1, fff1);
    for (i = 1; i <= n; i++) a[i].prf = max(a[i - 1].prf, a[i].first);
    q = a[n].ind;
    bool fl = 0;
    b[p] = 1;
    b[q] = 1;
    k = a[n].first;
    if (a[n].ind == p) fl = 1;
    for (i = n - 1; i >= 1; i--) {
      if (a[i].prf >= k) b[a[i].ind] = 1;
      if (a[i].ind == p) fl = 1;
      if (!fl) k = min(k, a[i].first);
    }
    fl = 0;
    sort(a + 1, a + n + 1, fff);
    k = a[n].second;
    if (a[n].ind == q) fl = 1;
    for (i = n - 1; i >= 1; i--) {
      if (a[i].prs >= k) b[a[i].ind] = 1;
      if (a[i].ind == q) fl = 1;
      if (!fl) k = min(k, a[i].second);
    }
    for (i = 1; i <= n; i++) cout << b[i];
    cout << endl;
  }
  return 0;
}
