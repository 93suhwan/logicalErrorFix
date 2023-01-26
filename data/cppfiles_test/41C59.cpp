#include <bits/stdc++.h>
using namespace std;
const int mxn = 1000;
int n, m, k;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i < n; i *= m) k++;
  cout << k << '\n';
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int x = 0;
      for (int ii = i, jj = j, l = 0; l < k; ii /= m, jj /= m, l++) {
        if (ii % m != jj % m) x = l;
      }
      cout << (x + 1) << (i != n - 2 || j != n - 1 ? ' ' : '\n');
    }
  return 0;
}
