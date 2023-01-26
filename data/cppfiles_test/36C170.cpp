#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  for (int T = 1; T <= t; T++) {
    int n;
    cin >> n;
    int arr[n], sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }
    int ans = 0;
    for (int i = 2; i * i <= sum; i++) {
      if (sum % i == 0) {
        ans = 1;
        break;
      }
    }
    if (ans) {
      cout << n << "\n";
      for (int i = 0; i < n; i++) cout << i + 1 << " ";
      cout << "\n";
    } else {
      int pos = -1;
      for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
          pos = i;
          break;
        }
      }
      cout << n - 1 << "\n";
      for (int i = 0; i < n; i++)
        if (i != pos) cout << i + 1 << " ";
      cout << "\n";
    }
  }
}
