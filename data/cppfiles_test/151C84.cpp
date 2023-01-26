#include <bits/stdc++.h>
using namespace std;
void burn() {
  int q;
  cin >> q;
  vector<vector<int>> ques(q);
  map<int, int> init;
  for (int i = 5e5; i; i--) init[i] = i;
  vector<int> ans;
  for (int i = 0; i < q; i++) {
    int in;
    cin >> in;
    if (in == 1) {
      int x;
      cin >> x;
      ques[i] = {x, 1};
    } else {
      int x, y;
      cin >> x >> y;
      ques[i] = {x, y, 2};
    }
  }
  for (int i = q - 1; ~i; i--) {
    if (ques[i].back() == 1) {
      ans.push_back(init[ques[i][0]]);
    } else {
      init[ques[i][0]] = init[ques[i][1]];
    }
  }
  for (int i = ans.size() - 1; ~i; i--) cout << ans[i] << ' ';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    burn();
    cout << '\n';
  }
  return 0;
}
