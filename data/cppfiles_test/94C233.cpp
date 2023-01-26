#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = 0, y = 0;
    int digits = 0;
    for (int temp = n; temp > 0; temp /= 10) {
      digits++;
      if (digits % 2 == 0) {
        x = x + pow(10, ((digits - 1) / 2)) * (temp % 10);
      } else {
        y = y + pow(10, (digits / 2)) * (temp % 10);
      }
    }
    int ans = y * (x + 1) + x - 1;
    cout << ans << endl;
  }
  return 0;
}
