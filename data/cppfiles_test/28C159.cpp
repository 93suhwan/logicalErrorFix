#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
int aa[N], bb[N], cc[N], qu[3];
bool check(int *aa, int n, int m, int k) {
  for (int i = 0; i < n; i++) bb[i] = aa[(i + k) % n];
  m -= n;
  for (int i = 0; i < n; i++) {
    if (bb[i] == -1) continue;
    for (int j = i, j_; (j_ = bb[j]) != -1; j = j_) bb[j] = -1;
    m++;
  }
  return m >= 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    fill(cc, cc + n, 0);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a, a--;
      cc[(i - (aa[i] = a) + n) % n]++;
    }
    int cnt = 0;
    for (int k = 0; k < n; k++)
      if (cc[k] >= n - n / 3 * 2 && check(aa, n, m, k)) qu[cnt++] = k;
    cout << cnt;
    for (int h = 0; h < cnt; h++) cout << ' ' << qu[h];
    cout << '\n';
  }
  return 0;
}
