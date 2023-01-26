#include <bits/stdc++.h>
using namespace std;
void eval(void) {
  int n;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i += 1) cin >> v[i];
  int maxi = 0;
  for (char z = 'a'; z < 'f'; z++) {
    vector<int> s;
    for (int i = 0; i < n; i++) {
      int k = 0;
      for (int j = 0; j < (int)(v[i]).size(); j++) {
        if (v[i][j] != z) k++;
      }
      s.push_back((int)(v[i]).size() - k - k);
    }
    sort((s).begin(), (s).end(), greater<int>());
    int x = 0, y = 0;
    for (int p = 0; p < (int)(s).size(); p += 1) {
      if (x + s[p] > 0) {
        y++;
        x += s[p];
      } else
        break;
    }
    maxi = max(maxi, y);
  }
  cout << maxi << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) eval();
  return 0;
}
