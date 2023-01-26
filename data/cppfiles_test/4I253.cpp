#include <bits/stdc++.h>
using namespace std;
long long int dx[] = {1, -1, 1, -1, 0, -1, 0, 1};
long long int dy[] = {1, -1, -1, 1, 1, 0, -1, 0};
long double PI = acosl(-1);
long long int i = 0, j = 0, c = 0, mx = 0, n = 0, w, h, d = 0, k = 0, s = 0,
              f = 0, sum = 0, mid, t = 0, m = 0, l = 0, r = 0, x = 0, y = 0, u;
long long int a[200005];
void input() {
  memset(a, 0, sizeof(a));
  cin >> n >> m;
  while (m--) {
    cin >> l >> r;
    d = min(l, r);
    k = max(l, r);
    a[d]++;
  }
  for (i = 1; i <= n; i++) {
    if (a[i] == 0) {
      c++;
    }
  }
  cin >> s;
  while (s--) {
    cin >> f;
    if (f == 1) {
      cin >> l >> r;
      d = min(l, r);
      k = max(l, r);
      a[d]++;
      if (a[d] == 1) c--;
    } else if (f == 2) {
      cin >> l >> r;
      d = min(l, r);
      k = max(l, r);
      a[d]--;
      if (a[d] == 0) c++;
    } else
      cout << c << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  t = 1;
  while (t--) {
    input();
  }
  return 0;
}
