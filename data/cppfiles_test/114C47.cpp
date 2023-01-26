#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int tc, n, m, i, j, k, l, x, y, z, a, b, c, sign, count;
  vector<long long int> vec;
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> x;
      vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    i = vec.size() - 1;
    m = n / 2;
    while (m--) {
      cout << vec[i] << " " << vec[0] << endl;
      i--;
    }
    vec.clear();
  }
  return 0;
}
