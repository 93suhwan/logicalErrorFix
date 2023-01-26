#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2100;
int n;
int p[MAXN];
vector<int> ans;
void rev(int x) {
  ans.push_back(x);
  reverse(p + 1, p + x + 1);
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
    int ind = -1;
    for (int i = 1; i <= num; i++) {
      if (p[i] == num) {
        ind = i;
        break;
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
