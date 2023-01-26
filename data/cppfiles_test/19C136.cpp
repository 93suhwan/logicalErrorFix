#include <bits/stdc++.h>
using namespace std;
bool amrit(long long int a[], long long int index, long long int anim,
           long long int lal, long long int xyz, long long int n) {
  if (index >= n) return false;
  if (anim == lal) return true;
  if (index == xyz) {
    return (amrit(a, index + 1, anim, lal, xyz, n));
  }
  return (amrit(a, index + 1, anim, lal, xyz, n) ||
          amrit(a, index + 1, anim + a[index], lal, xyz, n) ||
          amrit(a, index + 1, anim - a[index], lal, xyz, n));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n, i;
    cin >> n;
    long long int a[n];
    map<long long int, long long int> anii;
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (i = 0; i < n; i++) {
      anii[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
      if (amrit(a, 0, 0, a[i], i, n)) {
        sum = true;
        break;
      }
    }
    if (!sum)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
