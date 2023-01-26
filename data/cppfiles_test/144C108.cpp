#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int tt = 0; tt < int(t); tt++) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(n);
    for (int i = 0; i < int(n); i++) p[i] = i;
    if (tt > 0) cout << endl;
    for (int round = 0; round < int(k); round++) {
      int index = 0;
      for (int table = 0; table < int(m); table++) {
        int size = n / m;
        if (table < n % m) size++;
        cout << size;
        for (int j = 0; j < int(size); j++) cout << " " << p[index++] + 1;
        cout << endl;
      }
      rotate(p.begin(), p.begin() + (n % m) * ((n + m - 1) / m), p.end());
    }
  }
}
