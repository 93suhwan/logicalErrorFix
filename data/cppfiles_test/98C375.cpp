#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int mid, i, j, k, l, m, n, ans = 0, minn = INT_MAX, maxx = INT_MIN,
                                       x, sum = 0, c = 0, odd = 0, even = 0, q,
                                       ab = 0, ba = 0, y, a, b;
  string s;
  char cc = 'a';
  cin >> s;
  string word;
  cin >> word;
  vector<int> v;
  for (i = 0; word[i] != '\0'; i++) {
    for (j = 0; s[j] != '\0'; j++) {
      if (s[j] == word[i]) {
        v.push_back(j + 1);
        break;
      }
    }
  }
  for (i = 0; i < v.size() - 1; i++) {
    ans += abs(v[i] - v[i + 1]);
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
