#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, k, c[N * N];
void solve(int l, int r, int lvl) {
  if (r - l == 1) return;
  int stp = (r - l + k - 1) / k;
  for (int st = l; st < r; st += stp) {
    int en = min(r, st + stp);
    for (int i = st; i < en; i++)
      for (int j = en; j < r; j++) c[i * n + j] = lvl;
    solve(st, en, lvl + 1);
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> k;
  solve(0, n, 1);
  cout << *max_element(c, c + N) << "\n";
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) cout << c[i * n + j] << " ";
  cout << "\n";
}
