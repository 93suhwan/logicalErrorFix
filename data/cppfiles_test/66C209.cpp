#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, i = 0;
  cin >> t;
  while (t--) {
    i = 0;
    cin >> n;
    while (n != 0) {
      i++;
      if (i % 3 != 0 && (i - 3) % 10 != 0) n--;
    }
    cout << i << endl;
  }
  return 0;
}
