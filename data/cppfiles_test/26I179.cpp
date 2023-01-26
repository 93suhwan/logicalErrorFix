#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 1e5;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string second;
    cin >> second;
    int n = second.size();
    int ans = 10;
    for (int x = 0; x < 2; x++) {
      string curr = "";
      for (int i = 0; i < n; i++) {
        if (second[i] == '?') {
          if (i % 2 == x)
            curr += '1';
          else
            curr += '0';
        } else {
          curr += second[i];
        }
      }
      int a = 0;
      int b = 0;
      for (int j = 0; j < n; j++) {
        if (curr[j] == '1') {
          if (j % 2 == 0)
            a += 1;
          else
            b += 1;
        }
        if (x == 0) {
          if (a > (b + (n - (j + 1)) / 2 + 1)) ans = min(ans, j + 1);
        } else {
          if (b > (a + (n - (j + 1)) / 2)) ans = min(ans, j + 1);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
