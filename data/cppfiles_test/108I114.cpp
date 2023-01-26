#include <bits/stdc++.h>
using namespace std;
long long i, j, p, q, n, m, t, k, ans;
bool b[100006];
struct Pic {
  long long first, second, ind;
} a[100006];
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
      if (a[i].first > p) {
        p = a[i].first;
        q = i;
      }
    }
    b[q] = 1;
    for (i = 1; i <= n; i++) cin >> a[i].second;
    p = LLONG_MAX;
    for (i = 1; i <= n; i++) {
      if (a[i].second > a[q].second) p = min(p, a[i].first);
    }
    for (i = 1; i <= n; i++) {
      if (a[i].first >= p) b[i] = 1;
    }
    p = 0;
    for (i = 1; i <= n; i++) {
      if (a[i].second > p) {
        p = a[i].second;
        q = i;
      }
    }
    b[q] = 1;
    p = LLONG_MAX;
    for (i = 1; i <= n; i++) {
      if (a[i].first > a[q].first) p = min(p, a[i].second);
    }
    for (i = 1; i <= n; i++) {
      if (a[i].second >= p) b[i] = 1;
    }
    for (i = 1; i <= n; i++) cout << b[i];
    cout << endl;
  }
  return 0;
}
