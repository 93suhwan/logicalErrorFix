#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    vector<int> balance[5];
    for (int i = 0; i < n; i++) {
      int x = -v[i].size();
      for (int j = 0; j < 5; j++) {
        balance[j].push_back(-v[i].size());
      }
      for (auto ch : v[i]) {
        balance[ch - 'a'].back() += 2;
      }
    }
    int maxi = 0;
    char bestletter = '\n';
    for (int i = 0; i < 5; i++) {
      auto b = balance[i];
      sort(begin(b), end(b));
      reverse(begin(b), end(b));
      if (b[0] <= 0) {
        continue;
      }
      int sumBalance = b[0];
      int j = 1;
      for (j; sumBalance > 0 && j < n; j++) {
        sumBalance += b[j];
      }
      if (sumBalance <= 0) {
        j--;
      }
      if (j > maxi) {
        maxi = j;
        bestletter = i;
      }
    }
    cout << maxi << "\n";
  }
  return 0;
}
