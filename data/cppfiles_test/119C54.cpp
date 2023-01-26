#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, ans = 0;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    ans += arr[i];
  }
  cout << ceil(double(ans) / n) - (ans / n) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
