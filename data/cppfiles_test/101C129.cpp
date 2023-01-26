#include <bits/stdc++.h>
using namespace std;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
template <class T>
void in(T& x) {
  cin >> x;
}
template <class H, class... T>
void in(H& h, T&... t) {
  in(h);
  in(t...);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int T = 1;
  in(T);
  while (T--) {
    long long int n;
    in(n);
    vector<long long int> v(n + 1);
    vector<char> color(n + 1);
    bool can = true;
    for (long long int i = 1; i <= n; ++i) {
      in(v[i]);
    }
    for (long long int i = 1; i <= n; ++i) {
      in(color[i]);
    }
    long long int b1 = 0;
    long long int rn = 0;
    vector<long long int> R;
    vector<long long int> B;
    for (long long int i = 1; i <= n; ++i) {
      if (color[i] == 'B') {
        B.push_back(v[i]);
      }
      if (color[i] == 'R') {
        R.push_back(v[i]);
      }
      if (v[i] < 1 && color[i] == 'B') {
        can = false;
      }
      if (v[i] > n && color[i] == 'R') {
        can = false;
      }
    }
    sort(R.rbegin(), R.rend());
    sort(B.begin(), B.end());
    long long int rMax = n;
    long long int bMin = 1;
    for (long long int i = 0; i < R.size(); ++i) {
      if (R[i] > rMax) {
        can = false;
        break;
      } else {
        rMax--;
      }
    }
    for (long long int i = 0; i < B.size(); ++i) {
      if (B[i] < bMin) {
        can = false;
        break;
      } else {
        bMin++;
      }
    }
    cout << (can ? "YES\n" : "NO\n");
  }
  return 0;
}
