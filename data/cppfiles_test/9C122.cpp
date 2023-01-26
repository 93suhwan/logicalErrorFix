#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long inf = pow(10, 18);
long long modulo = pow(10, 9) + 7;
void deal() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<set<long long> > all(m);
  vector<vector<long long> > arr(n, vector<long long>(m));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      long long ed;
      cin >> ed;
      arr[i][j] = ed;
      if (ed != 2) {
        all[j].insert(i);
      }
    }
  }
  for (long long i = 0; i < k; i++) {
    long long y;
    cin >> y;
    long long x = -1;
    --y;
    while (1) {
      auto it = all[y].lower_bound(x);
      if (it == all[y].end()) {
        break;
      }
      long long wh = (*it);
      all[y].erase(it);
      x = wh;
      if (arr[x][y] == 1) {
        ++y;
      } else {
        --y;
      }
    }
    cout << y + 1 << " ";
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  deal();
}
