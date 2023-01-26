#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long arr[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    long long flag = 0;
    for (int i = 1; i <= min(n, (long long)28); i++) {
      long long flag1 = 0;
      for (int j = 1; j <= i; j++) {
        if (arr[i] % (j + 1) != 0) {
          flag1 = 1;
          break;
        }
      }
      if (flag1 == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      cout << "NO"
           << "\n";
    } else {
      cout << "YES"
           << "\n";
    }
  }
}
