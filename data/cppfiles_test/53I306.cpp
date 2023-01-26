#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int i;
  for (i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    int j;
    int a[n];
    for (j = 0; j < n; j++) {
      cin >> a[j];
    }
    int c = 0;
    for (j = 0; j < n - 1; j++) {
      while (j < n - 1 && a[j] < a[j + 1]) {
        j++;
      }
      c++;
    }
    if (j < n) c++;
    if (c <= k)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
