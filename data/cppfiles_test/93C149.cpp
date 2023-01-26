#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int arr[300006];
  arr[0] = 0;
  for (int i = 1; i <= 300005; i++) {
    arr[i] = i;
    arr[i] = arr[i] ^ arr[i - 1];
  }
  while (t--) {
    int a, b;
    cin >> a >> b;
    int xorl = arr[a - 1] ^ b;
    if (xorl == a) {
      cout << a + 2 << endl;
      continue;
    } else if (xorl == 0) {
      cout << a << endl;
    } else {
      cout << a + 1 << endl;
    }
  }
}
