#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int m;
  int p = 1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> m;
    int arr[m];
    for (int j = 0; j < m; j++) {
      cin >> arr[j];
    }
    if (arr[0] == 1) {
      p = p + 1;
    }
    for (int k = 1; k < m; k++) {
      if (k != 0 && arr[k] == 1 && arr[k - 1] == 0) {
        p = p + 1;
      } else if (arr[k - 1] == 0 && arr[k] == 0 && k != 0) {
        p = -1;
        break;
      } else if (arr[k - 1] == 1 && arr[k] == 1) {
        p = p + 5;
      }
    }
    cout << p << endl;
    p = 1;
  }
  return 0;
}
