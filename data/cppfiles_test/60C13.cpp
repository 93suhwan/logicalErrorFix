#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[30];
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    long int arr[m + 1], ans = 1000000009, bg = 0;
    for (int i = 0; i < m; i++) {
      cin >> arr[i];
      if (arr[i] < ans) ans = arr[i];
    }
    for (int i = 0; i < m; i++) {
      long k = ans & arr[i];
      if (k < ans) ans = ans & arr[i];
    }
    cout << ans << "\n";
  }
}
