#include <bits/stdc++.h>
using namespace std;
int T;
long long mod;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
      cin >> words[i];
    }
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    vector<int> d(n);
    vector<int> e(n);
    int maxa = 0;
    int maxb = 0;
    int maxc = 0;
    int maxd = 0;
    int maxe = 0;
    for (int i = 0; i < n; i++) {
      string s = words[i];
      vector<int> cnt(5, 0);
      for (int j = 0; j < s.length(); j++) {
        cnt[s[j] - 'a']++;
      }
      int s_len = s.length();
      a[i] = 2 * cnt[0] - s_len;
      b[i] = 2 * cnt[1] - s_len;
      c[i] = 2 * cnt[2] - s_len;
      d[i] = 2 * cnt[3] - s_len;
      e[i] = 2 * cnt[4] - s_len;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    sort(e.begin(), e.end());
    vector<int> sum(5, 0);
    for (int i = n - 1; i > -1; i--) {
      if ((sum[0] + a[i]) > 0) {
        sum[0] += a[i];
        maxa++;
      } else {
        break;
      }
    }
    for (int i = n - 1; i > -1; i--) {
      if ((sum[1] + b[i]) > 0) {
        sum[1] += b[i];
        maxb++;
      } else {
        break;
      }
    }
    for (int i = n - 1; i > -1; i--) {
      if ((sum[2] + c[i]) > 0) {
        sum[2] += c[i];
        maxc++;
      } else {
        break;
      }
    }
    for (int i = n - 1; i > -1; i--) {
      if ((sum[3] + d[i]) > 0) {
        sum[3] += d[i];
        maxd++;
      } else {
        break;
      }
    }
    for (int i = n - 1; i > -1; i--) {
      if ((sum[4] + e[i]) > 0) {
        sum[4] += e[i];
        maxe++;
      } else {
        break;
      }
    }
    int out = 0;
    if (maxa >= maxb && maxa >= maxc && maxa >= maxd && maxa >= maxe) {
      out = maxa;
    } else if (maxb >= maxc && maxb >= maxd && maxb >= maxe) {
      out = maxb;
    } else if (maxc >= maxd && maxc >= maxe) {
      out = maxc;
    } else if (maxd >= maxe) {
      out = maxd;
    } else {
      out = maxe;
    }
    cout << out << endl;
  }
}
