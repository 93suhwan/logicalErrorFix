#include <bits/stdc++.h>
using namespace std;
int nod(int a, int b) {
  if (min(a, b) == 0) return max(a, b);
  return nod(min(a, b), max(a, b) % min(a, b));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int lol;
  cin >> lol;
  for (int kik = 0; kik < lol; ++kik) {
    vector<int> v(6);
    for (int i = 0; i < 6; ++i) cin >> v[i];
    if (v[2] == v[4] || v[3] == v[5])
      cout << 0;
    else {
      if (v[4] > v[2] && v[5] > v[3]) {
        cout << min(v[4] - v[2], v[5] - v[3]);
      } else if (v[4] > v[2] && v[5] < v[3]) {
        cout << min(v[4] - v[2], v[1] - v[3] + v[1] - v[5]);
      } else if (v[5] > v[3] && v[4] < v[2]) {
        cout << min(v[5] - v[3], v[0] - v[2] + v[0] - v[4]);
      } else {
        cout << min(v[0] - v[2] + v[0] - v[4], v[1] - v[3] + v[1] - v[5]);
      }
    }
    cout << endl;
  }
  return 0;
}
