#include <bits/stdc++.h>
using namespace std;
long long shu[100000];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int T;
  cin >> T;
  shu[1] = 1;
  int t = 1;
  int cnt = 2;
  for (int i = 2; shu[i - 1] <= 1e9 + 2; i++) {
    shu[i] = shu[i - 1] + t;
    t += 2;
    cnt++;
  }
  while (T--) {
    int k;
    cin >> k;
    int w = upper_bound(shu, shu + cnt, k) - shu;
    w--;
    int ju = shu[w + 1] - shu[w];
    ju = (ju - 1) / 2;
    if (k <= (shu[w] + ju)) {
      int x = k - shu[w] + 1;
      cout << x << ' ' << w << endl;
    } else {
      int y = w;
      int s = shu[w] + ju;
      int x = y - (k - s);
      cout << y << ' ' << x << endl;
    }
  }
}
