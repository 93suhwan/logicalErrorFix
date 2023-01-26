#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, n, s;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    cin >> n >> s;
    if (s < n)
      cout << 0 << endl;
    else {
      if (n == 1)
        cout << (s - 1) / (n / 2 + 1) + 1 << endl;
      else
        cout << (s - 1) / (n / 2 + 1) << endl;
    }
  }
  return 0;
}
