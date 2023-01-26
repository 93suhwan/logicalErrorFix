#include <bits/stdc++.h>
using namespace std;
int up(double a) {
  int res = (int)a;
  if ((float)res == a) {
    return res;
  } else {
    return res + 1;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    if (n > s) {
      cout << 0 << endl;
      continue;
    }
    int m = up((float)n / 2.0);
    cout << s / (n - m + 1) << endl;
  }
  return 0;
}
