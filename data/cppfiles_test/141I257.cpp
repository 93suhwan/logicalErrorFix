#include <bits/stdc++.h>
using namespace std;
using namespace std;
int N;
string s1, s2;
inline void solve() {
  cin >> s1 >> s2;
  vector<int> ret;
  int i = s1.size() - 1, j = s2.size() - 1;
  while (i >= 0 and j >= 0) {
    int cur_s1 = s1[i] - '0', cur_s2 = s2[j] - '0';
    if (cur_s2 >= cur_s1) {
      ret.push_back(cur_s2 - cur_s1);
      i -= 1, j -= 1;
    } else {
      if (j == 0) {
        cout << -1 << endl;
        return;
      } else {
        cur_s2 = cur_s2 + (s2[j - 1] - '0') * 10;
        int potential = cur_s2 - cur_s1;
        if (potential >= 10) {
          cout << -1 << endl;
          return;
        } else {
          ret.push_back(potential);
          i -= 1, j -= 2;
        }
      }
    }
  }
  if (i != -1) {
    cout << -1 << endl;
    return;
  }
  while (j >= 0) {
    ret.push_back(s2[j] - '0');
    j -= 1;
  }
  while (ret.size() > 1 and ret.back() == 0) ret.pop_back();
  reverse(ret.begin(), ret.end());
  for (int i : ret) cout << i;
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  while (N--) {
    solve();
  }
  return 0;
}
