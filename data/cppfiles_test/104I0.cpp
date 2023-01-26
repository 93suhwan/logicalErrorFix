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
    vector<long long> A(n), B(n);
    vector<array<long long, 2>> minremaining(n);
    for (int i = 0; i < (int)n; i++) {
      long long a, b;
      cin >> a >> b;
      long long mna = max(0LL, m - b), mxa = min(a, m);
      bsum += b;
      asum += a;
      A[i] = a;
      B[i] = b;
      long long remmina = a - mxa, remmaxa = a - mna;
      mn += remmina;
      mx += remmaxa;
      minremaining[i] = {remmina, i};
    }
    long long ans = LLONG_MAX;
    long long optrema = (asum + bsum - n * m) / 2;
    if (optrema > mx)
      optrema = mx;
    else if (optrema < mn)
      optrema = mn;
    long long optremb = asum + bsum - n * m - optrema;
    cout << llabs(optrema - optremb) << '\n';
    sort(minremaining.rbegin(), minremaining.rend());
    vector<long long> ansa(n), ansb(n);
    for (auto &v : minremaining) {
      int i = v[1];
      long long mna = max(0LL, m - B[i]), mxa = min(A[i], m);
      long long remmina = A[i] - mxa, remmaxa = A[i] - mna;
      long long take = max(remmina, min(remmaxa, optrema));
      optrema -= take;
      long long dela = A[i] - take;
      ansa[i] = dela;
      ansb[i] = m - dela;
    }
    for (int i = 0; i < (int)n; i++) cout << ansa[i] << " " << ansb[i] << '\n';
  }
}
