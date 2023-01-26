#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
const double PI = 3.14159265359;
using namespace std;
const int N = 5e5 + 10;
int a[N], tr[N];
map<int, int> r;
int n;
int bitwise(int x) { return x & -x; }
void add(int x, int c) {
  for (int i = x; i <= n; i += bitwise(i)) {
    tr[i] += c;
  }
}
int sum(int x) {
  int ans = 0;
  for (int i = x; i >= 1; i -= bitwise(i)) {
    ans += tr[i];
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    r.clear();
    cin >> n;
    int maxn = 0;
    int flag = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      maxn = max(a[i], maxn);
      r[a[i]]++;
      if (r[a[i]] > 1) flag = 1;
    }
    if (flag == 1) {
      cout << "YES"
           << "\n";
      continue;
    }
    for (int i = 1; i <= n; i++) {
      ans += sum(n) - sum(a[i] - 1);
      add(a[i], 1);
    }
    if (ans % 2 == 0) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
    for (int i = 0; i <= maxn; i++) {
      tr[i] = 0;
    }
  }
}
