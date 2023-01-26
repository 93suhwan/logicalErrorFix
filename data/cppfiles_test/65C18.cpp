#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n;
  vector<long long> a(n);
  for (int i = (0); i < (n); i++) cin >> a[i];
  cin >> s;
  int cnt = 0;
  for (int i = (1); i < (n); i++) cnt += (s[i] != s[i - 1]);
  sort((a).begin(), (a).end());
  vector<long long> w(n);
  int j = 0, k = 0;
  for (int i = (0); i < (n); i++) {
    if (i == 0 || (s[i] != s[i - 1])) {
      w[i] = a[n - cnt - 1 + j];
      j++;
    } else {
      k++;
      w[i] = a[n - cnt - 1 - k];
    }
  }
  long long sum = 0;
  for (int i = (0); i < (n); i++) {
    char c = 'L';
    if (i == 0 || (s[i] != s[i - 1]))
      c = s[i];
    else {
      if (w[i] < abs(sum))
        c = s[i] ^ 'L' ^ 'R';
      else
        c = s[i];
    }
    cout << w[i] << ' ' << c << '\n';
    if (c == 'L')
      sum -= w[i];
    else
      sum += w[i];
  }
}
