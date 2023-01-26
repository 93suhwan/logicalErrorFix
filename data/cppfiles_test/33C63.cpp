#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N];
set<int> s;
int f[N];
bool st[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(f, 0x3f, sizeof f);
  for (int i = 1; i <= n; i++) {
    f[a[i]] = min(f[a[i]], a[i]);
    for (int j = 0; j <= 512; j++) {
      if (f[j] != 0x3f3f3f3f && f[j] <= a[i])
        f[j ^ a[i]] = min(f[j ^ a[i]], a[i]);
    }
  }
  for (int i = 0; i <= 511; i++)
    if (f[i] != 0x3f3f3f3f) s.insert(i);
  cout << s.size() << endl;
  for (auto x : s) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
