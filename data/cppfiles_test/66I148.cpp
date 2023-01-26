#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
long long fix_mod(long long x, long long y) { return (y + x % y) % y; }
void fast() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
int main() {
  fast();
  vector<long long> v;
  for (int i = 1;; i++) {
    bool valid = (i % 3 != 0);
    int j = i;
    while (j) {
      if (j % 10 == 3) valid = 0;
      j /= 10;
    }
    if (valid) v.push_back(i);
    if (v.size() == 1000) break;
  }
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    cout << v[k - 1] << "\n";
  }
}
