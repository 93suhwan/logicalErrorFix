#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long arr[7];
  for (int i = 0; i < 7; i++) cin >> arr[i];
  cout << arr[0] << " " << arr[1] << " " << (arr[6] - (arr[0] + arr[1]))
       << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
