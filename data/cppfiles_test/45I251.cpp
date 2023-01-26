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
    for (int k = 0; k < m; k++) {
      if (arr[k] == 1 && arr[k - 1] == 0 && k != 0) {
        p = p + 1;
      } else if (arr[k - 1] == 0 && arr[k] == 0 && k != 0) {
        p = -1;
        cout << p << endl;
      } else if (arr[k - 1] == 1 && arr[k] == 1 && k != 0) {
        p = p + 5;
      }
    }
    cout << p << endl;
  }
  return 0;
}
