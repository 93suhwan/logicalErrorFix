#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
void slove() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int ansx = 1, ansy = 1;
  int x = 0, y = 0, mnx = 0, mix = 0, mny = 0, miy = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'U')
      x--;
    else if (s[i] == 'D')
      x++;
    else if (s[i] == 'L')
      y--;
    else
      y++;
    mnx = max(mnx, x);
    mix = min(mix, x);
    mny = max(mny, y);
    miy = min(miy, y);
    if (mnx - mix + 1 > n || mny - miy + 1 > m) break;
    ansx = 1 - mix, ansy = 1 - miy;
  }
  cout << ansx << ' ' << ansy << endl;
  return;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    slove();
  }
  return 0;
}
