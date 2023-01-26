#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    deque<string> v(n);
    map<string, int> mp;
    for (int i = 0; i < n - 2; i++) {
      cin >> v[i];
      mp[v[i]] += 1;
    }
    sort(v.begin(), v.end());
    string ans = "";
    if (mp["aa"] >= 1) {
      ans = "aa";
      int aux = mp["aa"];
      for (int i = 1; i < aux - 1; i++) {
        ans += "a";
      }
    }
    if (mp["ab"] >= mp["ba"]) {
      for (int i = 0; i < mp["ab"]; i++) {
        ans = "ab" + ans;
      }
    } else {
      for (int i = 0; i < mp["ba"]; i++) {
        ans = "ba" + ans;
      }
    }
    string ans2 = "";
    int ix = -1;
    for (int i = 0; i < ans.size(); i++) {
      if (ans[i] == 'b') {
        ans2.push_back('b');
        ix = i + 1;
        break;
      } else {
        ans2.push_back(ans[i]);
      }
    }
    for (int i = 0; i < mp["bb"]; i++) {
      ans2.push_back('b');
    }
    for (int i = ix; i < ans.size(); i++) {
      ans2.push_back(ans[i]);
    }
    int k = n - ans2.size();
    for (int i = 0; i < k; i++) {
      ans2.push_back(ans2[ans2.size() - 1]);
    }
    cout << ans2 << '\n';
  }
  return 0;
}
