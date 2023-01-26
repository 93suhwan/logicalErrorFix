#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4.1")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long i, j;
  int q;
  cin >> q;
  vector<int> store(q);
  vector<int> n1(q), n2(q, 0);
  for (i = 0; i < q; i++) {
    cin >> store[i] >> n1[i];
    if (store[i] == 2) {
      cin >> n2[i];
    }
  }
  vector<int> ans;
  vector<int> index(500025);
  iota(index.begin(), index.end(), 0);
  for (i = q - 1; i >= 0; i--) {
    if (store[i] == 1) {
      ans.push_back(index[n1[i]]);
    } else {
      index[n1[i]] = index[n2[i]];
    }
  }
  for (i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
