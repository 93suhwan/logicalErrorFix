#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
void slv() {
  int n, m, k;
  cin >> n >> m >> k;
  vi a(n);
  set<pii> st;
  for (int i = 0; i < n; i++) {
    a[i] = 0;
    st.insert({0, i});
  }
  if (n % m == 0) {
    for (int _ = 0; _ < k; _++) {
      for (int i = 0; i < m; i++) {
        cout << n / m << " ";
        for (int j = 0; j < n / m; j++) {
          cout << i * (n / m) + j + 1 << " ";
        }
        cout << "\n";
      }
    }
  } else {
    for (int _ = 0; _ < k; _++) {
      for (int i = 0; i < m; i++) {
        cout << (n / m) + (i < n % m) << " ";
        for (int j = 0; j < (n + (i < n % m ? m - 1 : 0)) / m; j++) {
          auto it = st.begin();
          pii p = *it;
          int v = p.second;
          a[v] += (i < n % m);
          cout << v + 1 << " ";
          st.erase(it);
        }
        cout << "\n";
      }
      for (int v = 0; v < n; v++) {
        st.insert({a[v], v});
      }
    }
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (int cs = 0; cs < t; cs++) slv();
  return 0;
}
