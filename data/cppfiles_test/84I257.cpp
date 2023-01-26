#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    float n, s;
    cin >> n >> s;
    int m = ceil(n / 2);
    int sol = n - m + 1;
    sol = s / sol;
    cout << sol << endl;
  }
}
