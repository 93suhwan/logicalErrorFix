#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tcase;
  cin >> tcase;
  while (tcase--) {
    long long n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int check = arr[0];
    int index = 0;
    for (int i = 1; i < n; i++) {
      if (arr[i] >= check) {
        check = arr[i];
        index = i;
      }
    }
    long long ans;
    if (index == n - 1)
      ans = arr[index] * arr[index - 1];
    else
      ans = max(arr[index] * arr[index - 1], arr[index] * arr[index + 1]);
    cout << ans << "\n";
  }
}
