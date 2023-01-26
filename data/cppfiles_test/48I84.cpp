#include <bits/stdc++.h>
using namespace std;
void solvetask() {
  int n;
  cin >> n;
  vector<int> a(n), b, cnt(n + 1);
  int cnt_same = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    if (cnt[a[i]] > 1) {
      cnt_same++;
    }
  }
  b = a;
  sort(b.begin(), b.end());
  int cnt_off = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      cnt_off++;
    }
  }
  if (cnt_off % 3 == 2 && cnt_same == 0)
    cout << "NO" << '\n';
  else
    cout << "YES" << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solvetask();
}
