#include <bits/stdc++.h>
using namespace std;
void DoSomething() {
  int n, cnt = 0;
  cin >> n;
  vector<int> a(n);
  for (int(i) = 0; (i) < (n); (i)++) cin >> a[i];
  while (!is_sorted(a.begin(), a.end())) {
    for (int i = cnt % 2; i < n - 1; i += 2)
      if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
    cnt++;
  }
  cout << cnt << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    DoSomething();
  }
  cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC * 3000 << " ms"
       << endl;
  return 0;
}
