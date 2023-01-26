#include <bits/stdc++.h>
using namespace std;
void solve(long long int caseno) {
  long long int i, j, n, o = 0;
  cin >> n;
  vector<long long int> arr(n);
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (arr[0] == 1) {
    cout << n + 1 << ' ';
    for (i = 1; i <= n; i++) cout << i << ' ';
    cout << '\n';
  } else if (arr[n - 1] == 0) {
    for (i = 1; i <= n; i++) cout << i << ' ';
    cout << n + 1 << '\n';
  } else {
    bool unvi = true;
    for (i = 0; i < n - 1; i++) {
      cout << i + 1 << ' ';
      if (unvi && arr[i] == 0 && arr[i + 1] == 1) {
        cout << n + 1 << ' ';
        unvi = false;
      }
    }
    cout << n << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
