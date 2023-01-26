#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n, q;
  cin >> n >> q;
  vector<int> counts(n + 1, 0);
  vector<int> invalid(n + 1, 0);
  queue<int> line;
  int sumcount = 0;
  vector<int> ans;
  while (q--) {
    int type, op;
    cin >> type >> op;
    if (type == 1) {
      line.push(op);
      counts[op]++;
      sumcount++;
    } else if (type == 2) {
      invalid[op] += counts[op];
      sumcount -= counts[op];
      counts[op] = 0;
    } else {
      int counter = 0;
      while (counter < op && !line.empty()) {
        int val = line.front();
        line.pop();
        if (invalid[val]) {
          invalid[val]--;
        } else {
          counter++;
          counts[val]--;
          sumcount--;
        }
      }
    }
    ans.push_back(sumcount);
  }
  for (int i : ans) cout << i << endl;
  return 0;
}
