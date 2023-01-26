#include <bits/stdc++.h>
using namespace std;
int n;
int NN = 20;
string s[20];
map<int, int> cnt[20];
vector<int> tot(20, 0);
vector<int> ts((1 << NN), 0);
vector<int> vis((1 << NN), 0);
vector<int> dp((1 << NN), 0);
vector<int> lst((1 << NN), 0);
int ans = 0;
int fun(int x) {
  if (vis[x]) return dp[x];
  vis[x]++;
  if (ts[x] < 0) return 0;
  int cmax = 0;
  for (int i = 0; i < n; i++) {
    if (((1 << i) & x) == 0) {
      int y = cnt[i][-ts[x]];
      if (lst[(1 << i)] + tot[x] >= 0) y += fun(x | (1 << i));
      cmax = max(cmax, y);
    }
  }
  dp[x] = cmax;
  return cmax;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    int curr = 0;
    bool less = false;
    int least = 0;
    for (auto j : s[i]) {
      if (j == '(')
        curr++;
      else
        curr--;
      if (curr <= 0 && least >= curr) cnt[i][curr]++;
      if (curr < 0) {
        least = min(least, curr);
      }
    }
    lst[i] = least;
    tot[i] = curr;
  }
  int N = (1 << n);
  for (int i = 1; i < N; i++) {
    int a = 0;
    for (int j = 0; j < 20; j++) {
      if (((1 << j) & i) != 0) a += tot[j];
    }
    ts[i] = a;
  }
  fun(0);
  cout << dp[0];
}
