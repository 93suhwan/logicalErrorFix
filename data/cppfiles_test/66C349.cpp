#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  long long i, n, m = 0;
  vector<long long> v;
  for (i = 1; m < 1005; i++) {
    if (i % 3 == 0 || i % 10 == 3) continue;
    m++;
    v.push_back(i);
  }
  while (t--) {
    cin >> n;
    cout << v[n - 1] << '\n';
  }
  return 0;
}
