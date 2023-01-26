#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int grp = n / k;
  if (n % k) grp++;
  cout << grp << endl;
  int a[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int g1 = i / k;
      int g2 = j / k;
      if (g1 == g2) {
        a[i][j] = 0;
      } else {
        a[i][j] = g1 + 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cout << a[i][j] + 1 << " ";
    }
  }
}
