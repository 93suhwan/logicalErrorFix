#include <bits/stdc++.h>
#pragma gcc optimize(2)
using namespace std;
int read() {
  int w = 1, x = 0, ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') w = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * w;
}
int main() {
  ios::sync_with_stdio(false);
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    while (m-- > 1) {
      int temp = pow(10, (int)log10(n - m));
      cout << temp << " ";
      n -= temp;
    }
    cout << n << "\n";
  }
  return 0;
}
