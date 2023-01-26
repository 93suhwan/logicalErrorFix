#include <bits/stdc++.h>
using namespace std;
void print(vector<long long int> &a, long long int s, long long int e) {
  for (long long int i = s; i <= e - 1; i++) {
    cout << a[i] << " ";
  }
  cout << a[e];
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> maxb_of_can_defeat(n, 0), maxb_of_cannot_defeat(n, 0);
  vector<pair<long long int, long long int> > a(n), b(n);
  for (long long int i = 0; i <= n - 1; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  vector<long long int> tempb(n);
  for (long long int i = 0; i <= n - 1; i++) {
    cin >> b[i].first;
    b[i].second = i;
    tempb[i] = b[i].first;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<bool> covered(n, false);
  long long int pointer = n - 1;
  long long int current_max_in_can_defeat = 0;
  for (long long int i = 0; i <= n - 1; i++) {
    if (tempb[a[i].second] > current_max_in_can_defeat) {
      current_max_in_can_defeat = tempb[a[i].second];
    }
    maxb_of_can_defeat[a[i].second] = current_max_in_can_defeat;
    covered[a[i].second] = true;
    while (pointer >= 0 and covered[b[pointer].second]) {
      pointer--;
    }
    maxb_of_cannot_defeat[a[i].second] = ((pointer < 0) ? 0 : b[pointer].first);
  }
  for (long long int i = 0; i <= n - 1; i++) {
    if (maxb_of_can_defeat[i] > maxb_of_cannot_defeat[i]) {
      cout << "1";
    } else {
      cout << "0";
    }
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
