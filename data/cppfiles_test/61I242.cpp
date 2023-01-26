#include <bits/stdc++.h>
using namespace std;
long long pw(int x, int y, int z) {
  if (y == 0) return 1 % z;
  long long a = pw(x, y / 2, z);
  if (y % 2 == 0)
    return (a * a) % z;
  else
    return (((a * a) % z) * x % z) % z;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; ++i) cin >> arr[i][0] >> arr[i][1];
    map<int, int> l, r;
    for (int i = 0; i < n; ++i) {
      l[arr[i][0]]++;
      r[arr[i][1]]++;
    }
    sort(arr.begin(), arr.end());
    long long ans = (n * (n - 1) * (n - 2)) / 6;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
      int curl = arr[i][0];
      int nos = l[curl];
      int othel = 0;
      if (nos >= 2) {
        for (int j = i; j < i + nos; ++j) {
          othel += (r[arr[j][1]] - 1);
        }
      }
      ans -= ((nos - 1) * othel);
      i += nos - 1;
    }
    cout << ans << endl;
  }
}
