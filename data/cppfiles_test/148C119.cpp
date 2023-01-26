#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long w, h;
  cin >> w >> h;
  long long c = 0, c1 = 0, c2 = 0, c3 = 0;
  int k1;
  long long t1 = 0, t2 = 0;
  int i;
  cin >> k1;
  int a1[k1];
  for (long long i = 0; i < k1; i++) {
    cin >> a1[i];
  }
  int k2;
  cin >> k2;
  int a2[k2];
  for (long long i = 0; i < k2; i++) {
    cin >> a2[i];
  }
  c = a1[k1 - 1] - a1[0];
  c1 = a2[k2 - 1] - a2[0];
  c3 = max(c, c1);
  t1 = c3 * h;
  int k3;
  cin >> k3;
  int a3[k3];
  for (long long i = 0; i < k3; i++) {
    cin >> a3[i];
  }
  int k4;
  cin >> k4;
  int a4[k4];
  for (long long i = 0; i < k4; i++) {
    cin >> a4[i];
  }
  c = a3[k3 - 1] - a3[0];
  c1 = a4[k4 - 1] - a4[0];
  c3 = max(c, c1);
  t2 = c3 * w;
  cout << max(t1, t2) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
