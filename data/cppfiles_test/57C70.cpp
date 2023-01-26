#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2100;
int n;
int p[MAXN];
vector<int> ans;
void rev(int x) {
  if (x == 1) return;
  if (ans.empty() == false && ans.back() == x) {
    ans.pop_back();
    return;
  }
  ans.push_back(x);
  reverse(p + 1, p + x + 1);
}
void rev(int x, int &ind, int &ind1) {
  rev(x);
  if (ind <= x) ind = x - ind + 1;
  if (ind1 <= x) ind1 = x - ind1 + 1;
}
void solveTestcase() {
  ans.clear();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) {
    if (p[i] % 2 != i % 2) {
      cout << "-1" << '\n';
      return;
    }
  }
  for (int num = n; num > 1; num -= 2) {
    if (p[num] == num && p[num - 1] == num - 1) continue;
    if (p[1] == num && p[2] == num - 1) {
      rev(num);
      continue;
    }
    int ind = -1, ind1 = -1;
    for (int i = 1; i <= num; i++) {
      if (p[i] == num) {
        ind = i;
      }
      if (p[i] == num - 1) {
        ind1 = i;
      }
    }
    if (p[ind - 1] == num - 1) {
      rev(ind);
      rev(num);
      continue;
    }
    if (p[ind + 1] == num - 1) {
      rev(num);
      ind = num - ind + 1;
      rev(ind);
      rev(num);
      continue;
    }
    if (ind < ind1) {
      rev(ind, ind, ind1);
      rev(ind1 - 1, ind, ind1);
      rev(num, ind, ind1);
      rev(ind);
      rev(num);
      continue;
    }
    if (ind > ind1) {
      rev(ind, ind, ind1);
      rev(ind1 - 1, ind, ind1);
      rev(num, ind, ind1);
      rev(ind, ind, ind1);
      rev(num, ind, ind1);
      continue;
    }
    cout << "-1" << '\n';
    return;
  }
  if (ans.size() > n * 2.5) {
    cout << "-1" << '\n';
    return;
  }
  cout << ans.size() << '\n';
  for (int x : ans) cout << x << " ";
  cout << '\n';
}
int main() {
  int T;
  cin >> T;
  while (T--) solveTestcase();
}
