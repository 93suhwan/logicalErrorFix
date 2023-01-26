#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int test;
  cin >> test;
  while (test--) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> p, ne;
    for (int i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      if (x > 0)
        p.push_back(x);
      else
        ne.push_back(-x);
    }
    sort(p.begin(), p.end());
    sort(ne.begin(), ne.end());
    if (p.size() == 0) {
      long long int ans = 0;
      long long int i = ne.size() - 1;
      ans += ne[i];
      i -= k;
      while (i >= 0) {
        ans += 2 * ne[i];
        i -= k;
      }
      cout << ans << endl;
    } else if (ne.size() == 0) {
      long long int ans = 0;
      long long int i = p.size() - 1;
      ans += p[i];
      i -= k;
      while (i >= 0) {
        ans += 2 * p[i];
        i -= k;
      }
      cout << ans << endl;
    } else {
      if (ne.back() > p.back()) {
        long long int ans = 0;
        long long int i = ne.size() - 1;
        ans += ne[i];
        i -= k;
        while (i >= 0) {
          ans += 2 * ne[i];
          i -= k;
        }
        i = p.size() - 1;
        while (i >= 0) {
          ans += 2 * p[i];
          i -= k;
        }
        cout << ans << endl;
      } else {
        long long int ans = 0;
        long long int i = p.size() - 1;
        ans += p[i];
        i -= k;
        while (i >= 0) {
          ans += 2 * p[i];
          i -= k;
        }
        i = ne.size() - 1;
        while (i >= 0) {
          ans += 2 * ne[i];
          i -= k;
        }
        cout << ans << endl;
      }
    }
  }
}
