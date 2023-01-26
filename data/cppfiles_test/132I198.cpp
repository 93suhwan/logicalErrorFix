#include <bits/stdc++.h>
using namespace std;
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int arr[7];
    for (int i = 0; i < 7; i++) {
      cin >> arr[i];
    }
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
