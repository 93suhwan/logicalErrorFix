#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long int myRand(long long int B) { return (unsigned long long)rng() % B; }
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int del = 0;
    int j = 0;
    for (int i = 0; i < s.size() and j < t.size(); i++) {
      if (del > 0) {
        del--;
      } else {
        if (t[j] == s[i]) {
          j++;
        } else {
          del++;
        }
      }
    }
    if (j == t.size()) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}
