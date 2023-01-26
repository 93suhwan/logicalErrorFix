#include <bits/stdc++.h>
using namespace std;
int countSC(int n) {
  int count = (int)sqrt(n) + (int)cbrt(n) - (int)(sqrt(cbrt(n)));
  return count;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << countSC(n) << "\n";
  }
  return 0;
}
