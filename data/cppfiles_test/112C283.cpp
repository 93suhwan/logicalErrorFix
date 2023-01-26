#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, c, m;
    cin >> a >> b >> c >> m;
    long long int aa, bb, cc;
    aa = a;
    bb = b;
    cc = c;
    if (aa) aa--;
    if (bb) bb--;
    if (cc) cc--;
    long long int maxx = aa + bb + cc;
    vector<long long int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(), v.end());
    long long int low = v[2] - v[1] - v[0] - 1;
    if (m > maxx) {
      cout << "NO" << endl;
    } else if (m < low) {
      cout << "NO" << endl;
    } else
      cout << "YES" << endl;
  }
  return 0;
}
