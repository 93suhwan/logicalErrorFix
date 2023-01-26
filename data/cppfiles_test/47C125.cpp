#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
const int oo = 1e9 + 7;
void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
int a[maxn];
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> pos, neg;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > 0) pos.push_back(a[i]);
    if (a[i] < 0) neg.push_back(abs(a[i]));
  }
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  long long res = 0;
  int n1 = pos.size();
  int take_first = n1 % k;
  int maxx = 0;
  for (int i = 0; i < take_first; i++) {
    maxx = max(maxx, pos[i]);
  }
  res += 1ll * maxx * 2;
  for (int i = take_first; i < pos.size(); i += k) {
    maxx = 0;
    for (int j = i; j < i + k; j++) {
      maxx = max(maxx, pos[j]);
    }
    res += 1ll * maxx * 2;
  }
  int n2 = neg.size();
  take_first = n2 % k;
  maxx = 0;
  for (int i = 0; i < take_first; i++) {
    maxx = max(maxx, neg[i]);
  }
  res += 1ll * maxx * 2;
  for (int i = take_first; i < neg.size(); i += k) {
    maxx = 0;
    for (int j = i; j < i + k; j++) {
      maxx = max(maxx, neg[j]);
    }
    res += 1ll * maxx * 2;
  }
  maxx = 0;
  if (pos.size() != 0 && neg.size() != 0)
    maxx = max(pos.back(), neg.back());
  else {
    if (pos.size() != 0) maxx = pos.back();
    if (neg.size() != 0) maxx = neg.back();
  }
  cout << res - 1ll * maxx << endl;
}
int main() {
  init();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  vector<int> x;
}
