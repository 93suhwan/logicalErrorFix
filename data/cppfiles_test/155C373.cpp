#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  string s;
  cin >> s;
  vector<long long> lik;
  vector<long long> dis;
  for (long long i = 0; i < n; i++)
    if (s[i] == '0')
      dis.push_back(a[i]);
    else
      lik.push_back(a[i]);
  sort(lik.begin(), lik.end());
  sort(dis.begin(), dis.end());
  reverse(dis.begin(), dis.end());
  if (dis.size() == 0) {
    for (long long i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return;
  }
  for (long long i = 0; i < min(lik.size(), dis.size()); i++) {
    if (lik[i] < dis[i]) {
      swap(lik[i], dis[i]);
    }
  }
  sort(lik.begin(), lik.end());
  sort(dis.begin(), dis.end());
  map<long long, long long> m;
  long long k = 0;
  long long mp = 0;
  vector<long long> v1, v0;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      v1.push_back(a[i]);
    } else
      v0.push_back(a[i]);
  }
  sort(v1.begin(), v1.end());
  sort(v0.begin(), v0.end());
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      m[v1[k]] = lik[k];
      k++;
    } else {
      m[v0[mp]] = dis[mp];
      mp++;
    }
  }
  for (long long i = 0; i < s.size(); i++) {
    cout << m[a[i]] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
