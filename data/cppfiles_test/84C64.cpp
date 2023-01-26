#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s, median;
    cin >> n >> s;
    median = (n - 1) / 2;
    int a, ans;
    a = (n - median);
    ans = (s / a);
    cout << ans << endl;
  }
  return 0;
}
