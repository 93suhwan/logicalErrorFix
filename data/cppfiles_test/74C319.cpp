#include <bits/stdc++.h>
using namespace std;
const int NMAX = 100;
void breakGame(int a, int b) {
  int n = abs(a - b), j, h, k, dk;
  h = min(a, b);
  dk = 2 * h;
  k = h + 1;
  if (n & 1) k *= 2;
  cout << k << "\n";
  if (n % 2 == 0) {
    for (j = 0; j <= dk; j += 2) cout << n / 2 + j << " ";
  } else
    for (j = 0; j <= dk; j += 2)
      cout << n / 2 + j << " " << n / 2 + j + 1 << " ";
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
