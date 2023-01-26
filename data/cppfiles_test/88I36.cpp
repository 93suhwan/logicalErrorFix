#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, m, ans, s[N];
pair<int, int> a[N];
bool mark[N];
void read_input() {
  cin >> n >> m;
  for (int i = 0; i < n * m; i++) {
    cin >> a[i].first;
    a[i].second = -i;
  }
}
void write_output() {
  sort(a, a + n * m);
  ans = 0;
  for (int i = 0; i < n * m; i++) s[-a[i].second] = i;
  int L = 0, R = 0;
  for (int i = 1; i < n * m; i++) {
    if (a[i].first == a[i - 1].first) R++;
    if (a[i].first != a[i - 1].first || i == n * m - 1) {
      int rw1 = s[-a[L].second] / m;
      int rw2 = s[-a[R].second] / m;
      if (rw1 != rw2) {
        int L2 = L;
        int R2 = R;
        while (L2 < n - 1 && s[-a[L2 + 1].second] / m == s[-a[L].second] / m)
          L2++;
        while (R2 > 0 && s[-a[R2 - 1].second] / m == s[-a[R].second] / m) R2--;
        int sz = min(L2 - L + 1, R - R2 + 1);
        for (int i = L; i < L + sz; i++) swap(a[i], a[R - (i - L)]);
      }
      L = R = i;
    }
  }
  for (int i = 0; i < n; i++) sort(a + (i * m), a + ((i + 1) * m));
  for (int i = 0; i < n * m; i++) s[-a[i].second] = i;
  for (int i = 0; i < n * m; i++) {
    int row = s[i] / m;
    int col = s[i] % m;
    for (int j = row * m; j < row * m + col; j++) ans += mark[j];
    mark[s[i]] = true;
  }
  for (int i = 0; i < n * m; i++) mark[i] = false;
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    read_input();
    write_output();
  }
}
