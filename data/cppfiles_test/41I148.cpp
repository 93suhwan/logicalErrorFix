#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  int n;
  string str;
  cin >> n >> tc;
  cin >> str;
  while (tc--) {
    int l, r, a, ans;
    ans = r - l + 1;
    cin >> l >> r;
    l--;
    r--;
    vector<char> vc(3);
    vc[0] = 'a';
    vc[1] = 'b';
    vc[2] = 'c';
    do {
      a = 0;
      for (int i = l; i <= r; i++) {
        if (str[i] != vc[i % 3]) a++;
      }
      ans = min(ans, a);
    } while (next_permutation(vc.begin(), vc.end()));
    cout << ans << endl;
  }
}
