#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    long long int sum = 0;
    for (int i : a) sum += i;
    long long int c = 2 * sum;
    long long int b = n;
    if (c % b != 0) {
      cout << "0\n";
      continue;
    }
    long long int x = c / b;
    int N = 2 * 1e5 + 5;
    map<int, long long int> freq;
    sort(a.begin(), a.end());
    for (int i : a) freq[i]++;
    int i = 0, j = n - 1;
    long long int ans = 0;
    while (i <= j && i != j) {
      long long int num = a[i] + a[j];
      if (num == x) {
        if (a[i] == a[j]) {
          ans += freq[a[i]] * (freq[a[i]] - 1) / 2;
          break;
        }
        ans += freq[a[i]] * freq[a[j]];
        i += freq[a[i]];
        j -= freq[a[j]];
      }
      if (num > x) j--;
      if (num < x) i++;
    }
    cout << ans << "\n";
  }
  return 0;
}
