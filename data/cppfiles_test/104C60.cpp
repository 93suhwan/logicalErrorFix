#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    map<int, vector<array<int, 2>>> mp;
    long long bsum = 0, asum = 0;
    long long mn = 0, mx = 0;
    vector<long long> A(n), B(n), remmina(n), remmaxa(n);
    vector<array<long long, 2>> minremaining(n);
    for (int i = 0; i < (int)n; i++) {
      long long a, b;
      cin >> a >> b;
      long long mna = max(0LL, m - b), mxa = min(a, m);
      bsum += b;
      asum += a;
      A[i] = a;
      B[i] = b;
      remmina[i] = a - mxa, remmaxa[i] = a - mna;
      mn += remmina[i];
      mx += remmaxa[i];
      minremaining[i] = {remmina[i], i};
    }
    long long optrema = (asum + bsum - n * m) / 2;
    if (optrema > mx)
      optrema = mx;
    else if (optrema < mn)
      optrema = mn;
    long long optremb = asum + bsum - n * m - optrema;
    cout << llabs(optrema - optremb) << '\n';
    sort(minremaining.rbegin(), minremaining.rend());
    vector<long long> ansa(n), ansb(n);
    vector<array<long long, 2>> maxremaining(n);
    for (auto &v : minremaining) {
      int i = v[1];
      long long take = v[0];
      assert(take <= optrema);
      optrema -= take;
      long long dela = A[i] - take;
      ansa[i] = dela;
      ansb[i] = m - dela;
      maxremaining[i] = {remmaxa[i] - take, i};
    }
    sort(maxremaining.rbegin(), maxremaining.rend());
    for (auto &v : maxremaining) {
      int i = v[1];
      long long take = min(optrema, v[0]);
      assert(take >= 0);
      optrema -= take;
      ansa[i] -= take;
      ansb[i] += take;
    }
    for (int i = 0; i < (int)n; i++) cout << ansa[i] << " " << ansb[i] << '\n';
  }
}
