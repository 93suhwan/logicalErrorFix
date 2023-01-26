#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 10;
int tim[N][10];
int cnt1, cnt2;
int n;
int check(int x, int y) {
  int cnt1 = 0;
  int cnt2 = 0;
  for (int i = 1; i <= n; i++) {
    if (tim[i][x] && !tim[i][y]) ++cnt1;
    if (tim[i][y] && !tim[i][x]) ++cnt2;
  }
  for (int i = 1; i <= n; i++) {
    if (tim[i][x] && tim[i][y]) ++cnt1;
    if (tim[i][y] && tim[i][x]) ++cnt2;
  }
  return cnt1 >= n / 2 && cnt2 >= n / 2;
}
void sovle() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 5; j++) cin >> tim[i][j];
  for (int i = 1; i <= 5; i++)
    for (int j = i + 1; j <= 5; j++) {
      if (check(i, j)) {
        cout << "YES" << endl;
        return;
      }
    }
  cout << "NO" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    sovle();
  }
  return 0;
}
