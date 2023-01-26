#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int test = 1;
  cin >> test;
  while (test--) {
    long long int n;
    cin >> n;
    if (n & 1) n++;
    long long int ans = (n * 5) / 2;
    if (n < 6) ans = 15;
    cout << ans;
    cout << "\n";
  }
  return 0;
}
