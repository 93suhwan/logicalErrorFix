#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int i = 0, j = 0, k = 0;
    for (int y = 1; y < n - 1; y++) {
      for (int x = 0; x < y; x++)
        if (arr[x] < arr[y]) {
          i = x;
          j = y;
          break;
        }
      for (int z = y + 1; z < n; z++)
        if (arr[z] < arr[y]) {
          k = z;
          break;
        }
      if (i < j && j < k) break;
    }
    if (i < j && j < k)
      cout << "YES\n" << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
    else
      cout << "NO\n";
  }
}
