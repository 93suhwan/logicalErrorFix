#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int x;
  cin >> x;
  while (x--) {
    int n;
    cin >> n;
    int c = 0;
    string v, s;
    cin >> v;
    s = v;
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
      if (v[i] != s[i]) {
        c++;
      }
    }
    cout << c << "\n";
  }
}
