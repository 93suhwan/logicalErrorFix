#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int v[10];
    for (int i = 0; i < 7; ++i) cin >> v[i];
    cout << v[0] << " " << v[1] << " " << v[6] - v[0] - v[1] << '\n';
  }
  return 0;
}
