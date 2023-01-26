#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int main() {
  int _;
  scanf("%d", &_);
  while (_--) {
    string s, t;
    cin >> s >> t;
    string ss = s;
    sort(ss.begin(), ss.end());
    if (t == "abc") {
      int x, y, z;
      bool ins1 = 0, ins2 = 0, ins3 = 0;
      for (int i = 0; i <= ss.size() - 1; i++) {
        if (!ins1 && ss[i] == 'a') ins1 = 1, x = i;
        if (!ins2 && ss[i] == 'b') ins2 = 1, y = i;
        if (!ins3 && ss[i] == 'c') ins3 = 1, z = i;
      }
      if (ins1 && ins2 && ins3) swap(ss[y], ss[z]);
    }
    cout << ss << endl;
  }
  return 0;
}
