#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
const double dinf = 1e100;
using namespace std;
const int maxn = 2e5 + 10;
int a[26][maxn];
char s[maxn];
signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < n; j++) a[i][j] = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      int l = strlen(s);
      int temp[26] = {0};
      for (int j = 0; j < l; j++) {
        temp[s[j] - 'a']++;
      }
      for (int j = 0; j < 26; j++) {
        a[j][i] = 2 * temp[j] - l;
      }
    }
    int M = 0;
    for (int i = 0; i < 26; i++) {
      sort(a[i], a[i] + n, greater<int>());
      int s = 0;
      int sum = 0;
      for (int j = 0; j < n; j++) {
        if (sum + a[i][j] > 0) {
          sum += a[i][j];
          s++;
        } else {
          break;
        }
      }
      M = max(M, s);
    }
    cout << M << endl;
  }
  return 0;
}
