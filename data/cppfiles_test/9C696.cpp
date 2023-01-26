#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, i, j, k, t, temp, tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    int len = s.length();
    int f[26];
    for (i = 0; i < 26; i++) {
      f[i] = 0;
    }
    for (auto &x : s) {
      f[x - 'a']++;
    }
    int poss = 0;
    for (i = 0; i < 26; i++) {
      poss += min(2, f[i]);
    }
    if (poss & 1) {
      poss--;
    }
    cout << poss / 2 << endl;
  }
  return 0;
}
