#include <bits/stdc++.h>
using namespace std;
int calc(int n, int m, int rc, int cc, int rd, int cd) {
  int sec = 0;
  int dr = 1, dc = 1;
  while (rc != rd && cc != cd) {
    if (rc + dr > n) dr *= -1;
    if (cc + dc > m) dc *= -1;
    rc += dr;
    cc += dc;
    sec++;
  }
  return sec;
}
int main() {
  int k;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    int n, m, rc, cc, rd, cd;
    cin >> n >> m >> rc >> cc >> rd >> cd;
    cout << calc(n, m, rc, cc, rd, cd) << endl;
  }
}
