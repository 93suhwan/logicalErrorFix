#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    cout << s / ((n + 2) / 2) << endl;
  }
  return 0;
}
