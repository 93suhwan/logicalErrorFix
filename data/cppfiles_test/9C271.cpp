#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string s;
  while (t--) {
    cin >> s;
    unordered_map<int, int> h;
    for (int i = 0; i < s.size(); ++i) {
      h[s[i] - 'a']++;
    }
    int single = 0, more = 0;
    for (auto i : h) {
      if (i.second == 1)
        single++;
      else
        more++;
    }
    int res = more + (single / 2);
    cout << res << "\n";
  }
}
