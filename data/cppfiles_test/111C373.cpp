#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  short m;
  cin >> m;
  while (m--) {
    int k;
    cin >> k;
    string s = "";
    for (int i = 0; i < k - 1; i++) {
      s += "(";
    }
    for (int i = k; i < (k * 2) - 1; i++) {
      s += ")";
    }
    cout << "()" << s << endl;
    int it = 0;
    it++;
    k--;
    while (k > 0) {
      s.insert(it, "()");
      cout << s << endl;
      s.erase(it, 2);
      k--;
      it++;
    }
  }
  return 0;
}
