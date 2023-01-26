#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const long long int N = 1e3 + 10;
int cnt[N][10];
bool prime(long long int n) {
  if (n == 0 || n == 1) return false;
  for (long long int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    memset(cnt, 0, sizeof(cnt));
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) cnt[i][s[i] - '0']++;
    for (int i = n - 1; i >= 0; i--)
      for (int j = 1; j <= 10; j++) cnt[i][j] += cnt[i + 1][j];
    if (cnt[0][1] > 0) {
      cout << "1\n1\n";
      continue;
    }
    if (cnt[0][2] > 1) {
      cout << "2\n22\n";
      continue;
    }
    if (cnt[0][3] > 1) {
      cout << "2\n33\n";
      continue;
    }
    if (cnt[0][4] > 0) {
      cout << "1\n4\n";
      continue;
    }
    if (cnt[0][5] > 1) {
      cout << "2\n55\n";
      continue;
    }
    if (cnt[0][6] > 0) {
      cout << "1\n6\n";
      continue;
    }
    if (cnt[0][7] > 1) {
      cout << "2\n77\n";
      continue;
    }
    if (cnt[0][8] > 0) {
      cout << "1\n8\n";
      continue;
    }
    if (cnt[0][9] > 0) {
      cout << "1\n9\n";
      continue;
    }
    for (int i = 0; i < 1 << n; i++) {
      int cur = 0, cnt = 0;
      for (int j = 0; j < n; j++)
        if (i >> j & 1) cur = cur * 10 + s[j] - '0', cnt++;
      if (!prime(cur) && cur) cout << cnt << '\n' << cur << '\n';
    }
  }
  return 0;
}
