#include <bits/stdc++.h>
using namespace std;
long long res[200010];
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, r, k;
    long long a, b, c;
    string str;
    vector<long long> v;
    vector<pair<long long, long long> > vg, vs;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      cin >> a;
      v.push_back(a);
    }
    cin >> str;
    for (long long i = 0; i < n; i++) {
      if (str[i] == '1')
        vg.push_back({v[i], i});
      else
        vs.push_back({v[i], i});
    }
    sort(vg.begin(), vg.end());
    sort(vs.begin(), vs.end());
    long long g = n, l = 1;
    long long siz = vg.size();
    for (long long i = siz - 1; i >= 0; i--) {
      long long ind = vg[i].second;
      res[ind] = g--;
    }
    siz = vs.size();
    for (long long i = 0; i < siz; i++) {
      long long ind = vs[i].second;
      res[ind] = l++;
    }
    for (long long i = 0; i < n; i++) {
      cout << res[i] << " ";
    }
    cout << endl;
  }
}
