#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int c = 0, c1 = 0;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (arr[i] > arr[j]) {
          swap(arr[i], arr[j]);
          flag = true;
        }
      }
      if (flag == true) c1++;
    }
    if (n > 3 && c1 != 0)
      cout << n - 2 << "\n";
    else
      cout << c1 << "\n";
  }
  return 0;
}
