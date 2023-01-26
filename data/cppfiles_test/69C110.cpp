#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  vector<string> all;
  for (long long i = 1; i < 2e18; i *= 2) {
    all.push_back(to_string(i));
  }
  while (t-- > 0) {
    string str;
    cin >> str;
    int ans = str.length() + 1;
    for (auto &x : all) {
      int temp = 0, siz = 0;
      auto j = x.begin();
      for (; j < x.end() && siz < str.length(); siz++) {
        if (str[siz] == (*j)) {
          j++;
        } else {
          ++temp;
        }
      }
      while (siz < str.length()) {
        siz++;
        temp++;
      }
      while (j < x.end()) {
        j++;
        temp++;
      }
      ans = min(ans, temp);
    }
    cout << ans << endl;
  }
  return 0;
}
