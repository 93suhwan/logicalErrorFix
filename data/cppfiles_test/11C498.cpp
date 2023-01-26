#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt[n][6];
    memset(cnt, 0, sizeof cnt);
    ;
    for (long long i = (0); i < (n); i++) {
      string s;
      cin >> s;
      for (auto c : s) cnt[i][c - 'a']++;
      cnt[i][5] = s.size();
    }
    long long ans = 0;
    for (long long cha = (0); cha < (5); cha++) {
      vector<long long> arr;
      for (long long i = (0); i < (n); i++)
        arr.push_back(2 * cnt[i][cha] - cnt[i][5]);
      sort(arr.begin(), arr.end());
      reverse(arr.begin(), arr.end());
      long long store = 0;
      long long subans = 0;
      if (arr[0] <= 0) continue;
      for (long long i = (0); i < (n); i++) {
        store += arr[i];
        if (store <= 0) break;
        subans++;
      }
      ans = max(ans, subans);
    }
    cout << ans << "\n";
  }
  return 0;
}
