#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n + 1];
    arr[0] = 2;
    long long int val = 1;
    long long int c = 0;
    for (long long int i = 1; i <= n; i++) {
      cin >> arr[i];
      if (arr[i] == 0 && arr[i - 1] == 0) {
        c = 1;
      } else if (arr[i] == 0) {
        val = val + 0;
      } else if (arr[i] == 1 && arr[i - 1] == 1) {
        val = val + 5;
      } else if (arr[i] == 1) {
        val = val + 1;
      }
    }
    if (c == 1) {
      cout << "-1" << endl;
    } else {
      cout << val << endl;
    }
  }
  return 0;
}
