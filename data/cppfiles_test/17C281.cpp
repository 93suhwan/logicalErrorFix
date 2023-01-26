#include <bits/stdc++.h>
using namespace std;
const long long N = 1e7 + 10;
const double PI = 3.1415926535898;
const long long mod = 1e9 + 7;
using namespace std;
int r[N][6];
void sovle() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 5; j++) {
      cin >> r[i][j];
    }
  }
  int ok = 1;
  if (n == 1) {
    cout << 1 << '\n';
    return;
  }
  for (int i = 2; i <= n; i++) {
    int tmp = 0;
    for (int j = 1; j <= 5; j++) {
      if (r[ok][j] > r[i][j]) tmp++;
    }
    if (tmp >= 3) ok = i;
  }
  for (int i = 1; i <= n; i++) {
    if (i == ok) continue;
    int tmp = 0;
    for (int j = 1; j <= 5; j++) {
      if (r[ok][j] < r[i][j]) tmp++;
    }
    if (tmp < 3) {
      cout << -1 << '\n';
      return;
    }
  }
  cout << ok << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    sovle();
  }
  return 0;
}
