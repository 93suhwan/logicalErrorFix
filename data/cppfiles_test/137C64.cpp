#include <bits/stdc++.h>
using namespace std;
const int dx[9] = {0, 0, -1, 1, -1, -1, 1, 1, 0};
const int dy[9] = {-1, 1, 0, 0, -1, 1, -1, 1, 0};
long long a, b;
set<long long> st;
long long rev(long long x) {
  long long res = 0;
  while (x) {
    res <<= 1;
    res += x & 1;
    x >>= 1;
  }
  return res;
}
long long get(long long x) {
  long long res = 0;
  while (x) {
    res++;
    x >>= 1;
  }
  return res;
}
bool dfs(long long u) {
  if (st.count(u) || get(u) > get(b)) return false;
  if (u == b) return true;
  st.insert(u);
  return dfs(rev(u * 2)) || dfs(rev(u * 2 + 1));
}
void solve() {
  if (a == b) {
    cout << "YES"
         << "\n";
    return;
  }
  bool ans = dfs(rev(a * 2)) || dfs(rev(a * 2 + 1));
  cout << (ans ? "YES" : "NO") << "\n";
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> a >> b;
  solve();
  return 0;
}
