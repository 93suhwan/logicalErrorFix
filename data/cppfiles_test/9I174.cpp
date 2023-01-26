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
    vector<int> v;
    for (auto i : h) {
      v.push_back(i.second);
    }
    int max = v[0];
    for (int i = 1; i < v.size(); i++) {
      if (v[i] > max) max = v[i];
    }
    int res = s.size() / max;
    if (max == 1) {
      cout << res / 2 << "\n";
    } else if (s.size() % max == 0) {
      cout << res << "\n";
    } else {
      cout << res + 1 << "\n";
    }
  }
}
