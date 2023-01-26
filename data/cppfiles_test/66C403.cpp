#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int num = 1;
  int a[8005];
  for (int i = 1; i <= 8005; i++) {
    if (i % 3 == 0 || i % 10 == 3) {
      continue;
    }
    a[num] = i;
    num++;
  }
  int k;
  while (t--) {
    cin >> k;
    cout << a[k] << endl;
  }
}
