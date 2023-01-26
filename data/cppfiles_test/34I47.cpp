#include <bits/stdc++.h>
using namespace std;
const int SIZE = 9010;
const int mod = 1e9 + 7;
bool dapei[SIZE][SIZE], yhz[SIZE][SIZE];
vector<long long> ve[SIZE];
long long n, a[SIZE];
void solve() {
  for (int i = 0; i <= 9009; i++) ve[i].push_back(0), yhz[i][0] = true;
  for (int i = 1; i <= n; i++) {
    for (auto it : ve[a[i]]) {
      if (dapei[a[i]][it]) continue;
      for (int j = a[i] + 1; j <= 9000; j++) {
        if (yhz[j][a[i] ^ it]) break;
        ve[j].push_back(a[i] ^ it);
        yhz[j][a[i] ^ it] = true;
      }
      dapei[a[i]][it] = true;
    }
  }
  set<long long> st(ve[9000].begin(), ve[9000].end());
  cout << st.size() << "\n";
  for (auto it : st) cout << it << " ";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  solve();
}
