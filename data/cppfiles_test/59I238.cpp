#include <bits/stdc++.h>
const double pi = acos(-1.0);
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  int n, ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0, ans = 0;
  cin >> n;
  int a[n + 2][10];
  int arr[10] = {};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) arr[j]++;
    }
  }
  if (arr[0] >= n / 2) {
    ans++;
    ans1++;
  }
  if (arr[1] >= n / 2) {
    ans++;
    ans2++;
  }
  if (arr[2] >= n / 2) {
    ans++;
    ans3++;
  }
  if (arr[3] >= n / 2) {
    ans++;
    ans4++;
  }
  if (arr[4] >= n / 2) {
    ans++;
    ans5++;
  }
  if (ans > 2) {
    cout << "YES"
         << "\n";
    return;
  }
  if (ans == 2 &&
      (ans1 != 2 && ans2 != 2 && ans3 != 2 && ans4 != 2 && ans5 != 2)) {
    cout << "YES"
         << "\n";
    return;
  }
  cout << "NO"
       << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
