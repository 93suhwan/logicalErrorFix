#include <bits/stdc++.h>
using namespace std;
const int Maxn = 500005;
const int Inf = 2000000000;
int n, d;
vector<pair<int, int> > good;
int R[Maxn];
vector<pair<int, int> > neut;
vector<pair<int, int> > bad;
int res;
bool byEnd(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second < b.second;
}
int main() {
  scanf("%d %d", &n, &d);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a < d) continue;
    b = max(d, b);
    if (b <= a)
      good.push_back(pair<int, int>(b, a));
    else
      neut.push_back(pair<int, int>(a, b));
  }
  sort(good.begin(), good.end());
  res = good.size();
  R[good.size()] = Inf;
  for (int i = int(good.size()) - 1; i >= 0; i--)
    R[i] = min(R[i + 1], good[i].second);
  for (int i = 0; i < neut.size(); i++) {
    int ind = lower_bound(good.begin(), good.end(),
                          pair<int, int>(neut[i].first + 1, 0)) -
              good.begin();
    if (R[ind] < neut[i].second) continue;
    bad.push_back(neut[i]);
  }
  int lst = 0;
  sort(bad.begin(), bad.end(), byEnd);
  for (int i = 0; i < bad.size(); i++)
    if (lst <= bad[i].first) {
      res++;
      lst = bad[i].second;
    }
  printf("%d\n", res);
  return 0;
}
