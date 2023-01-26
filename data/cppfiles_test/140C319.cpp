#include <bits/stdc++.h>
using namespace std;
int countSC(int N) {
  int res = (int)sqrt(N) + (int)cbrt(N) - (int)(sqrt(cbrt(N)));
  return res;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    cout << countSC(N) << endl;
  }
  return 0;
}
