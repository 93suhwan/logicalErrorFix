#include <bits/stdc++.h>
using namespace std;
void slove() {
  int n;
  cin >> n;
  int ans;
  ans = n / 10;
  if (n % 10 == 9) ans++;
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    slove();
  }
  return 0;
}
