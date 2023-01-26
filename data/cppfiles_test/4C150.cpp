#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
int main() {
  fast();
  long long t, i;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if ((n - 1) / 2 == 2)
      cout << 2 << " " << (n - 1) / 2 * 2 << endl;
    else
      cout << 2 << " " << (n - 1) / 2 << endl;
  }
  return 0;
}
