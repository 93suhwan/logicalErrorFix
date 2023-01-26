#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n - 2; i++) {
      string str;
      cin >> str;
      v.push_back(str);
    }
    string ans = v[0];
    for (int i = 1; i < n - 2; i++) {
      string s1 = v[i];
      int sizeofans = ans.size();
      if (s1[0] == ans[sizeofans - 1]) {
        ans += s1[1];
      } else {
        ans += s1;
      }
    }
    int k = n - ans.size();
    while (k--) {
      ans += 'a';
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
