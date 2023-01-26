#include <bits/stdc++.h>
using namespace std;
const int NMAX = 100;
inline void breakGame(int a, int b) {
  int n, j, k, dk;
  if (a > b) swap(a, b);
  dk = 2 * a;
  k = a + 1;
  n = b - a;
  if (n & 1) k *= 2;
  cout << k << "\n";
  int n2 = n / 2, l = dk + n2;
  if (n % 2 == 0) {
    for (j = n2; j <= l; j += 2) cout << j << " ";
  } else
    for (j = n2; j <= l; j += 2) cout << j << " " << j + 1 << " ";
  cout << "\n";
}
int main() {
  int t, a, b;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> a >> b;
    breakGame(a, b);
  }
  return 0;
}
