#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    int arr[n];
    int height = 1;
    int a = 0;
    for (int j = 0; j < n; j++) {
      cin >> arr[j];
      if (arr[j] == 1) {
        height++;
      }
      if (j >= 1) {
        if (arr[j] == 1 && arr[j - 1] == 1) {
          height += 4;
        }
      }
      if (j >= 1) {
        if (arr[j] == 0 && arr[j - 1] == 0) {
          cout << "-1" << endl;
          a = 1;
          break;
        }
      }
    }
    if (a == 0) {
      cout << height << endl;
    }
  }
  return 0;
}
