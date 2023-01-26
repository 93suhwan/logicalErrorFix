#include <bits/stdc++.h>
using namespace std;
long long kq[200005];
map<long long, vector<long long>> pos;
void solve() {
  pos.clear();
  memset(kq, 0, sizeof(kq));
  long long n, k, a;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> a;
    if (pos[a].size() < k) pos[a].push_back(i);
  }
  long long d = 0;
  for (auto t : pos) d += pos.size();
  d -= d % k;
  long long color = 0;
  for (auto t : pos) {
    for (auto i : t.second) {
      color = (color + 1) % k;
      kq[i] = color;
      d--;
      if (!d) goto ahihi;
    }
  }
ahihi:
  for (long long i = 0; i < n; i++) cout << kq[i] << " ";
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
