#include <bits/stdc++.h>
using namespace std;
int t, n, k;
struct point {
  int x;
  int y;
};
point v[101];
int f[202], rms[202];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t) {
    t--;
    cin >> n;
    cin >> k;
    for (int i = 1; i <= 2 * n; i++) f[i] = 0, rms[i] = 0;
    for (int i = 1; i <= k; i++) {
      cin >> v[i].x >> v[i].y;
      if (v[i].x > v[i].y) swap(v[i].y, v[i].x);
      f[v[i].x] = 1;
      f[v[i].y] = 1;
    }
    int cnt = 0, ans = 0;
    for (int i = 1; i <= 2 * n; i++)
      if (f[i] == 0) {
        cnt++;
        rms[cnt] = i;
      }
    for (int i = k + 1; i <= n; i++) {
      v[i].x = rms[i - k];
      v[i].y = rms[i - k + n - k];
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if ((v[i].x > v[j].x && v[i].y > v[j].y && v[j].y > v[i].x) ||
            (v[i].x < v[j].x && v[i].y < v[j].y && v[i].y > v[j].x))
          ans++;
    cout << ans / 2 << "\n";
  }
  return 0;
}
