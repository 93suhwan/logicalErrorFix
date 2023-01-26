#include <bits/stdc++.h>
using namespace std;
int sum[51];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    memset(sum, 0, sizeof(int) * 51);
    int n;
    cin >> n;
    string str;
    cin >> str;
    int l, r;
    bool success = false;
    for (int i = 0; i < n; i++) {
      if (str[i] == 'a') {
        for (int j = 0; j < i; j++) {
          sum[j] += 1;
          if (!sum[j]) {
            l = j + 1;
            r = i + 1;
            success = true;
            break;
          }
        }
        sum[i] = 1;
      } else {
        for (int j = 0; j < i; j++) {
          sum[j] -= 1;
          if (!sum[j]) {
            l = j + 1;
            r = i + 1;
            success = true;
            break;
          }
        }
        sum[i] = -1;
      }
      if (success) break;
    }
    if (success)
      cout << l << ' ' << r << '\n';
    else
      cout << -1 << ' ' << -1 << '\n';
  }
}
