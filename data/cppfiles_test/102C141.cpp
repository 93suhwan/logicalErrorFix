#include <bits/stdc++.h>
using namespace std;
void RUN() { ios::sync_with_stdio(false), cin.tie(nullptr); }
int main() {
  RUN();
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int curY = 0, y = 1, L = 0, R = 0;
    int curX = 0, x = 1, U = 0, D = 0;
    for (auto c : s) {
      curY -= c == 'L', curY += c == 'R';
      L = min(L, curY), R = max(R, curY);
      curX -= c == 'U', curX += c == 'D';
      U = min(U, curX), D = max(D, curX);
      if (R - L + 1 <= m && D - U + 1 <= n) x = -U + 1, y = -L + 1;
    }
    cout << x << " " << y << '\n';
  }
}
