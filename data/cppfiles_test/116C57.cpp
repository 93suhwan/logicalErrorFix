#include <bits/stdc++.h>
using namespace std;
ifstream fin("Sisend.txt");
long long t, n, c, cc = 998244353;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long> a = {0}, b = {0};
    for (int(i) = (0); ((i)) < ((n + 5)); ((i))++)
      a.emplace_back(0), b.emplace_back(0);
    for (int(i) = (0); ((i)) < ((n)); ((i))++) {
      cin >> c;
      if (!c)
        a[c] = (a[c] * 2 + 1) % cc;
      else
        a[c] = (a[c] * 2 + a[c - 1]) % cc;
      if (c == 1) b[c] = (b[c] * 2 + 1) % cc;
      if (c > 1) b[c] = (a[c - 2] + b[c] * 2) % cc;
      b[c + 2] = (b[c + 2] * 2) % cc;
    }
    long long vas = 0;
    for (int(i) = (0); ((i)) < ((n + 1)); ((i))++) {
      vas += a[i];
      vas %= cc;
      vas += b[i];
      vas %= cc;
    }
    cout << vas << endl;
  }
}
