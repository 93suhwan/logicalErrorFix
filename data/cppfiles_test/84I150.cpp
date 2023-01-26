#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test;
  cin >> test;
  while (test--) {
    long long int n, s;
    cin >> n >> s;
    long long int x = (n + 1) / 2;
    if (n % 2 == 0) x++;
    long long int y = (s) / x;
    if (y * x == s && x != n) y = (s - 1) / x;
    cout << y << endl;
  }
  return 0;
}
