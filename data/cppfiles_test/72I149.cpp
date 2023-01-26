#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    string S, ans = "";
    int K, N;
    cin >> S >> K;
    N = S.size();
    bool bigger = 0;
    set<char> udh;
    vector<pair<char, int>> take;
    while (!bigger && ans.size() < N) {
      char i = S[ans.size()], idx = ans.size();
      if (!udh.count(i)) {
        if (udh.size() == K) {
          auto it = udh.upper_bound(i);
          if (it == udh.end()) {
            ans = ans.substr(0, take.back().second);
            ans.push_back(take.back().first + 1);
            udh.erase(take.back().first);
            udh.insert(ans.back());
            take.back().first = ans.back();
          } else {
            ans.push_back(*it);
          }
          bigger = 1;
        } else {
          ans.push_back(i);
          udh.insert(i);
          take.push_back({i, idx});
        }
      } else {
        ans.push_back(i);
      }
    }
    while (ans.size() < N) {
      auto it = udh.lower_bound('0');
      ans = ans + (*it);
    }
    cout << ans << '\n';
  }
}
