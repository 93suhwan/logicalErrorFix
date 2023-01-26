#include <bits/stdc++.h>
using namespace std;
void hyuga(int T) {
  int n, m, rb, cb, rd, cd;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  int count = 1e9;
  int a = 1, b = 1;
  if (rb > rd)
    count = min(count, abs(rb - rd) + 2 * (n - rb));
  else
    count = min(count, abs(rb - rd));
  if (cb > cd)
    count = min(count, abs(cb - cd) + 2 * (m - cb));
  else
    count = min(count, abs(cb - cd));
  cout << count << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    hyuga(T);
  }
  return 0;
}
