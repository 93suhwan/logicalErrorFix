#include <bits/stdc++.h>
using namespace std;
void solve() {
  vector<int> arr(3);
  int m;
  cin >> arr[0] >> arr[1] >> arr[2];
  cin >> m;
  sort(arr.begin(), arr.end());
  int minCan = max(0, arr[2] - (arr[0] + arr[1] + 1));
  int c1 = max(0, arr[0] - 1);
  int c2 = max(0, arr[1] - 1);
  int c3 = max(0, arr[2] - 1);
  int mxCan = c1 + c2 + c3;
  if (m >= minCan && m <= mxCan) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int main(int argc, char const *argv[]) {
  init();
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
