#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
void solve() {
  long long n, m, i, j;
  cin >> n;
  vector<string> arr(n);
  for (i = 0; i < n; i++) cin >> arr[i];
  long long ans = 0;
  for (i = 0; i < 5; i++) {
    long long tempans = 0;
    char ch = 'a' + i;
    vector<long long> temp;
    for (auto x : arr) {
      long long diff = 0;
      for (auto y : x) {
        diff += (y == ch ? 1 : -1);
      }
      temp.push_back(diff);
    }
    sort(temp.begin(), temp.end(), greater<long long>());
    long long cnt = 0;
    for (j = 0; j < n; j++) {
      cnt += temp[j];
      if (cnt > 0) tempans = j + 1;
    }
    ans = max(ans, tempans);
  }
  cout << ans << endl;
}
int main() {
  ;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
