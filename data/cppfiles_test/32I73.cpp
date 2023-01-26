#include <bits/stdc++.h>
using namespace std;
long long pre[100005];
inline long long sum(int l, int r) { return pre[r] - pre[l - 1]; }
long long suf[450][100005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1, val; i <= n; i++) {
      cin >> val;
      pre[i] = pre[i - 1] + val;
    }
    int b = sqrt(n * 2) + 1;
    for (int i = 1; i <= b; i++) fill(suf[i] + 1, suf[i] + 1 + n + 1, -1);
    int ans = 1;
    for (int i = n; i >= 1; i--) {
      suf[1][i] = max(suf[1][i + 1], sum(i, i));
      for (int j = 2; j <= b && i + j - 1 <= n; j++) {
        long long now = sum(i, i + j - 1);
        long long from = suf[j - 1][i + j];
        if (now < from) suf[j][i] = max(suf[j][i + 1], now), ans = max(ans, j);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
