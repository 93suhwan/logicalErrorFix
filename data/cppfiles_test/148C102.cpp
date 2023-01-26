#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int MM = 998244353;
int _atharva_() {
  long long w;
  cin >> w;
  ;
  long long h;
  cin >> h;
  ;
  long long k;
  cin >> k;
  ;
  vector<long long> x1(k);
  for (int i = 0; i < k; i++) {
    cin >> x1[i];
  };
  long long t1 = x1[k - 1] - x1[0];
  cin >> k;
  vector<long long> x2(k);
  for (int i = 0; i < k; i++) {
    cin >> x2[i];
  };
  long long t2 = x2[k - 1] - x2[0];
  cin >> k;
  vector<long long> y1(k);
  for (int i = 0; i < k; i++) {
    cin >> y1[i];
  };
  long long t3 = y1[k - 1] - y1[0];
  cin >> k;
  vector<long long> y2(k);
  for (int i = 0; i < k; i++) {
    cin >> y2[i];
  };
  long long t4 = y2[k - 1] - y2[0];
  long long ans1 = max(t1 * h, t2 * h);
  long long ans2 = max(t3 * w, t4 * w);
  long long ans = max(ans1, ans2);
  cout << ans << "\n";
  ;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  cin >> TESTS;
  while (TESTS--) _atharva_();
  cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms"
       << '\n';
  return 0;
}
