#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int Nmax = 2010;
int n, m;
char c[Nmax][Nmax];
struct Line {
  long long a, b;
  long long operator()(long long x) { return a * x + b; }
};
vector<Line> convex;
int bad(Line& L1, Line& L2, Line& L3) {
  return 1.0L * (L3.b - L1.b) / (L1.a - L3.a) <=
         1.0L * (L2.b - L1.b) / (L1.a - L2.a);
}
long long ans;
int pointer;
void add(Line l) {
  while (convex.size() >= 2 && bad(*-- --convex.end(), convex.back(), l))
    convex.pop_back();
  convex.push_back(l);
  pointer = min(pointer, (int)convex.size() - 1);
}
long long get(long long x) {
  while (pointer < convex.size() - 1 &&
         convex[pointer](x) > convex[pointer + 1](x))
    ++pointer;
  return convex[pointer](x);
}
int near[Nmax];
long long s[Nmax][Nmax];
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  ++n, ++m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> c[i][j];
  memset(s, 60, sizeof(s));
  for (int i = 1; i <= n; ++i) {
    convex.clear();
    pointer = 0;
    for (int j = 1; j <= m; ++j)
      if (c[i][j] == '1') near[j] = i;
    for (int j = 1; j <= m; ++j)
      if (near[j]) add({-2 * j, j * j + (i - near[j]) * (i - near[j])});
    for (int j = 1; j <= m; ++j) s[i][j] = min(s[i][j], get(j) + j * j);
  }
  memset(near, 0, sizeof(near));
  for (int i = n; i >= 1; --i) {
    convex.clear();
    pointer = 0;
    for (int j = 1; j <= m; ++j)
      if (c[i][j] == '1') near[j] = i;
    for (int j = 1; j <= m; ++j)
      if (near[j]) add({-2 * j, j * j + (i - near[j]) * (i - near[j])});
    for (int j = 1; j <= m; ++j) s[i][j] = min(s[i][j], get(j) + j * j);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) ans += s[i][j];
  cout << ans;
}
