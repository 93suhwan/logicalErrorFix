#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  cout << setprecision(7) << fixed;
  while (q--) {
    int n;
    cin >> n;
    long long m;
    cin >> m;
    long long s = m;
    for (int i = 1; i < n; ++i) {
      long long new_a;
      cin >> new_a;
      s += new_a;
      m = max(m, new_a);
    }
    s -= m;
    cout << static_cast<double>(m) +
                static_cast<double>(s) / static_cast<double>(n - 1)
         << endl;
  }
  return 0;
}
