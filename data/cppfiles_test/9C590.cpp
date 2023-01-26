#include <bits/stdc++.h>
using namespace std;
int used[500];
string s;
int t;
void solve() {
  cin >> t;
  while (t--) {
    cin >> s;
    for (int i = 0; i < 150; i++) used[i] = 0;
    for (int i = 0; i < s.size(); i++) {
      used[s[i]]++;
    }
    int p = 0;
    int o = 0;
    for (int i = 97; i < 123; i++) {
      if (used[i] >= 2) p += 2;
      if (used[i] == 1) o++;
    }
    int k = p / 2;
    if (o % 2 == 0)
      k += o / 2;
    else {
      k += (o - 1) / 2;
    }
    cout << k << endl;
  }
}
int main() {
  solve();
  return 0;
}
