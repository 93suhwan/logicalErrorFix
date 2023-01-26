#include <bits/stdc++.h>
using namespace std;
int n, dot;
int acc(int dot, vector<int>& a) {
  return 2 * a[dot] - accumulate(a.begin(), a.end(), 0);
}
bool cmp(vector<int>& a, vector<int>& b) { return acc(dot, a) > acc(dot, b); }
int check(vector<vector<int>>& buc) {
  int ret = 0, cnt = 0;
  sort(buc.begin() + 1, buc.end(), cmp);
  for (int i = (int)(1); i < (int)(n + 1); i++)
    if (cnt + acc(dot, buc[i]) > 0) cnt += acc(dot, buc[i]), ret++;
  return ret;
}
void ac(void) {
  cin >> n;
  vector<vector<int>> buc(n + 1, vector<int>(5));
  string str;
  for (int i = (int)(1); i < (int)(n + 1); i++) {
    cin >> str;
    for (auto I : str) buc[i][I - 'a']++;
  }
  int ans = 0;
  for (int i = (int)(0); i < (int)(5); i++) dot = i, ans = max(ans, check(buc));
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int test = 1;
  cin >> test;
  while (test--) ac();
  return 0;
}
