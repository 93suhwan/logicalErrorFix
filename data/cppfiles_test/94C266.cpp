#include <bits/stdc++.h>
using namespace std;
int find(vector<int> b, int i, int j, vector<vector<int>> dp, int x, int k) {
  if (i > j) return 0;
  if (i == j) return b[i];
  if (k != 0 and j - i >= 1) {
    int p = b[i] + find(b, i + 1, j, dp, x, k);
    int q = b[j] + find(b, i, j - 1, dp, x, k);
    int m = x + find(b, i + 1, j - 1, dp, x, k - 1);
    return min({p, q, m});
  } else {
    return min(b[i] + find(b, i + 1, j, dp, x, k),
               b[j] + find(b, i, j - 1, dp, x, k));
  }
}
long long run(string n, map<string, int> v) {
  string first = "";
  string second = "";
  for (int i = 0; i < n.size(); i++) {
    if (i % 2 == 0)
      first += n[i];
    else
      second += n[i];
  }
  return (stoi(first) + 1) * (stoi(second) + 1) - 2;
}
void solve() {
  string n;
  cin >> n;
  map<string, int> k;
  if (n.size() == 1) {
    cout << stoi(n) - 1 << endl;
  } else if (n.size() == 2) {
    cout << (((int)(n[1]) - (int)('0') + 1) * ((int)(n[0]) - (int)('0') + 1) -
             2)
         << endl;
  } else {
    cout << run(n, k) << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int k;
  cin >> k;
  while (k--) {
    solve();
  }
}
