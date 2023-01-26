#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 10;
int powk[15];
int a[N][15];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  powk[0] = 1;
  int up = 0;
  while (powk[up] < n) {
    ++up;
    powk[up] = k * powk[up - 1];
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= up; j++) a[i][j] = (i / powk[j]) % k;
  cout << up << "\n";
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      for (int res = up; res >= 0; res--)
        if (a[i][res] != a[j][res]) {
          cout << res + 1 << " ";
          break;
        }
}
