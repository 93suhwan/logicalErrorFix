#include <bits/stdc++.h>
using namespace std;
int n;
int k;
long long arr[1005];
void answer() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  long long ans = 0;
  for (int i = 0; i < n - 2 * k; i++) ans += arr[i];
  for (int i = n - 2 * k; i + k < n; i++) {
    ans += arr[i] / arr[i + k];
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    answer();
  }
  return 0;
}
