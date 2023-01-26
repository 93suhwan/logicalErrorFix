#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int a[1000];
  int i = 1;
  int j = 0;
  while (i < 1667) {
    if (i % 3 != 0 && i % 10 != 3) {
      a[j] = i;
      j++;
    }
    i++;
  }
  while (t--) {
    int k;
    cin >> k;
    cout << a[k - 1] << endl;
  }
}
