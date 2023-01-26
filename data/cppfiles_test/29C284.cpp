#include <bits/stdc++.h>
using namespace std;
long long bi[61];
int main() {
  int T;
  cin >> T;
  bi[0] = 1;
  for (int i = 1; i <= 60; i++) {
    bi[i] = bi[i - 1] * 2;
  }
  while (T--) {
    int n;
    cin >> n;
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x == 1) {
        cnt1++;
      }
      if (x == 0) {
        cnt0++;
      }
    }
    long long ans = cnt1 * bi[cnt0];
    cout << ans << endl;
  }
  return 0;
}
