#include <bits/stdc++.h>
using namespace std;
int a[200005], sum[200005];
vector<int> v;
int getid(int x) { return lower_bound(v.begin(), v.end(), x) - v.begin() + 1; }
int lowbit(int x) { return x & (-x); }
int ask(int x) {
  int re = 0;
  while (x) {
    re += sum[x];
    x -= lowbit(x);
  }
  return re;
}
void add(int x, int n) {
  while (x <= n) {
    ++sum[x];
    x += lowbit(x);
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    v.clear();
    for (int i = 1; i <= n; ++i) cin >> a[i], v.push_back(a[i]), sum[i] = 0;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      int now = getid(a[i]), num1 = ask(now - 1), num2 = i - 1 - ask(now);
      ans += min(num1, num2);
      add(now, n);
    }
    cout << ans << "\n";
  }
  return 0;
}
