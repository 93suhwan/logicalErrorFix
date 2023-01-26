#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s, median;
    cin >> n >> s;
    median = n / 2;
    int a, ans;
    if (s % 2 == 0 && s > 1) {
      a = (n - median) + 1;
      ans = (s / a);
    } else {
      a = (n - median);
      ans = (s / a);
    }
    if (s == 1) {
      ans = 0;
    }
    cout << ans << endl;
  }
  return 0;
}
