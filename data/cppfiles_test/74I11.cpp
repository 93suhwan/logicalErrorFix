#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, b[maxn], a[maxn], coef[maxn];
bool mark[maxn];
mt19937 rnd(time(0));
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  auto print = [&](vector<int> V) {
    vector<int> ans;
    if (V.size() & 1) {
      assert(V.size() == 3);
      int s = (b[V[0]] + b[V[1]] + b[V[2]]) / 2;
      ans.push_back(s - b[V[0]]);
      ans.push_back(s - b[V[1]]);
      ans.push_back(s - b[V[2]]);
    } else {
      ans.push_back(0);
      for (int i = 0; i + 1 < V.size(); i++) {
        ans.push_back(b[V[i]] - ans.back());
      }
    }
    for (int i : V) mark[i] = 1;
    for (int i = 0; i < n; i++) {
      if (!mark[i]) ans.push_back(b[i] - ans[0]);
    }
    puts("YES");
    for (int x : ans) printf("%d ", x);
    exit(0);
  };
  for (int i = 0; i < n; i++)
    if (!(b[i] % 2)) {
      int odd = 0, even = 0;
      for (int j = 0; j < n; j++)
        if (i ^ j) {
          if (b[j] % 2)
            odd++;
          else
            even++;
        }
      if (odd > 1) {
        vector<int> V = {i};
        for (int j = 0; j < n; j++)
          if (i ^ j) {
            if (b[j] % 2 && V.size() < 3) V.push_back(j);
          }
        print(V);
      } else if (even > 1) {
        vector<int> V = {i};
        for (int j = 0; j < n; j++)
          if (i ^ j) {
            if (!(b[j] % 2) && V.size() < 3) V.push_back(j);
          }
        print(V);
      }
    }
  shuffle(b, b + n, rnd);
  int m = min(25, n), num = 0;
  double st = clock();
  function<void(int, int, int, bool)> dfs = [&](int cur, int sum, int cnt,
                                                bool used) {
    if (++num % 100000 == 0 && (clock() - st) / CLOCKS_PER_SEC > 0.7)
      puts("NO"), exit(0);
    if (cur == m) {
      if (!sum && !cnt && used) {
        vector<int> V1, V2;
        for (int i = 0; i < n; i++) {
          if (coef[i] == 1) V1.push_back(i);
          if (coef[i] == -1) V2.push_back(i);
        }
        assert(V1.size() == V2.size());
        vector<int> V;
        for (int i = 0; i < V1.size(); i++) {
          V.push_back(V1[i]), V.push_back(V2[i]);
        }
        print(V);
      }
      return;
    }
    vector<int> X = {-1, 0, 1};
    shuffle(X.begin(), X.end(), rnd);
    for (int x : X) {
      coef[cur] = x, dfs(cur + 1, sum + x * b[cur], cnt + x, used | (x != 0));
    }
  };
  dfs(0, 0, 0, 0), puts("NO");
  return 0;
}
