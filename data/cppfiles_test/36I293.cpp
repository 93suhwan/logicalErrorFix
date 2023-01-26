#include <bits/stdc++.h>
using namespace std;
int a[] = {2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,
           41,  43,  47,  73,  79,  83,  89,  97,  101, 103, 107, 109,
           113, 127, 131, 137, 139, 149, 179, 181, 191, 193, 197, 199};
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int arr[n];
    int sum = 0;
    int j = 0, k = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum = sum + arr[i];
      if (arr[i] % 2 != 0) {
        j = arr[i], k = i;
      }
    }
    int m = sizeof(a) / sizeof(int);
    if (binary_search(a, a + m, sum)) {
      cout << n - 1 << endl;
      for (int i = 0; i < n; i++) {
        if (i == k)
          continue;
        else
          cout << i + 1 << " ";
      }
      cout << endl;
    } else {
      cout << n << endl;
      for (int i = 0; i < n; i++) {
        cout << i + 1 << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
