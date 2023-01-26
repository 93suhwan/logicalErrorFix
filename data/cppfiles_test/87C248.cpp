#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    long long int arr[m + 3];
    for (int i = 0; i < m; i++) {
      cin >> arr[i];
    }
    vector<long long int> v;
    v.push_back(arr[0]);
    long long int res = 0;
    for (int i = 0; i < m; i++) {
      long long int cnt = 0;
      if (i == 0) {
        continue;
      }
      for (int j = 0; j < v.size(); j++) {
        if (v[j] < arr[i]) {
          cnt++;
        }
      }
      v.push_back(arr[i]);
      res += cnt;
    }
    cout << res << endl;
  }
  return 0;
}
