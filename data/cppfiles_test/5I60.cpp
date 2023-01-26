#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, count = 0;
    cin >> n;
    string enemy, p;
    cin >> enemy >> p;
    if (p[0] == '1' && (enemy[0] == '0' || enemy[1] == '1')) count++;
    if (p[n - 1] == '1' && (enemy[n - 1] == '0' || enemy[n - 2] == '1'))
      count++;
    for (long long i = 1; i < n - 1; i++) {
      if (p[i] == '1') {
        if (enemy[i] == '0' || enemy[i + 1] == '1' || enemy[i - 1] == '1')
          count++;
      }
    }
    cout << count << '\n';
  }
  return 0;
}
