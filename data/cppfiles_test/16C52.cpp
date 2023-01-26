#include <bits/stdc++.h>
using namespace std;
void init_code() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  init_code();
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k = 0;
    cin >> n;
    string s;
    cin >> s;
    int l = s.size();
    string t = s;
    sort(s.begin(), s.end());
    for (int i = 0; i < l; i++) {
      k += (s[i] != t[i]);
    }
    cout << k << endl;
  }
  return 0;
}
