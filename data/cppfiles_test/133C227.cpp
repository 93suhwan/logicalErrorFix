#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string ans;
    string v;
    string p;
    for (int i = 0; i < n - 2; i++) {
      cin >> v;
      if (v[0] == p[1] && i != 0) {
        ans += v[0];
      } else if ((v[0] != p[1]) && i != 0) {
        ans += p[1];
        ans += v[0];
      } else {
        ans += v[0];
      }
      p = v;
    }
    ans += v[1];
    if (ans.size() != n) {
      ans += 'a';
    }
    cout << ans << endl;
  }
}
