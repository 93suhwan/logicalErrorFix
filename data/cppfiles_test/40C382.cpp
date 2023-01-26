#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int ar[n + 4], br[n + 4];
    for (int i = 0; i < n; i++) cin >> ar[i];
    for (int j = 0; j < n; j++) cin >> br[j];
    long long int pre1[n + 4], pre2[n + 3];
    pre1[0] = ar[0];
    for (int i = 1; i < n; i++) pre1[i] = pre1[i - 1] + ar[i];
    pre2[0] = br[0];
    for (int i = 1; i < n; i++) pre2[i] = pre2[i - 1] + br[i];
    pre1[n] = pre1[n - 1];
    long long int ans = pre1[n - 1] - pre1[0];
    for (int i = 1; i < n; i++) {
      long long int a = pre2[i - 1];
      long long int b = pre1[n - 1] - pre1[i];
      ans = min(ans, max(a, b));
    }
    cout << ans << endl;
  }
}
