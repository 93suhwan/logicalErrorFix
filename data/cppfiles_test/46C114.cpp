#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, idx, cnt = 0;
    cin >> n;
    long long arr[n + 5];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    idx = arr[n - 1];
    for (int i = n - 1; i >= 0; i--) {
      if (arr[i] > idx) {
        cnt++;
        idx = arr[i];
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}
