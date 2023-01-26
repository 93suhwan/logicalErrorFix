#include <bits/stdc++.h>
using namespace std;
int const maxn = 1e6 + 5;
int a[maxn];
int prime[maxn];
int L[maxn];
vector<int> pos[maxn];
inline void add(int x, int l) {
  L[l] = l;
  while (x > 1) {
    pos[prime[x]].push_back(l);
    x /= prime[x];
  }
}
inline void del(int x, int l) {
  if (x == 1) {
    L[l] = l;
    return;
  }
  L[l] = l;
  while (x > 1) {
    if ((int)pos[prime[x]].size() == 0) {
      L[l] = 0;
      return;
    }
    L[l] = min(L[l], pos[prime[x]].back());
    pos[prime[x]].pop_back();
    x /= prime[x];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 2; i < maxn; ++i) {
    if (prime[i] == 0) {
      prime[i] = i;
      if (i > 1000) continue;
      for (int j = i * i; j < maxn; j += i) {
        prime[j] = i;
      }
    }
  }
  char type;
  for (int i = 1; i <= n; ++i) {
    cin >> type;
    if (type == '*')
      add(a[i], i);
    else
      del(a[i], i);
  }
  long long answer = 0;
  vector<int> stk;
  L[n + 1] = -1;
  stk.push_back(n + 1);
  for (int i = n; i >= 1; --i) {
    int cnt = 1;
    while ((int)stk.size() && L[stk.back()] >= L[i]) {
      stk.pop_back();
    }
    if (L[i] == i) {
      answer += stk.back() - i;
    }
    stk.push_back(i);
  }
  cout << answer << '\n';
  return 0;
}
