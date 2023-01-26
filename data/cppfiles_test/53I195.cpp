#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int cnt = 0;
    if (n == 1)
      cout << "YES" << endl;
    else {
      for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) cnt++;
      }
      if (k > cnt)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
  return 0;
}
