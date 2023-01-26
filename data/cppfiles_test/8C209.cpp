#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int ans1 = n / 3;
    if (n % 3 == 1) ans1++;
    int ans2 = (n - ans1) / 2;
    cout << ans1 << " " << ans2 << endl;
  }
  return 0;
}
