#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 10;
int tim[N][10];
int cnt1, cnt2;
int n;
int check(int i1, int i2) {
  int cnt1 = 0;
  int cnt2 = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt1 == n / 2 && cnt2 == n / 2)
      break;
    else if (cnt1 < n / 2 && tim[i][i1] && !tim[i][i2])
      ++cnt1;
    else if (cnt2 < n / 2 && tim[i][i2] && !tim[i][i1])
      ++cnt2;
  }
  for (int i = 1; i <= n; i++) {
    if (cnt1 == n / 2 && cnt2 == n / 2)
      break;
    else if (cnt1 < n / 2 && tim[i][i1] && tim[i][i2])
      ++cnt1;
    else if (cnt2 < n / 2 && tim[i][i2] && tim[i][i1])
      ++cnt2;
  }
  if (cnt1 == n / 2 && cnt2 == n / 2)
    return true;
  else
    return 0;
}
void sovle() {
  cin >> n;
  memset(tim, 0, sizeof(tim));
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
