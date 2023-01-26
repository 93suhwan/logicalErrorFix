#include <bits/stdc++.h>
using namespace std;
long long a, ns, ni, ps, pi, b[200005], x[200005];
pair<long long, long long> sum[200005];
bool cmp(pair<long long, long long> xx, pair<long long, long long> yy) {
  return xx.first > yy.first;
}
int main() {
  cin >> a;
  for (int i = 1; i <= 200000; i++) sum[i].second = i;
  for (int i = 0; i < a; i++) {
    cin >> b[i] >> x[i];
    sum[b[i]].first += x[i];
  }
  sort(sum + 1, sum + 1 + 200000, cmp);
  reverse(sum + 1, sum + 1 + 200000);
  pi = 200001;
  for (int i = 200000; i >= 1; i--) {
    ns += sum[i].first;
    ni = (200000 - i + 1);
    if (ni <= 20) {
      ns = 0;
      for (int j = 0; j < a; j++) {
        for (int k = 200000; k >= i; k--) {
          if (sum[k].second == b[j]) {
            ns += min(ni, x[j]);
            break;
          }
        }
      }
    }
    long long cp1 = ps * ni, cp2 = ns * pi;
    if (cp1 < cp2 || pi == 200001) ps = ns, pi = ni;
  }
  cout << pi << endl;
  for (int i = 200000; i >= 200000 - pi + 1; i--) cout << sum[i].second << " ";
  cout << endl;
  return 0;
}
