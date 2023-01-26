#include <bits/stdc++.h>
using namespace std;
using namespace std;
vector<int> b[5];
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < 5; i++) b[i].clear();
    for (int i = 1; i <= n; i++) {
      cin >> s;
      int len = -int(s.size());
      for (int j = 0; j < 5; j++) b[j].push_back(len);
      for (auto c : s) {
        b[c - 'a'].back() += 2;
      }
    }
    int bestBalance = 0;
    int bestCount = 0;
    for (int i = 0; i < 5; i++) {
      auto& t = b[i];
      sort(t.begin(), t.end());
      reverse(t.begin(), t.end());
      int temp = t[0];
      int j;
      for (j = 1; j < n && temp > 0; j++) {
        temp += t[j];
      }
      if (temp <= 0) j--;
      if (j > bestCount) {
        bestCount = j;
      }
    }
    cout << bestCount << endl;
  }
  return 0;
}
