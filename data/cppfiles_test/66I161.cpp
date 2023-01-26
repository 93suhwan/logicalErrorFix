#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 0;
  cin >> t;
  int arr[1000];
  int i = 0, r = 1000, j = 0;
  while (i <= r) {
    if (i % 3 != 0 && i / 10 != 3) {
      arr[j++] = i;
    }
    i++;
  }
  while (t--) {
    int k = 0;
    cin >> k;
    cout << arr[k] << endl;
  }
  return 0;
}
