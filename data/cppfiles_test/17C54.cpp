#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n + 1][5];
    int flag = 1;
    int gold = 1;
    for (int i = 1; i <= n; i++) {
      int count = 0;
      for (int j = 0; j < 5; j++) {
        cin >> a[i][j];
        if (a[i][j] < a[gold][j]) count++;
      }
      if (count >= 3) gold = i;
    }
    for (int i = 1; i <= n && i != gold; i++) {
      int count = 0;
      for (int j = 0; j < 5; j++) {
        if (a[i][j] < a[gold][j]) count++;
      }
      if (count >= 3) {
        flag = 0;
        break;
      }
    }
    if (flag == 1)
      cout << gold << "\n";
    else
      cout << "-1\n";
  }
  return 0;
}
