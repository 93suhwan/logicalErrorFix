#include <bits/stdc++.h>
using namespace std;
int b[8], a1, a2, a3;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    for (int i = 0; i < 7; i++) cin >> b[i];
    printf("%d %d %d\n", b[0], b[1], b[2]);
  }
}
