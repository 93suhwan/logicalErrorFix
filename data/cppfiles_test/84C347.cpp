#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int temp = ceil(n / 2.0);
    if (n % 2 == 0) temp++;
    cout << (k / temp) << endl;
  }
}
