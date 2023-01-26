#include <bits/stdc++.h>
using namespace std;
int tt;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (int i = 0; i < n / 2; i++) cout << "a";
    cout << "c";
    if (n & 1) cout << "b";
    for (int i = 0; i < n / 2 - 1; i++) cout << "a";
    cout << '\n';
  }
}
