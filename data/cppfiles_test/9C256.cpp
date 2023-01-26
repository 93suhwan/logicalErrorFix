#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string n;
    cin >> n;
    map<int, int> mp;
    int c = 0;
    int k = 0;
    for (int i = 0; i < 2; i++) {
      k++;
    }
    for (int i = 0; i < n.size(); i++) {
      if (!mp[n[i]]) {
        c++;
        mp[n[i]]++;
      } else {
        if (mp[n[i]] == 1) {
          c++;
          mp[n[i]]++;
        }
        mp[n[i]]++;
      }
    }
    int u;
    for (int i = 0; i < 2; i++) {
      k++;
    }
    u = k;
    int ans;
    ans = c / 2;
    cout << ans << endl;
  }
}
