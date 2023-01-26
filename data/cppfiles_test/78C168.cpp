#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 1, 0, 0, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0, 0, 0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    if (r < 2 * l) {
      cout << r - l << endl;
    } else {
      r--;
      long long x = r / 2 - l;
      cout << l + x << endl;
    }
  }
  return 0;
}
