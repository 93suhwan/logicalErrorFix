#include <bits/stdc++.h>
using namespace std;
long long int tab[200005];
void prob() {
  int n;
  long long int k;
  cin >> n >> k;
  long long int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> tab[i];
    sum += tab[i];
  }
  sort(tab, tab + n);
  long long int diff = sum - k;
  if (diff <= 0) {
    cout << "0\n";
    return;
  }
  long long int best = diff;
  long long int cumu_imp = 0;
  for (int l = 1; l <= n - 1; l++) {
    cumu_imp += tab[n - l] - tab[0];
    long long int needed = diff - cumu_imp;
    long long int add_turns = max(0LL, (needed + l) / (l + 1));
    best = min(best, add_turns + l);
  }
  cout << best << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) prob();
  return 0;
}
