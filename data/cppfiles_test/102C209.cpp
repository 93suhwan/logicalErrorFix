#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, X[N], Y[N];
char a[N];
void work() {
  cin >> n >> m;
  scanf("%s", a + 1);
  int s = strlen(a + 1);
  int xmn = 0, xmx = 0, ymn = 0, ymx = 0;
  int x = 0, y = 0, t = s;
  for (int i = 1; i <= s; i++) {
    if (a[i] == 'L') y--;
    if (a[i] == 'R') y++;
    if (a[i] == 'U') x--;
    if (a[i] == 'D') x++;
    xmn = min(xmn, x);
    xmx = max(xmx, x);
    ymn = min(ymn, y);
    ymx = max(ymx, y);
    X[i] = xmn;
    Y[i] = ymn;
    if (xmx - xmn >= n || ymx - ymn >= m) {
      t = i - 1;
      break;
    }
  }
  cout << -X[t] + 1 << " " << -Y[t] + 1 << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) work();
  return 0;
}
