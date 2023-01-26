#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
vector<int> disc;
int n;
int tr[N], a[N];
int lowbit(int x) { return x & -x; }
int find(int x) {
  return lower_bound(disc.begin(), disc.end(), x, greater<int>()) -
         disc.begin() + 1;
}
void add(int x, int c) {
  for (int i = x; i <= disc.size(); i += lowbit(i)) tr[i] += c;
}
int res(int x) {
  int ans = 0;
  for (int i = x; i; i -= lowbit(i)) ans += tr[i];
  return ans;
}
void init() {
  disc.clear();
  memset(a, 0, sizeof a);
  memset(tr, 0, sizeof tr);
}
bool cmp(int x, int y) { return x > y; }
int main() {
  int T;
  cin >> T;
  while (T--) {
    int cnt = 0;
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      disc.push_back(a[i]);
    }
    sort(disc.begin(), disc.end(), cmp);
    disc.erase(unique(disc.begin(), disc.end()), disc.end());
    for (int i = 1; i <= n; i++) {
      int k = find(a[i]);
      int ans1 = res(k - 1);
      int ans2 = res(disc.size()) - res(k);
      add(k, 1);
      cnt += min(ans1, ans2);
    }
    cout << cnt << endl;
  }
}
