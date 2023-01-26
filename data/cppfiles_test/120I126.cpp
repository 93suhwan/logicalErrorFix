#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  long long int tc;
  cin >> tc;
  while (tc--) {
    long long int l, r;
    cin >> l >> r;
    long long int max2 = log2(r);
    long long int ch = 1;
    vector<long long int> v(max2 + 1, 0);
    v[0] = (r - l) / 2;
    if (r % 2 || l % 2) v[0]++;
    for (long long int i = 1; i < max2 + 1; i++) {
      ch = ch << 1;
      long long int s = l, e;
      if (s & ch) {
        while (s <= r && s & ch) {
          v[i]++;
          s++;
        }
        e = r;
        if (e & ch) {
          while (e >= s && e & ch) {
            v[i]++;
            e--;
          }
          e -= ch;
        } else {
          while (e >= s && !(e & ch)) {
            e--;
          }
        }
        if (s < e) {
          v[i] += (e - s) / 2;
        }
      } else {
        while (s <= r && !(s & ch)) {
          s++;
        }
        e = r;
        if (e & ch) {
          while (s <= e && e & ch) {
            v[i]++;
            e--;
          }
        } else {
          while (s <= e && !(e & ch)) {
            e--;
          }
          e -= ch;
          v[i] += ch;
        }
        if (s < e) {
          v[i] += (e - s) / 2;
        }
      }
    }
    cout << r - l + 1 - *max_element(v.begin(), v.end()) << "\n";
  }
}
