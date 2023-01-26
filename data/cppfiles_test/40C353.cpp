#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    vector<long long int> b(n);
    for (long long int i = 0; i < n; i++) cin >> a[i];
    for (long long int i = 0; i < n; i++) cin >> b[i];
    long long int suma[n], sumb[n];
    for (long long int i = 0; i < n; i++) {
      suma[i] = sumb[i] = 0;
    }
    suma[0] = a[0];
    sumb[0] = b[0];
    for (long long int i = 1; i < n; i++) suma[i] += a[i] + suma[i - 1];
    for (long long int i = 1; i < n; i++) sumb[i] += b[i] + sumb[i - 1];
    long long int maxf = 1e17;
    long long int minmaxf = 1e17;
    for (long long int i = 0; i < n; i++) {
      if (i == 0)
        maxf = suma[n - 1] - suma[i];
      else {
        if (suma[n - 1] - suma[i] < sumb[i - 1])
          maxf = sumb[i - 1];
        else
          maxf = suma[n - 1] - suma[i];
      }
      if (maxf < minmaxf) minmaxf = maxf;
    }
    cout << minmaxf << endl;
  }
}
