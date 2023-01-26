#include <bits/stdc++.h>
using namespace std;
int n, k, f[1005][1005], ff[1005], ec[1005][1005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  ff[1] = 1;
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    vector<int> v(ff + 1, ff + i);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    reverse(v.begin(), v.end());
    for (int j = 1; j < i; j++) {
      for (int x : v)
        if (f[j][x] < k - 1) {
          f[i][x] = max(f[i][x], f[j][x] + 1);
          ec[j][i] = x;
          ans = max(ans, x);
          break;
        }
    }
    ff[i] = 1;
    while (f[i][ff[i]] == k - 1) ff[i]++;
  }
  cout << ans << '\n';
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cout << ec[i][j] << ' ';
    }
  }
  return 0;
}
