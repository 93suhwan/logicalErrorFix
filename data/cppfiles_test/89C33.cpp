#include <bits/stdc++.h>
using namespace std;
int n, buds;
bool valid;
vector<int> v[200005];
bool calc(int r, int parent) {
  bool turn = 0;
  for (int i : v[r]) {
    if (i == parent) continue;
    turn |= calc(i, r);
  }
  if (r == 1 && turn)
    valid = 1;
  else if (turn)
    buds++;
  return !turn;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i < n; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      v[a].push_back(b);
      v[b].push_back(a);
    }
    calc(1, -1);
    cout << n - 2 * buds - valid << endl;
    valid = 0;
    buds = 0;
    for (int i = 1; i <= n; i++) v[i].clear();
  }
  return 0;
}
