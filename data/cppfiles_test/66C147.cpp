#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t;
  cin >> t;
  int a[2000];
  for (int i = 1, j = 1; i < 2000; i++, j++) {
    if (j % 3 == 0 || j % 10 == 3) j++;
    if (j % 10 == 3 || j % 3 == 0) j++;
    a[i] = j;
  }
  while (t--) {
    int k;
    cin >> k;
    cout << a[k] << endl;
  }
  return 0;
}
