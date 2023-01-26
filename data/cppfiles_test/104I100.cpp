#include <bits/stdc++.h>
using namespace std;
void fio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  fio();
  int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    vector<pair<long long int, long long int> > vec(n);
    long long int k = n * m;
    for (int i = 0; i < n; i++) {
      cin >> vec[i].first >> vec[i].second;
      k += (vec[i].first - vec[i].second);
    }
    vector<pair<long long int, long long int> > temp(n);
    long long int mn = 0, mx = 0;
    for (int i = 0; i < n; i++) {
      temp[i].second = min(m, vec[i].first);
      temp[i].first = max(0LL, m - vec[i].second);
      mn += temp[i].first;
      mx += temp[i].second;
    }
    mn *= 2, mx *= 2;
    long long int eat = 0;
    if (k >= mx) {
      eat = mx;
    } else if (k <= mn) {
      eat = mn;
    } else {
      if (k % 2 == 0)
        eat = k;
      else
        eat = k - 1;
    }
    long long int diff = abs(k - eat);
    cout << diff << "\n";
    vector<long long int> ans(n, 0);
    long long int sum = 0;
    eat /= 2;
    for (int i = 0; i < n; i++) {
      ans[i] = temp[i].first;
      sum += ans[i];
    }
    for (int i = 0; i < n; i++) {
      long long int v = temp[i].second - temp[i].first;
      if (sum + v <= eat) {
        sum += v;
        ans[i] += v;
      } else if (sum + v > eat) {
        sum = eat;
        ans[i] += (eat - sum);
      }
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " " << m - ans[i] << "\n";
    }
  }
  return 0;
}
