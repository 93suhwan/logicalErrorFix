#include <bits/stdc++.h>
#pragma GCC optimize("O3")
const double PI = acos(-1);
template <class A, class B>
std::ostream& operator<<(std::ostream& st, const std::pair<A, B> p) {
  st << "(" << p.first << ", " << p.second << ")";
  return st;
}
void tc();
auto test_cases = []() {
  int T;
  scanf("%d", &T);
  while (T--) tc();
};
using namespace std;
const int MAXB = 5000, MAX = 1 << 20;
int n, m;
int cnt[MAXB][MAXB];
int X[MAX], Y[MAX];
int B;
int BIT[MAX], day[MAX];
int flag[MAX];
int visId[MAX], status[MAX], visNum;
void update(const vector<pair<int, std::pair<int, int>>>& aux) {
  for (auto [j, info] : aux) {
    auto [dj, sgn] = info;
    int s = X[j] + Y[j];
    for (int t = 0; t < (Y[j]); t++) {
      int i = t + X[j];
      if (t >= s) t -= s;
      cnt[s][i] += sgn;
    }
  }
}
void update(int d, int x, int y, int v) {
  int s = x + y;
  for (int t = d; t <= m; t += s) {
    if (t + x <= m) flag[t + x] += v;
    if (t + s <= m) flag[t + s] -= v;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  B = sqrt(m);
  for (int i = 1; i <= n; i++) scanf("%d %d", X + i, Y + i);
  vector<pair<int, std::pair<int, int>>> aux;
  int sum = 0;
  for (int d = 1; d <= m; d++) {
    sum += flag[d];
    int type, j;
    scanf("%d %d", &type, &j);
    int s = X[j] + Y[j];
    if (s >= B) {
      if (day[j]) {
        sum -= (d - day[j]) % (X[j] + Y[j]) >= X[j];
        update(day[j], X[j], Y[j], -1);
        day[j] = 0;
      } else {
        update(d, X[j], Y[j], 1);
        day[j] = d;
      }
    } else {
      if (day[j]) {
        aux.emplace_back(j, std::pair<int, int>(day[j], -1));
        day[j] = 0;
      } else {
        aux.emplace_back(j, std::pair<int, int>(d, 1));
        day[j] = d;
      }
    }
    int ans = sum;
    for (int s = 1; s < B; s++) ans += cnt[s][d % s];
    for (auto [j, info] : aux) {
      auto [dj, sgn] = info;
      int v = (d - dj) % (X[j] + Y[j]) >= X[j];
      ans += v * sgn;
    }
    printf("%d\n", ans);
    if (((int)aux.size()) >= B) {
      update(aux);
      aux.clear();
    }
  }
  return 0;
}
