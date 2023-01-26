#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int q;
  cin >> q;
  const int N = 500000;
  vector<int> rel(N + 1);
  for (int i = 1; i <= N; i++) {
    rel[i] = i;
  }
  vector<int> arr[q + 1];
  for (int i = 1; i <= q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      cin >> x;
      arr[i].push_back(1);
      arr[i].push_back(x);
    } else {
      int x, y;
      cin >> x >> y;
      arr[i].push_back(2);
      arr[i].push_back(x);
      arr[i].push_back(y);
    }
  }
  vector<int> ans;
  for (int i = q; i >= 1; i--) {
    if (arr[i][0] == 1) {
      ans.push_back(rel[arr[i][1]]);
    } else {
      rel[arr[i][1]] = rel[arr[i][2]];
    }
  }
  reverse(ans.begin(), ans.end());
  for (int nums : ans) cout << nums << " ";
  return 0;
}
