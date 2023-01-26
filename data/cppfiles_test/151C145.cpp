#include <bits/stdc++.h>
using namespace std;
int par[(int)5e5 + 10];
void burn() {
  int q;
  cin >> q;
  vector<vector<int>> ques(q);
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
      ans.push_back(par[ques[i][0]]);
    } else {
      par[ques[i][0]] = par[ques[i][1]];
    }
  }
  reverse(ans.begin(), ans.end());
  for (auto &i : ans) cout << i << ' ';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  for (int i = 0; i < 5e5 + 10; i++) par[i] = i;
  int t = 1;
  while (t--) {
    burn();
    cout << '\n';
  }
  return 0;
}
