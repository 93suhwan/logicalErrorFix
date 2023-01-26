#include <bits/stdc++.h>
using namespace std;
const int N = 109;
int T, n;
int a[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 1e9 + 7;
    for (int i = 0; i <= 2; i++)
      for (int j = 0; j <= 2; j++) {
        int temp = 0;
        for (int k = 1; k <= n; k++) {
          int minn = 1e9 + 7;
          for (int x = 0; x <= i; x++)
            for (int y = 0; y <= j; y++)
              if (a[k] - x - y * 2 >= 0 && (a[k] - x - y * 2) % 3 == 0)
                minn = min(minn, (a[k] - x - y * 2) / 3);
          temp = max(temp, minn);
        }
        ans = min(ans, temp + i + j);
      }
    cout << ans << "\n";
  }
  return 0;
}
