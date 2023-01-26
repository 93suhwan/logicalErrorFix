#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
pair<bool, bool> prv_state[N][2][2];
int min_index[N][2][2];
bool set_min(int &a, int b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &i : p) cin >> i;
    for (int i = 1; i <= n; ++i) {
      for (int j : {0, 1}) {
        for (int k : {0, 1}) {
          min_index[i][j][k] = INT_MAX;
        }
      }
    }
    min_index[1][false][false] = min_index[1][true][false] = INT_MIN;
    for (int i = 1; i < n; ++i) {
      for (bool sign : {false, true}) {
        for (bool xy : {false, true}) {
          if (min_index[i][sign][xy] == INT_MAX) continue;
          int x = p[i - 1] * (sign ? 1 : -1);
          int y = min_index[i][sign][xy];
          if (xy) swap(x, y);
          for (bool sign_new : {false, true}) {
            int p_new = p[i] * (sign_new ? 1 : -1);
            if (p_new > y) {
              if (set_min(min_index[i + 1][sign_new][p_new < x],
                          p_new < x ? x : y)) {
                prv_state[i + 1][sign_new][p_new < x] = {sign, xy};
              }
            }
          }
        }
      }
    }
    bool sign_prv = false, xy_prv = false, possible = false;
    for (bool sign : {false, true}) {
      for (bool xy : {false, true}) {
        if (min_index[n][sign][xy] < INT_MAX) {
          possible = true, sign_prv = sign, xy_prv = xy;
        }
      }
    }
    if (!possible) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = n - 1; i >= 0; --i) {
      if (!sign_prv) p[i] = -p[i];
      tie(sign_prv, xy_prv) = prv_state[i][sign_prv][xy_prv];
    }
    for (auto i : p) {
      cout << i << " ";
    }
    cout << "\n";
  }
}
