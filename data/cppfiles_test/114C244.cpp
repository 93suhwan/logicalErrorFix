#include <bits/stdc++.h>
using namespace std;
int main() {
  clock_t begin = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 1, num = 0; num < n / 2; i++, num++) {
      cout << a[i] << " " << a[0] << endl;
    }
  }
  return 0;
}
