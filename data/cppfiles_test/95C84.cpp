#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long LINF = 1e18;
vector<int> vec[N];
vector<int> prmx[N], prmn[N], sumx[N], sumn[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      prmx[i].push_back(0);
      prmn[i].push_back(INF);
      vec[i].push_back(0);
      for (int j = 1; j <= m; j++) {
        int x;
        scanf("%d", &x);
        vec[i].push_back(x);
        prmx[i].push_back(max(x, prmx[i].back()));
        prmn[i].push_back(min(x, prmn[i].back()));
      }
    }
    for (int i = 1; i <= n; i++) {
      sumx[i].resize(m + 1);
      sumn[i].resize(m + 1);
      for (int j = m; j >= 1; j--) {
        sumx[i][j] = max(vec[i][j], j != m ? sumx[i][j + 1] : 0);
        sumn[i][j] = min(vec[i][j], j != m ? sumn[i][j + 1] : (int)INF);
      }
    }
    bool q = 0;
    string ans(n + 1, 'R');
    int idx = 0;
    for (int j = 1; j <= m - 1; j++) {
      vector<pair<pair<int, int>, int>> vec1, vec2;
      multiset<int> st1, st2;
      for (int i = 1; i <= n; i++) {
        vec1.push_back({{prmn[i][j], prmx[i][j]}, i});
        st1.insert(sumx[i][j + 1]);
      }
      sort(vec1.begin(), vec1.end());
      int r = 0, l = INF;
      for (int i = 0; i < vec1.size() - 1; i++) {
        r = max(r, vec1[i].first.second);
        l = min(l, sumn[vec1[i].second][j + 1]);
        st1.erase(st1.find(sumx[vec1[i].second][j + 1]));
        if (r >= vec1[i + 1].first.first) continue;
        if (l > *st1.rbegin()) {
          q = 1;
          idx = j;
          for (int k = 0; k <= i; k++) ans[vec1[k].second] = 'B';
          break;
        }
      }
    }
    for (int i = 1; i <= n; i++)
      vec[i].clear(), prmx[i].clear(), prmn[i].clear(), sumx[i].clear(),
          sumn[i].clear();
    if (!q) {
      puts("NO");
      continue;
    }
    puts("YES");
    for (int i = 1; i <= n; i++) cout << ans[i];
    printf(" %d\n", idx);
  }
}
