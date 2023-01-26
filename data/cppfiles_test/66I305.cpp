#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int a[1001];
  int i = 1, n = 1;
  while (n < 1001)
    if (i % 3 == 0) {
      i++;
      continue;
    } else if (i % 10 == 0) {
      i++;
      continue;
    } else {
      a[n] = i;
      n++;
      i++;
    }
  while (t--) {
    int k;
    cin >> k;
    cout << a[k] << endl;
  }
}
