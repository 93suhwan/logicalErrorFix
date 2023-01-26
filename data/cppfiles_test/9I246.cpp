#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<char> v{s[0]};
    int sum = 1;
    for (int i = 1; i < s.size(); i++) {
      int vsize = v.size();
      while (vsize) {
        if (v[vsize - 1] == s[i])
          break;
        else
          vsize--;
      }
      if (vsize == 0) sum++;
      v.push_back(s[i]);
    }
    if (sum > s.size() / 2)
      cout << s.size() / 2 << endl;
    else
      cout << sum << endl;
  }
  return 0;
}
