#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, i;
    cin >> n;
    long long arr[n];
    int rem = n;
    int buffer = 0;
    for (i = 0; i < n; i++) cin >> arr[i];
    for (i = n - 1; i > -1; i--) {
      if (arr[i] % (i + 2) == 0)
        buffer++;
      else {
        rem = rem - 1 - buffer;
        buffer = 0;
      }
    }
    if (rem)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
