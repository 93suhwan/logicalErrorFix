#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const int oo = 1e9 + 7;
void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
bool check(int** a, int m, int n, int mid) {
  vector<int> mark(n + 1, 0);
  int same = 0;
  for (int i = 1; i <= m; i++) {
    int num = 0;
    for (int j = 1; j <= n; j++) {
      if (a[i][j] >= mid) {
        num++;
        mark[j] = 1;
      }
    }
    if (num >= 2) same = 1;
  }
  for (int i = 1; i <= n; i++) same &= mark[i];
  return same;
}
int main() {
  init();
  int t;
  cin >> t;
  while (t--) {
    int m, n;
    cin >> m >> n;
    int** a = new int*[m + 1];
    for (int i = 1; i <= m; i++) {
      a[i] = new int[n + 1];
      for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
      }
    }
    int l = 1, r = 1e9 + 5;
    int res;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (check(a, m, n, mid)) {
        res = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    cout << res << endl;
  }
}
