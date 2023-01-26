#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846;
const long long mod = 1000000007;
void solve() {
  int n;
  cin >> n;
  vector<long long> vtr(n + 1);
  for (int i = 1; i <= n; i++) cin >> vtr[i];
  sort(vtr.begin() + 1, vtr.end());
  int flag = 1, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (vtr[i] != i) {
      if (vtr[i] < i) {
        flag = 0;
        break;
      } else {
        if (vtr[i] % 2 == 0) {
          if (vtr[i] / 2 - 1 >= i)
            cnt++;
          else {
            flag = 0;
            break;
          }
        } else {
          if (vtr[i] / 2 >= i)
            cnt++;
          else {
            flag = 0;
            break;
          }
        }
      }
    }
  }
  if (flag == 0)
    cout << -1 << endl;
  else
    cout << cnt << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
