#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<pair<char, int> > v;
    string s;
    cin >> s;
    for (int i = 0; i < 26; i++) {
      v.push_back(make_pair(s[i], i + 1));
    }
    string z;
    cin >> z;
    vector<pair<char, int> >::iterator it;
    int sum = 0;
    int n, m;
    for (int i = 0; i < v.size(); i++) {
      if (z[0] == v[i].first) {
        n = v[i].second;
        break;
      }
    }
    for (int i = 1; i < z.size(); i++) {
      for (int j = 0; j < v.size(); j++) {
        if (v[j].first == z[i]) {
          m = v[j].second;
          sum += abs(m - n);
          n = m;
        }
      }
    }
    cout << sum << endl;
  }
}
