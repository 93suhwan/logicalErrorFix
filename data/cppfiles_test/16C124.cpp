#include <bits/stdc++.h>
using namespace std;
int bs(int i, int j, pair<int, int> a[], int target) {
  if (i == j) return a[i].second;
  int mid = (i + j) / 2;
  if (target <= a[mid].first)
    return bs(i, mid, a, target);
  else
    return bs(mid + 1, j, a, target);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string second, s1;
    long long k = 0;
    cin >> second;
    s1 = second;
    sort(s1.begin(), s1.end());
    for (long long i = 0; i < n; i++)
      if (second[i] != s1[i]) k++;
    cout << k << "\n";
  }
  return 0;
}
