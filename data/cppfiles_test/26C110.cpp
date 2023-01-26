#include <bits/stdc++.h>
using namespace std;
const long long INF = 9e18;
const int inf = 2147483647;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
void work() {
  int t;
  cin >> t;
  while (t--) {
    string a;
    cin >> a;
    int cnt[2] = {0}, wenhao = 0;
    int ans = 10;
    for (int i = 0; i < 10; i++) {
      if (a[i] == '?')
        wenhao++;
      else {
        if (a[i] == '0')
          cnt[1 - i % 2]++;
        else
          cnt[i % 2]++;
      }
      int y = 10 - i - 1;
      bool ok = 0;
      for (int j = 0; j <= wenhao; j++) {
        int c1 = cnt[0] + j;
        int c2 = cnt[1] + wenhao - j;
        if (c1 + y < c2 || c2 + y < c1) {
          ans = i + 1;
          ok = 1;
          break;
        }
      }
      if (ok) break;
    }
    cout << ans << endl;
  }
}
int main() {
  work();
  return 0;
}
