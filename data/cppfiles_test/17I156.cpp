#include <bits/stdc++.h>
using namespace std;
const long long int M = 10000000007;
long long int binarySearch(vector<long long int> arr, long long int l,
                           long long int r, long long int x) {
  if (r >= l) {
    long long int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long int tt, n, i, j, k, ans, cnt, flag;
  cin >> tt;
  while (tt--) {
    cin >> n;
    vector<vector<long long int> > v(n, (vector<long long int>(5)));
    for (i = 0; i < n; i++) {
      for (j = 0; j < 5; j++) {
        cin >> v[i][j];
      }
    }
    if (n == 1) {
      cout << 1 << "\n";
      continue;
    }
    vector<long long int> ranks(5, 50000);
    ans = -1;
    for (i = 0; i < n; i++) {
      cnt = 0;
      for (j = 0; j < 5; j++)
        if (v[i][j] < ranks[j]) cnt++;
      if (cnt < 3) continue;
      flag = 0;
      for (j = 0; j < n; j++) {
        if (i == j) continue;
        cnt = 0;
        for (k = 0; k < 5; k++) {
          if (v[i][k] < v[j][k]) cnt++;
        }
        if (cnt < 3) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        ans = i + 1;
        break;
      } else {
        for (j = 0; j < 5; j++) ranks[j] = min(ranks[j], v[i][j]);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
