#include <bits/stdc++.h>
using namespace std;
long long kq[200005];
map<long long, vector<long long>> pos;
void solve() {
  memset(kq, 0, sizeof(kq));
  pos.clear();
  long long n, k, a;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> a;
    if (pos[a].size() < k) pos[a].push_back(i);
  }
  long long d = 0;
  for (long long val = 1; val <= n; val++) d += pos[val].size();
  d -= d % k;
  long long color = 0;
  for (auto t : pos) {
    for (auto i : t.second) {
      kq[i] = color % k + 1;
      d--;
      color++;
      if (!d) goto output;
    }
  }
output:
  for (long long i = 1; i <= n; i++) cout << kq[i] << " ";
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
