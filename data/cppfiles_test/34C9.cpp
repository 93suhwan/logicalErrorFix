#include <bits/stdc++.h>
using namespace std;
const int M = 5005, M2 = 8200;
vector<int> opt[M];
int mi[M2];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fill(mi, mi + M2, 5001);
  mi[0] = 0;
  for (int i = 1; i <= 5000; i++) opt[i].push_back(0);
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    for (int u : opt[x]) {
      if (x < mi[u ^ x]) {
        for (int j = x + 1; j <= mi[u ^ x]; j++) opt[j].push_back(u ^ x);
        mi[u ^ x] = x;
      }
    }
    opt[x].clear();
  }
  vector<int> ans;
  for (int i = 0; i < 8192; i++) {
    if (mi[i] <= 5000) ans.push_back(i);
  }
  cout << ans.size() << "\n";
  for (int u : ans) cout << u << " ";
}
