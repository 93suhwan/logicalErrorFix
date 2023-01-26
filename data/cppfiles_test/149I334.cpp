#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  srand(time(NULL));
  ;
  int T = 1;
  cin >> T;
  while (T--) {
    int n, k;
    long long int x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    vector<long long int> v;
    for (int i = 0; i < int(n); i++) {
      if (s[i] == 'a')
        v.push_back(-1);
      else {
        int j = i + 1;
        while (j < n && s[j] != 'a') j++;
        v.push_back(1ll * k * (j - i));
        i = j - 1;
      }
    }
    n = int((v).size());
    int j = n;
    long long int m = 1, xx = x;
    for (int i = n - 1; i >= 0; i--)
      if (v[i] > 0) {
        if (xx < v[i] + 1) {
          j = i;
          break;
        } else
          xx = (xx - 1) / (v[i] + 1), m *= v[i] + 1;
      }
    for (int i = 0; i < int(j); i++)
      if (v[i] > 0) v[i] = 0;
    if (j < n) v[j] = (x - 1) / m;
    long long int y = (x - 1) % m + 1;
    for (int i = j + 1; i <= n - 1; i++)
      if (v[i] > 0) {
        m /= v[i] + 1;
        v[i] = (y - 1) / m;
        y = (y - 1) % m + 1;
      }
    for (int i = 0; i < int(n); i++) {
      if (v[i] < 0)
        cout << "a";
      else
        for (long long int z = 0; z < v[i]; z++) cout << "b";
    }
    cout << endl;
  }
  return 0;
}
