#include <bits/stdc++.h>
using namespace std;
const int nh = 200013, ogo = 1000000007, og0 = 998244353;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int lol;
  cin >> lol;
  while (lol--) {
    int n, k;
    long long x;
    string s, c;
    cin >> n >> k >> x >> s;
    x--;
    vector<int> bla(n);
    if (s[0] != 'a') bla[0]--;
    for (int i = 1; i < n; i++) {
      bla[i] = bla[i - 1];
      if (s[i] == 'a') bla[i] = i;
    }
    for (int i = n - 1; i >= 0;) {
      if (s[i] == 'a') {
        c.push_back('a');
        i--;
      } else {
        int q = k * (i - bla[i]) + 1;
        for (int j = 0; j < x % q; j++) c.push_back('b');
        x /= q;
        i = bla[i];
      }
    }
    reverse((c).begin(), (c).end());
    cout << c << "\n";
  }
  return 0;
}
