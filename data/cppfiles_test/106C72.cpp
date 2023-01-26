#include <bits/stdc++.h>
using namespace std;
int t, a[10000000], i, j;
int main() {
  cin >> t;
  for (i = 0; i < t; i++) cin >> a[i];
  for (i = 0; i < t; i++) {
    if (a[i] == 1)
      cout << 1;
    else
      for (j = a[i]; j < a[i] * 2; j++) cout << j << " ";
    cout << '\n';
  }
}
