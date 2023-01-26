#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<pair<string, int>> allpairs;
  int minlength = n / 2 - 1;
  for (int i = 0; i < n; ++i) {
    string tmp;
    tmp.push_back(s[i]);
    for (int j = i + 1; j < n; ++j) {
      tmp.push_back(s[j]);
      if (tmp.size() >= minlength) {
        allpairs.push_back({tmp, i + 1});
      }
    }
  }
  vector<int> num;
  for (int i = 0; i < allpairs.size(); ++i) {
    int number = 0;
    for (int j = allpairs[i].first.size() - 1; j >= 0; --j) {
      number += (allpairs[i].first[j] - '0') *
                pow(2, allpairs[i].first.size() - 1 - j);
    }
    if (number != 0) {
      num.push_back(number);
    }
  }
  for (int i = 0; i < num.size(); ++i) {
    for (int j = 0; j < num.size(); ++j) {
      if (num[i] % num[j] == 0 and i != j) {
        cout << allpairs[i].second << " "
             << allpairs[i].second + allpairs[i].first.size() << " ";
        cout << allpairs[j].second << " "
             << allpairs[j].second + allpairs[j].first.size();
        cout << "\n";
        return;
      }
    }
  }
}
