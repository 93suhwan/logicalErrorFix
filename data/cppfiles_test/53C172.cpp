#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    char c;
    cin >> n >> c;
    string second;
    cin >> second;
    vector<int> pos;
    for (int i = 0; i < n; i++)
      if (second[i] != c) pos.push_back(i + 1);
    if (pos.size() == 0) {
      cout << "0\n";
    } else if (pos.back() < n) {
      cout << "1\n" << n << '\n';
    } else {
      vector<int> u(n + 1, 0);
      for (auto t : pos) {
        for (int j = 1; (j * j) <= t; j++)
          if ((t % j) == 0) {
            u[j] = 1;
            u[t / j] = 1;
          }
      }
      int j = 1;
      while (j <= n && u[j]) j++;
      if (j < n) {
        cout << "1\n";
        cout << j << '\n';
      } else
        cout << "2\n" << (n - 1) << ' ' << n << '\n';
    }
  }
}
