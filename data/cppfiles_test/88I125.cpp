#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> ls(n), la(n, 1);
    for (int &x : ls) cin >> x;
    if (n & 1) {
      int f = 0;
      for (int u = 1; u < n; u++) {
        if (ls[u - 1] < ls[u] && la[u - 1] == 1) la[u] = 2, f++;
      }
      if (f > 2)
        cout << "YES";
      else if (f == 2) {
        vector<int> ni;
        for (int u = 0; u < n; u++)
          if (la[u] == 2) ni.push_back(u);
        if (ni[0] + 2 != ni[1])
          cout << "YES";
        else if (ni[0])
          cout << "YES";
        else if (ni[1] + 2 != n)
          cout << "YES";
        else
          cout << "NO";
      } else
        cout << "NO";
    } else
      cout << "YES";
    cout << "\n";
  }
}
