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
  long long k = 0;
  long long m = 0;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      cout << dis[k] << " ";
      k++;
    } else {
      cout << lik[m] << " ";
      m++;
    }
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
