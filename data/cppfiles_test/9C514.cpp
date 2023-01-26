#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    vector<int> vec(26);
    string s;
    cin >> s;
    for (int sz = s.size(), i = 0; i < sz; i++) {
      vec[s[i] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      ans += (vec[i] > 0);
      ans += (vec[i] > 1);
    }
    cout << min(ans / 2, (int)s.size() / 2) << endl;
  }
  return 0;
}
