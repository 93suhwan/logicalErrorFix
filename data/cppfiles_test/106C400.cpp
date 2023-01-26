#include <bits/stdc++.h>
using namespace std;
void Read() {
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 2; i <= n + 1; ++i) cout << i << " ";
    cout << '\n';
  }
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Read();
  return 0;
}
