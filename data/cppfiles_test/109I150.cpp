#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  cin >> s;
  map<char, int> mp;
  for (int i = 0; i < s.length(); i++) {
    mp[s[i]] = i;
  }
  int n;
  cin >> n;
  vector<string> a;
  while (n--) {
    string x;
    cin >> x;
    a.push_back(x);
  }
  for (int i = 0; i < a.size() - 1; i++) {
    for (int j = 0; j < a.size() - i - 1; j++) {
      if (a[j].size() > a[j + 1].size()) {
        swap(a[i], a[j]);
      } else if (a[j].size() == a[j + 1].size()) {
        for (int k = 0; k < a[i].length(); k++) {
          if (mp[a[j][k]] > mp[a[j + 1][k]]) {
            swap(a[j], a[j + 1]);
          }
        }
      }
    }
  }
  for (auto i : a) {
    cout << i << endl;
  }
  return 0;
}
