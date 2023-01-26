#include <bits/stdc++.h>
using namespace std;
vector<long long int> func(long long int a, long long int b, long long int c) {
  vector<long long int> ans;
  ans.push_back(a);
  ans.push_back(b);
  ans.push_back(c);
  ans.push_back(a + b);
  ans.push_back(a + c);
  ans.push_back(b + c);
  ans.push_back(a + b + c);
  sort(ans.begin(), ans.end());
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int x24e;
  cin >> x24e;
  for (long long int TC = 1; TC <= x24e; TC++) {
    vector<long long int> arr(7);
    for (long long int i = 0; i < 7; i++) cin >> arr[i];
    vector<long long int> ans;
    bool flag = false;
    for (long long int i = 0; i < 7; i++) {
      for (long long int j = i + 1; j < 7; j++) {
        for (long long int k = j + 1; k < 7; k++) {
          vector<long long int> temp = func(arr[i], arr[j], arr[k]);
          if (arr == temp) {
            ans.clear();
            ans.push_back(arr[i]);
            ans.push_back(arr[j]);
            ans.push_back(arr[k]);
          }
        }
      }
    }
    for (auto u : ans) cout << u << " ";
    cout << "\n";
  }
  return 0;
}
