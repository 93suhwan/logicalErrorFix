#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 1, 0, 0, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0, 0, 0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    long long f[n][4];
    memset(f, 0, sizeof(f));
    if (s[0] == '+') {
      f[0][0]++;
    } else {
      f[0][1]++;
    }
    for (int i = 1; i < n; i++) {
      if (i % 2) {
        if (s[i] == '+') {
          f[i][2]++;
        } else {
          f[i][3]++;
        }
      } else {
        if (s[i] == '+') {
          f[i][0]++;
        } else {
          f[i][1]++;
        }
      }
      f[i][0] += f[i - 1][0];
      f[i][1] += f[i - 1][1];
      f[i][2] += f[i - 1][2];
      f[i][3] += f[i - 1][3];
    }
    while (q--) {
      long long l, r;
      cin >> l >> r;
      if (l > r) swap(l, r);
      l--;
      r--;
      long long op = f[r][0];
      if (l > 0) op -= f[l - 1][0];
      long long on = f[r][1];
      if (l > 0) on -= f[l - 1][1];
      long long ep = f[r][2];
      if (l > 0) ep -= f[l - 1][2];
      long long en = f[r][3];
      if (l > 0) en -= f[l - 1][3];
      if (op + en - on - ep == 0) {
        cout << 0 << endl;
        continue;
      }
      if ((r - l + 1) % 2) {
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }
  return 0;
}
