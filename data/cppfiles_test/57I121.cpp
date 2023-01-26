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
    long long s, n, k;
    cin >> s >> n >> k;
    if (k > n)
      cout << "NO\n";
    else {
      long long rem = s - n;
      long long invalid = (n / k) * k;
      cout << (rem < invalid ? "YES\n" : "NO\n");
    }
  }
  return 0;
}
