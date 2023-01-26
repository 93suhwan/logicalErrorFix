#include <bits/stdc++.h>
using namespace std;
template <class Num>
Num mabs(Num x) {
  if (x < 0) return -x;
  return x;
}
void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> a(n);
  vector<int> cnt(n + 1, 0);
  set<int> ss;
  vector<vector<int>> gdje(n + 1, vector<int>());
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
    gdje[a[i]].push_back(i);
    ss.insert(a[i]);
  }
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += min(k, cnt[i]);
  }
  int svaki = sum / k;
  vector<int> sol(n, 0);
  for (int i = 1; i <= k; i++) {
    int cc = 0;
    while (svaki > cc) {
      int mini = *ss.begin();
      cnt[mini]--;
      int ind = gdje[mini].back();
      gdje[mini].pop_back();
      sol[ind] = i;
      if (cnt[mini] == 0) ss.erase(ss.begin());
      cc++;
    }
  }
  for (int s : sol) printf("%d ", s);
  puts("");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
