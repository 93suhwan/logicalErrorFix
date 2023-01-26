#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 2e6;
int arr[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> m;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
      int x = arr[i];
      sort(arr + 1, arr + 1 + i);
      int l = 0;
      int r = i + 1;
      while (r - l > 1) {
        int mid = (r + l) / 2;
        if (arr[mid] >= x) {
          r = mid;
        } else {
          l = mid;
        }
      }
      ans += l;
    }
    cout << ans << endl;
  }
}
