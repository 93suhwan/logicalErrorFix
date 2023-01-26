#include <bits/stdc++.h>
const int INF = 0x7fffffff;
const int N = 1e5 + 5;
const double eps = 1e-10;
using namespace std;
int n, m, ok;
vector<int> g[N];
set<int> choose;
set<int>::iterator iter1, iter2;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = (1); i <= (m); i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y), g[y].push_back(x);
  }
  for (int cas = 1; cas <= 100000; cas++) {
    ok = 1;
    choose.clear();
    for (int i = (1); i <= (5); i++) {
      int tmp = (rand() % n) + 1;
      while (i > 1 && choose.count(tmp)) tmp = rand() % n + 1;
      choose.insert(tmp);
    }
    for (iter1 = choose.begin(); iter1 != choose.end(); iter1++) {
      for (iter2 = choose.begin(); iter2 != choose.end(); iter2++) {
        if (*iter2 == *iter1) continue;
        if (binary_search(g[*iter1].begin(), g[*iter1].end(), *iter2)) {
          ok = 0;
          break;
        }
      }
      if (!ok) break;
    }
    if (ok) {
      for (iter1 = choose.begin(); iter1 != choose.end(); iter1++)
        cout << *iter1 << " ";
      cout << endl;
      return 0;
    }
  }
  puts("-1");
}
