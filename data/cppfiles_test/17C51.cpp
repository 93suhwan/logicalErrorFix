#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int inf = 0x3f3f3f3f;
int t;
int n;
int a[50020][7];
int cmp(int x, int y) {
  int flag = 0;
  for (int i = (1); i <= (5); i++) {
    if (a[x][i] < a[y][i]) flag++;
  }
  if (flag >= 3)
    return 1;
  else
    return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cin.tie(0);
  cin >> t;
  while (t--) {
    int m = 1, flag = 1;
    cin >> n;
    for (int i = (1); i <= (n); i++)
      cin >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4] >> a[i][5];
    if (n == 1) {
      cout << "1" << endl;
      continue;
    }
    for (int i = (2); i <= (n); i++) {
      if (cmp(i, m)) m = i;
    }
    for (int i = (1); i <= (n); i++) {
      if (i == m) continue;
      if (cmp(i, m)) {
        flag = 0;
        break;
      }
    }
    if (flag == 0) {
      cout << "-1" << endl;
      continue;
    }
    cout << m << endl;
  }
}
