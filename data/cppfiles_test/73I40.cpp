#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  for (cin >> t; t--;) {
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int i = 1;
    bool a = false, b = false;
    bool A = false, B = false;
    while (true) {
      if (a && b) break;
      if (i % 2) {
        bool x = false;
        for (int j = 1; j < n; j += 2) {
          if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]), x = true;
        }
        if (!x)
          a = true;
        else
          b = false;
        if (i == 1 && !x) A = true;
        i++;
      } else {
        bool x = false;
        for (int j = 2; j < n; j += 2) {
          if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]), x = true;
        }
        if (!x)
          b = true;
        else
          a = false;
        if (i == 2 && !x) B = true;
        i++;
      }
    }
    if (A && B)
      cout << "0"
           << "\n";
    else if (B)
      cout << "2\n";
    else
      cout << i - 3 << "\n";
  }
  return 0;
}
