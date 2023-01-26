#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int random(int x) { return (long long)rand() * rand() % x + 1; }
int main() {
  int n, m;
  cin >> n >> m;
  set<pair<int, int>> st;
  while (m--) {
    int u, v;
    cin >> u >> v;
    st.insert({u, v});
    st.insert({v, u});
  }
  if (n <= 120) {
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        for (int k = j + 1; k <= n; k++)
          for (int l = k + 1; l <= n; l++)
            for (int r = l + 1; r <= n; r++) {
              vector<int> a;
              a.push_back(i), a.push_back(j), a.push_back(k), a.push_back(l),
                  a.push_back(r);
              bool ok1 = false, ok2 = false;
              for (int x = 0; x < 5; x++)
                for (int y = x + 1; y < 5; y++) {
                  int u = a[x], v = a[y];
                  if (st.find({u, v}) != st.end())
                    ok1 = true;
                  else
                    ok2 = true;
                }
              if (ok1 != ok2) {
                for (int i : a) cout << i << ' ';
                return 0;
              }
            }
    cout << "-1\n";
  } else {
    srand(time(0));
    int t = 1e7;
    while (t--) {
      vector<int> a(5);
      for (int i = 0; i < 5; i++) {
        a[i] = random(n);
      }
      bool ok1 = false, ok2 = false, ok = true;
      for (int i = 0; i < 5 && ok; i++)
        for (int j = i + 1; j < 5 && ok; j++) {
          int u = a[i], v = a[j];
          if (u == v) {
            ok = false;
            break;
          }
          if (st.find({u, v}) != st.end())
            ok1 = true;
          else
            ok2 = true;
        }
      if (ok && (ok1 == ok2)) {
        for (int i : a) cout << i << ' ';
        return 0;
      }
    }
    puts("-1");
  }
  return 0;
}
