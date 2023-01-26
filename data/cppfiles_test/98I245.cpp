#include <bits/stdc++.h>
using namespace std;
void _solve(int32_t tc) {
  int32_t N;
  cin >> N;
  string S;
  cin >> S;
  map<int32_t, int32_t> mp;
  int32_t curr = 0;
  pair<int32_t, int32_t> ans = {-1, -1};
  mp[0] = 0;
  for (int32_t i = 0; i < N; i++) {
    if (S[i] == 'a') {
      curr++;
      if (mp[curr]) {
        ans.first = mp[curr] + 1;
        ans.second = i + 1;
        break;
      }
      mp[curr] = i + 1;
    } else {
      curr--;
      if (mp[curr]) {
        ans.first = mp[curr] + 1;
        ans.second = i + 1;
        break;
      }
      mp[curr] = i + 1;
    }
  }
  cout << ans.first << " " << ans.second << "\n";
}
int32_t main() {
  int64_t tc = 1;
  std::cin >> tc;
  for (int32_t testcase = 1; testcase <= tc; testcase++) {
    _solve(testcase);
  }
  return 0;
}
