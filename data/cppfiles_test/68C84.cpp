#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    int root = sqrt(k);
    long long sq = root * root;
    long long rem = k - sq;
    if (sq == k) {
      cout << root << " " << 1 << endl;
      continue;
    }
    if (rem <= root + 1) {
      cout << rem << " " << root + 1 << endl;
    } else {
      cout << root + 1 << " " << root + root + 2 - rem << endl;
    }
  }
  return 0;
}
