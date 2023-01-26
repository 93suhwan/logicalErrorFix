#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(false);
  cin.tie(NULL);
  int T, n, sum;
  string friendly, enemy;
  cin >> T;
  while (T--) {
    sum = 0;
    cin >> n;
    cin >> enemy >> friendly;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        if (friendly[i] == '1' && i + 1 < n && enemy[i + 1] == '1') sum++;
      } else if (i == n - 1) {
        if (friendly[i] == '1' && enemy[i - 1] == '1') sum++;
      } else {
        if (friendly[i] == '1' &&
            (enemy[i - 1] == '1' || enemy[i + 1] == '1' || enemy[i] == '0'))
          sum++;
      }
    }
    cout << sum << '\n';
  }
  return 0;
}
