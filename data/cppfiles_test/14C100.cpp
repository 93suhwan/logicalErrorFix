#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> arr(n);
  for (long long int i = 0; i < n; ++i) {
    long long int x;
    cin >> x;
    arr[i] = x;
  }
  vector<vector<long long int> > ans;
  for (long long int i = n - 1; i >= 0; --i) {
    long long int maxi = INT_MIN;
    long long int index;
    for (long long int j = 0; j <= i; ++j) {
      if (arr[j] > maxi) {
        maxi = arr[j];
        index = j;
      }
    }
    if (index != i) {
      vector<long long int> temp(n);
      for (long long int j = 0; j <= i; j++) {
        temp[j] = arr[(j + index + 1) % (i + 1)];
      }
      arr = temp;
      vector<long long int> tempv;
      tempv.push_back(1);
      tempv.push_back(i + 1);
      tempv.push_back(index + 1);
      ans.push_back(tempv);
    }
  }
  cout << ans.size() << endl;
  for (long long int i = 0; i < ans.size(); ++i) {
    vector<long long int> v;
    v = ans[i];
    cout << v[0] << " " << v[1] << " " << v[2] << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int tc;
  cin >> tc;
  while (tc--) solve();
}
