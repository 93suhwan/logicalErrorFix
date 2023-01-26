#include <bits/stdc++.h>
using namespace std;
void slove() {
  string s, t;
  cin >> s >> t;
  vector<int> a(30, 0);
  for (int i = 0; i < s.size(); i++) {
    a[s[i] - 'a']++;
  }
  if (t != "abc" || (t == "abc" && a[0] == 0)) {
    for (int i = 0; i < 30; i++) {
      char x = i + 'a';
      if (a[i] > 0)
        while (a[i]--) cout << x;
    }
    cout << "\n";
  } else {
    while (a[0]--) cout << "a";
    while (a[2]--) cout << "c";
    while (a[1]--) cout << "b";
    for (int i = 3; i < 30; i++) {
      char x = i + 'a';
      if (a[i] > 0)
        while (a[i]--) cout << x;
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int T = 1;
  cin >> T;
  while (T--) {
    slove();
  }
  return 0;
}
