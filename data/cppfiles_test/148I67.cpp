#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
const int MAX_L = 20;
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
void solve() {
  long long x, y;
  cin >> x >> y;
  long long k;
  cin >> k;
  vector<long long> x1(k);
  for (int i = 0; i < k; i++) {
    cin >> x1[i];
  }
  cin >> k;
  vector<long long> x2(k);
  for (int i = 0; i < k; i++) {
    cin >> x2[i];
  }
  cin >> k;
  vector<long long> y1(k);
  for (int i = 0; i < k; i++) {
    cin >> y1[i];
  }
  cin >> k;
  vector<long long> y2(k);
  for (int i = 0; i < k; i++) {
    cin >> y2[i];
  }
  int maxax = max(x1[x1.size() - 1] - x1[0], x2[x2.size() - 1] - x2[0]);
  int maxay = max(y1[y1.size() - 1] - y1[0], y2[y2.size() - 1] - y2[0]);
  cout << maxax << " " << maxay << " ";
  cout << max(maxay * x, maxax * y) << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
