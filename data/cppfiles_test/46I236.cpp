#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int b[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    long long a[n + 1];
    a[0] = 0;
    long long r, maxi = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] >= maxi) {
        maxi = a[i];
        r = i;
      }
    }
    if (a[n] == maxi)
      cout << "0"
           << "\n";
    else {
      long long cnt = 1;
      vector<long long> v;
      for (int i = r; i <= n; i++) {
        if (a[i] < maxi && a[i] > a[n]) v.push_back(a[i]);
      }
      if (v.size() == 1)
        cnt++;
      else if (v.size() == 0)
        cnt = cnt;
      else {
        for (int i = 0; i < v.size() - 1; i++) {
          if (v[i] < maxi && v[i] > v[v.size() - 1] && b[v[i]] == 0) {
            cnt++;
            b[v[i]]++;
          }
        }
        cnt++;
      }
      cout << cnt << "\n";
    }
  }
  return 0;
}
