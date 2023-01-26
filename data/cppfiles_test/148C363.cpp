#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void solve() {
  long long w, h;
  cin >> w >> h;
  int l1;
  cin >> l1;
  vector<long long> row1(l1);
  for (int i = 0; i < l1; i++) {
    cin >> row1[i];
  }
  int l2;
  cin >> l2;
  vector<long long> row2(l2);
  for (int i = 0; i < l2; i++) {
    cin >> row2[i];
  }
  sort(row1.begin(), row1.end());
  sort(row2.begin(), row2.end());
  long long gap = max(row1[l1 - 1] - row1[0], row2[l2 - 1] - row2[0]);
  int h1;
  cin >> h1;
  vector<long long> col1(h1);
  for (int i = 0; i < h1; i++) {
    cin >> col1[i];
  }
  int h2;
  cin >> h2;
  vector<long long> col2(h2);
  for (int i = 0; i < h2; i++) {
    cin >> col2[i];
  }
  sort(col1.begin(), col1.end());
  sort(col2.begin(), col2.end());
  long long gap2 = max(col1[h1 - 1] - col1[0], col2[h2 - 1] - col2[0]);
  long long area = max(h * gap, w * gap2);
  cout << area << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
