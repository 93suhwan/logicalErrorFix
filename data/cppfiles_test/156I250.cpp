#include <bits/stdc++.h>
using namespace std;
int n;
int md(string a, string b) {
  if (a == b) {
    return 0;
  } else if (n == 1) {
    if (a == b) {
      return 0;
    } else {
      return -1;
    }
  } else {
    map<string, long long> mp;
    int pda = 0, pdb = 0;
    for (int i = 0; i < n; i++) {
      string c = "";
      c += a[i];
      c += b[i];
      mp[c]++;
      if (a[i] == '1') {
        pda = 1;
      }
      if (b[i] == '1') {
        pdb = 1;
      }
    }
    if (pda != pdb) {
      return -1;
    }
    long long ans = -1;
    if ((mp["10"] + mp["01"]) % 2 == 0 && mp["10"] && mp["01"] &&
        mp["10"] == mp["01"]) {
      ans = mp["10"] + mp["01"];
    }
    if ((mp["00"] + mp["11"]) % 2 == 1 && (mp["00"] + 1 == mp["11"])) {
      if (ans == -1) {
        ans = mp["00"] + mp["11"];
      } else {
        ans = min(ans, mp["00"] + mp["11"]);
      }
    }
    return ans;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    string a, b;
    cin >> a >> b;
    cout << md(a, b) << endl;
  }
  return 0;
}
