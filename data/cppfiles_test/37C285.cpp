#include <bits/stdc++.h>
using namespace std;
void Saraff() {
  long long n, m;
  cin >> n >> m;
  vector<bool> vis(n + 1, true);
  vis[0] = false;
  for (long long i = 0; i < m; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    vis[b] = false;
  }
  long long index = find((vis).begin(), (vis).end(), true) - vis.begin();
  for (long long i = 1; i < n + 1; i++) {
    if (i == index) continue;
    cout << index << " " << i << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  long long test = 1;
  cin >> test;
  for (long long t = 1; t <= test; t++) {
    Saraff();
  }
}
