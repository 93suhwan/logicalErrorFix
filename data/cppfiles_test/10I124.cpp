#include <bits/stdc++.h>
using namespace std;
long long t, n, k;
vector<pair<long long, long long> > v;
vector<long long> resp;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    resp = vector<long long>(n);
    for (long long i = 0; i < n; i++) {
      long long num;
      cin >> num;
      v.emplace_back(num, i);
    }
    sort((v).begin(), (v).end());
    long long ant, contatual;
    ant = -1;
    long long validos = 0;
    long long ultimo = 1;
    for (long long i = 0; i < (long long)(v).size(); i++) {
      if (v[i].first == ant) {
        contatual++;
      } else {
        contatual = 1;
      }
      ant = v[i].first;
      if (contatual > k) {
        resp[v[i].second] = 0;
        continue;
      }
      resp[v[i].second] = ultimo;
      ultimo = (ultimo) % k + 1;
    }
    for (long long i = 0; i < n; i++) {
      cout << resp[i] << ' ';
    }
    cout << '\n';
    v.clear();
  }
  return 0;
}
