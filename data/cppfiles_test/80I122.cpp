#include <bits/stdc++.h>
using namespace std;
const long long MX = 303030;
const long long INF = 9e15;
long long tc;
vector<long long> v[2];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> tc;
  while (tc--) {
    long long n;
    string s;
    cin >> n;
    cin >> s;
    long long chk[2] = {0};
    v[0].clear();
    v[1].clear();
    for (int i = 0; i < s.size(); i++) {
      chk[s[i] - '0'] = 1;
      v[s[i] - '0'].push_back(i);
    }
    if ((!chk[0] && chk[1])) {
      cout << n / 2 + 1 << " " << n << " " << 1 << " " << n / 2 << "\n";
    } else {
      long long ret = 0;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0' && n - i - 1 >= n / 2) {
          cout << i + 1 << " " << n << " " << i + 2 << " " << n << "\n";
          ret = 1;
          break;
        }
      }
      if (!ret) {
        for (int i = s.size() - 1; i >= 0; i--) {
          if (s[i] == '0' && i >= n / 2) {
            cout << 1 << " " << i + 1 << " " << 1 << " " << i << "\n";
            break;
          }
        }
      }
    }
  }
}
