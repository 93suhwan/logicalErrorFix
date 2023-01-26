#include <bits/stdc++.h>
using namespace std;
signed main() {
  cin.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, s;
    cin >> n >> s;
    long long half = n / 2;
    half++;
    cout << s / half << endl;
  }
  return 0;
}
