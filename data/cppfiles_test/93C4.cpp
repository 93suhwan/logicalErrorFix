#include <bits/stdc++.h>
using namespace std;
unsigned long long n, x, y;
int main() {
  std::ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x >> y;
    if (x == 1) {
      cout << 0 << '\n';
      continue;
    }
    unsigned long long z = 1, h = 0;
    while ((z << 1) < y) z = z << 1, h++;
    z = z << 1, h++;
    if (z >= x) {
      cout << h << '\n';
      continue;
    }
    unsigned long long f = (x - z);
    if (!(f % y))
      cout << h + f / y << '\n';
    else
      cout << h + f / y + 1 << '\n';
  }
}
