#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 50;
constexpr double eps = 1e-8;
constexpr int inf = 0x3f3f3f3f;
constexpr long long linf = 0x3f3f3f3f3f3f3f3f;
int m, n;
int vis[maxn];
set<pair<int, int> > st;
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n % m == 0) {
      for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j += n / m) {
          cout << n / m << " ";
          for (int p = 1; p <= n / m; p++) cout << j + p - 1 << " ";
          cout << endl;
        }
      }
      continue;
    }
    int round_up = n / m + 1;
    int round_down = n / m;
    st.clear();
    for (int i = 1; i <= n; i++) {
      st.insert({0, i});
    }
    for (int i = 1; i <= k; i++) {
      for (int j = 1; j <= n; j++) {
        vis[j] = 0;
      }
      for (int p = 1; p <= n % m; p++) {
        cout << round_up << " ";
        for (int j = 1; j <= round_up; j++) {
          auto it = st.begin();
          cout << (*it).second << " ";
          vis[(*it).second] = 1;
          st.insert({(*it).first + 1, (*it).second});
          it = st.erase(it);
        }
        cout << endl;
      }
      int st = 1;
      for (int j = 1; j <= m - n % m; j++) {
        cout << round_down << " ";
        for (int p = 1; p <= round_down; p++) {
          while (vis[st]) st++;
          vis[st] = 1;
          cout << st << " ";
        }
        cout << endl;
      }
    }
  }
}
