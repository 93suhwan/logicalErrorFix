#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30) - 1;
const long long LINF = (1LL << 60) - 1;
template <class T>
bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  } else
    return false;
}
template <class T>
bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  } else
    return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string n;
    cin >> n;
    int k;
    cin >> k;
    vector<vector<vector<long long> > > ans(
        n.size() + 1,
        vector<vector<long long> >(11, vector<long long>(2, LINF)));
    ans[0][0][0] = 0;
    for (int i = 0; i < n.size(); i++) {
      int ni = n[i] - '0';
      for (int j = 0; j < 11; j++) {
        for (int k = 0; k < 2; k++) {
          if (ans[i][j][k] == LINF) continue;
          set<int> st;
          long long m = ans[i][j][k];
          while (m) {
            st.insert(m % 10);
            m /= 10;
          }
          for (int x = (k ? 0 : ni); x < 10; x++) {
            chmin(ans[i + 1][j + (st.find(x) == st.end())][k || (x > ni)],
                  ans[i][j][k] * 10 + x);
          }
        }
      }
    }
    long long res = LINF;
    for (int l = 0; l < k + 1; l++) {
      for (int j = 0; j < 2; j++) chmin(res, ans[n.size()][l][j]);
    }
    cout << res << endl;
  }
  return 0;
}
