#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> pos[n + 1];
    int totColorable = 0;
    for (int i = 1; i <= n; i++) {
      int num;
      cin >> num;
      pos[num].push_back(i);
      if (pos[num].size() <= k) totColorable++;
    }
    vector<int> ans(n + 1, 0);
    int totColored = k == 0 ? 0 : k * (totColorable / k);
    int colNum = 1;
    int i = 0, ptr = 1;
    while (i < totColored) {
      int size = pos[ptr].size();
      for (int j = 0; j < min(k, size) && i < totColored; j++) {
        ans[pos[ptr][j]] = colNum;
        colNum++;
        colNum %= (k + 1);
        colNum += colNum == 0 ? 1 : 0;
        i++;
      }
      ptr++;
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
}
