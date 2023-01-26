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
    cout << s / (n / 2 + 1) << endl;
  }
  return 0;
}
