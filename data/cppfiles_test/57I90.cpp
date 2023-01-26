#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    long long n, p, k;
    cin >> n >> p >> k;
    if (k > p)
      cout << "NO\n";
    else if (k == p)
      cout << "YES\n";
    else {
      long long rem = n - k, valid = p - k;
      cout << (valid <= rem ? "YES\n" : "NO\n");
    }
  }
  return 0;
}
