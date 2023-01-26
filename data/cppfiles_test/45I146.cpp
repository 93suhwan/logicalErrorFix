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
    int val = 1;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
      if (arr[i] == 0 && arr[i - 1] == 0) {
        val = -1;
        break;
      } else if (arr[i] == 0) {
        val = val + 0;
      } else if (arr[i] == 1 && arr[i - 1] == 1) {
        val = val + 5;
      } else {
        val = val + 1;
      }
    }
    cout << val << endl;
  }
  return 0;
}
