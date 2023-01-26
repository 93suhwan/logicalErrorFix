#include <bits/stdc++.h>
using namespace std;
int n, a[5][1010];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; i++)
      for (int j = 0, k; j < 5; j++) cin >> a[j][i];
    int possible = 0;
    for (int i = 0; i < 5; i++)
      for (int j = i + 1; j < 5; j++) {
        int oneStudentMissing = 0, c1 = 0, c2 = 0, c3 = 0;
        for (int s = 0; s < n; s++) {
          if (a[i][s] && !a[j][s])
            c1++;
          else if (!a[i][s] && a[j][s])
            c2++;
          else if (a[i][s] && a[j][s])
            c3++;
          else
            oneStudentMissing = 1;
        }
        if (oneStudentMissing) continue;
        if (c1 < n / 2) c3 -= n / 2 - c1;
        if (c2 < n / 2) c3 -= n / 2 - c2;
        if (c3 >= 0) {
          possible = 1;
          break;
        }
      }
    cout << (possible ? "YES\n" : "NO\n");
  }
}
