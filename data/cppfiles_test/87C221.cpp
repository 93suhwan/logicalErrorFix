#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int a[n], sum = 0, fg = 0, cnt = 0, ind = 1, ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
      if (a[i] <= ind) {
        ind++;
        continue;
      }
      ans = ans + a[i] - ind;
      ind = a[i] + 1;
    }
    cout << ans;
    cout << '\n';
  }
  return 0;
}
