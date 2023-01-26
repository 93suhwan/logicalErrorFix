#include <bits/stdc++.h>
using namespace std;
int a[100], T, n;
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    int flag = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] == 1) flag = 1;
    }
    if (!flag) {
      cout << "0" << endl;
      continue;
    }
    int cnt1 = 0, cnt0 = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == 0) cnt0++;
      if (a[i] == 1) cnt1++;
    }
    long long ans = pow(2, cnt0) * cnt1;
    cout << ans << endl;
  }
  return 0;
}
