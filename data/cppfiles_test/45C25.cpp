#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a = 0;
    int n;
    cin >> n;
    int arr[n];
    int height = 1;
    for (int j = 0; j < n; j++) {
      cin >> arr[j];
    }
    for (int k = 0; k < n; k++) {
      if (arr[k] == 1) {
        height++;
      }
      if (k >= 1) {
        if (arr[k] == 0 && arr[k - 1] == 0) {
          cout << "-1" << endl;
          a = 1;
          break;
        }
        if (arr[k] == 1 && arr[k - 1] == 1) {
          height += 4;
        }
      }
    }
    if (a == 0) cout << height << endl;
  }
  return 0;
}
