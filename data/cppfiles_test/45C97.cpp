#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int flag = 0;
    int count = 1;
    if (arr[0] == 1) count++;
    for (int i = 1; i < n; i++) {
      if (arr[i] == 0 and arr[i - 1] == 0) {
        flag = 1;
        break;
      } else if (arr[i] == 1 and arr[i - 1] == 0)
        count++;
      else if (arr[i] == 1 and arr[i - 1] == 1)
        count += 5;
    }
    if (flag)
      cout << -1 << endl;
    else
      cout << count << endl;
  }
}
