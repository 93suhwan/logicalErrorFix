#include <bits/stdc++.h>
using namespace std;
const int dx4[4] = {0, 1, 0, -1};
const int dy4[4] = {1, 0, -1, 0};
const int dx8[8] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dy8[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long int n, s;
    cin >> n >> s;
    long long int m = n / 2 + n % 2 + (n % 2 == 0);
    cout << s / m << "\n";
  }
  return 0;
}
