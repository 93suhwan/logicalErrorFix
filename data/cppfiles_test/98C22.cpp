#include <bits/stdc++.h>
using namespace std;
void init_code() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }
vector<long long int> v1, v2, v3;
map<long long int, long long int> m1, m2, m4;
int main() {
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int q;
  cin >> q;
  while (q--) {
    long long int ans = 0, i;
    map<char, long long int> m1;
    string s, p;
    cin >> s >> p;
    for (i = 0; i < s.length(); i++) {
      m1.insert(make_pair(s[i], i));
    }
    for (i = 0; i < p.length() - 1; i++) {
      ans = ans + abs(m1[p[i + 1]] - m1[p[i]]);
    }
    cout << ans << endl;
  }
}
