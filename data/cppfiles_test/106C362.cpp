#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  int a, u;
  long long ans;
  cin >> a;
  while (a--) {
    ans = 2;
    cin >> u;
    while (u--) {
      cout << ans << " ";
      ans++;
    }
    cout << endl;
  }
}
