#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> v(n - 2);
    for (int i = 0; i < n - 2; i++) cin >> v[i];
    int a = v.size();
    if (a == 1) {
      cout << v[0] + v[0][1] << endl;
      continue;
    } else {
      int x = a;
      for (int i = 1; i < a; i++) {
        if (v[i - 1][1] != v[i][0]) {
          x = i;
        }
      }
      string st = "";
      if (x == a) {
        for (int i = 0; i < v.size(); i++) st = st + v[i][0];
        st = st + v[v.size() - 1][1] + 'b';
        cout << st << endl;
        continue;
      } else {
        for (int i = 0; i < x; i++) st = st + v[i][0];
        st = st + v[x - 1][1];
        for (int i = x; i < a; i++) st = st + v[i][0];
      }
      cout << st + v[a - 1][1] << endl;
    }
  }
  return 0;
}
