#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,avx,avx2,fma,mmx,tune=native")
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    bool sorted = true;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (int i = 1;; i++) {
      bool sorted = true;
      for (int j = 0; j < n - 1; j++) {
        if (arr[j] != j + 1) sorted = false;
        if ((i + 1) % 2 != j % 2) continue;
        if (arr[j] > arr[j + 1]) {
          arr[j + 1] += arr[j];
          arr[j] = arr[j + 1] - arr[j];
          arr[j + 1] -= arr[j];
        }
      }
      if (sorted) {
        cout << i - 1 << "\n";
        break;
      }
    }
  }
}
