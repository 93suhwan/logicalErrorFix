#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    string s;
    vector<int> v(26);
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
      v[int(s[i] - 'a')]++;
    }
    int n_reds = 0;
    bool have_extra = false;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] >= 2) {
        n_reds++;
      }
      if (v[i] == 1) {
        if (!have_extra) {
          have_extra = true;
        } else {
          have_extra = false;
          n_reds++;
        }
      }
    }
    cout << n_reds << endl;
  }
}
