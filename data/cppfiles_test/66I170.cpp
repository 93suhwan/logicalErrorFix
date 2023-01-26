#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
vector<int> p1(1001, -1), p2(1001, -1), r1(1001, 1), r2(1001, 1);
vector<pair<int, int>> ans;
int find(int x) {
  if (p1[x] == x) return x;
  return p1[x] = find(p1[x]);
}
int find2(int x) {
  if (p2[x] == x) return x;
  return p2[x] = find(p2[x]);
}
void unionfd(int x, int y) {
  int st1 = find(x);
  int st2 = find(y);
  if (st1 != st2) {
    if (r1[st1] < r1[st2]) swap(st1, st2);
    p1[st2] = st1;
    r1[st1] += r1[st2];
  }
}
void unionfd2(int x, int y) {
  int st1 = find2(x);
  int st2 = find2(y);
  if (st1 != st2) {
    if (r2[st1] < r2[st2]) swap(st1, st2);
    p2[st2] = st1;
    r2[st1] += r2[st2];
  }
}
void item() {
  int n, i = 1, ans;
  cin >> n;
  while (n--) {
    while (i % 3 == 0 || i % 3 == 3) i++;
    ans = i;
    i++;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    item();
  }
  return 0;
}
