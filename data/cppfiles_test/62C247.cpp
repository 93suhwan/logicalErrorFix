#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  if (arr[1] == 1) {
    cout << n + 1 << " ";
    for (int i = 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << '\n';
    return;
  } else {
    for (int i = 1; i < n; i++) {
      if (!arr[i] && arr[i + 1]) {
        for (int j = 1; j <= i; j++) {
          cout << j << " ";
        }
        cout << n + 1 << " ";
        for (int j = i + 1; j <= n; j++) {
          cout << j << " ";
        }
        cout << '\n';
        return;
      }
    }
  }
  for (int i = 1; i <= n + 1; i++) {
    cout << i << " ";
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
