#include <bits/stdc++.h>
using namespace std;
long solve(vector<int> arr, int m) {
  vector<int> vec;
  for (int i = 0; i < m; i++) vec.push_back(arr[i]);
  sort(vec.begin(), vec.end());
  vector<bool> hash(m, 0);
  long total_ans = 0;
  for (int i = 0; i < m; i++) {
    int x = upper_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
    int cnt = 0;
    int j = 0;
    while (j < (x - 1)) {
      if (hash[j] == 1) cnt++;
      j++;
    }
    hash[x - 1] = 1;
    total_ans += cnt;
  }
  return total_ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> arr;
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      arr.push_back(x);
    }
    long ans = solve(arr, m);
    cout << ans << endl;
  }
  return 0;
}
