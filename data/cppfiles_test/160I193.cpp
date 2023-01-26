#include <bits/stdc++.h>
const long long INF = (1ll) * 1e18;
using namespace std;
void test_case() {
  int n, m;
  cin >> n >> m;
  int rb, rd, cb, cd;
  cin >> rb >> cb >> rd >> cd;
  if (rb <= rd && cb <= cd) {
    cout << min(rd - rb, cd - cb);
  } else if (rb <= rd) {
    cout << (rd - rb);
  } else if (cb <= cd) {
    cout << (cd - cb);
  } else {
    cout << min(rb - rd + 2 * (n - rb), cb - cd + 2 * (m - cb));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  auto start = chrono::high_resolution_clock::now();
  int testno = 1;
  cin >> testno;
  for (int i = 1; i <= testno; i++) {
    test_case();
    cout << '\n';
  }
  auto end = chrono::high_resolution_clock::now();
  double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  time_taken *= 1e-9;
  cerr << fixed << time_taken << setprecision(9) << " sec" << endl;
  return 0;
}
