#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    bool prev = false;
    for (int i = 0; true; i++) {
      int change = 0;
      if (i & 1) {
        for (int j = 1; j < n - 1; j++) {
          if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
            change++;
          }
          j++;
        }
      } else {
        for (int j = 0; j < n - 2; j++) {
          if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
            change++;
          }
          j++;
        }
      }
      if (!change) {
        if (prev) {
          cout << i - 1 << "\n";
          break;
        }
        prev = true;
      } else {
        prev = false;
      }
    }
  }
}
