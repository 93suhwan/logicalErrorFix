#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k, a = 1;
    cin >> k;
    int arr[1000];
    for (int i = 1; i <= 1000; i++) {
      if (a % 3 != 0 && a % 10 != 3) {
        arr[i] = a;
      } else {
        i--;
      }
      a++;
    }
    cout << arr[k] << endl;
  }
}
