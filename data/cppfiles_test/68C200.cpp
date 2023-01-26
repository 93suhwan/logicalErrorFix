#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    long long init = sqrt(k);
    if (init * init < k) init++;
    long long row = init, col = 1;
    long long ans = init * init;
    long long count = 1;
    while (ans > k && col < row) {
      col++;
      ans--;
    }
    if (ans == k) {
      cout << row << " " << col << "\n";
    } else {
      count = 0;
      while (ans > k) {
        row--;
        ans--;
      }
      cout << row << " " << col << "\n";
    }
  }
  return 0;
}
