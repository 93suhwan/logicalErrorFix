#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  long long int i, j;
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long int neu, ext;
  long long int rem;
  long long int ans = 0;
  bool con;
  for (i = 0; i < n; i = i + 2) {
    neu = v[i];
    ext = 0;
    rem = 0;
    for (j = i + 1; j < n; j++) {
      if (j % 2 == 1) {
        if (ext == 0) {
          rem = v[j];
          if (rem < neu) {
            ans += rem;
            neu -= rem;
          } else {
            if (rem == neu) {
              ans += rem;
              neu -= rem;
            } else {
              ans += neu;
              neu = 0;
              break;
            }
          }
        } else {
          if (v[j] < ext) {
            ext -= v[j];
          } else {
            if (v[j] == ext) {
              ext = 0;
              ans++;
            } else {
              rem = v[j] - ext;
              ext = 0;
              ans++;
              if (rem < neu) {
                ans += rem;
                neu -= rem;
              } else {
                if (rem == neu) {
                  ans += rem;
                  neu -= rem;
                } else {
                  ans += neu;
                  neu = 0;
                  break;
                }
              }
            }
          }
        }
      } else {
        ext += v[j];
      }
    }
  }
  cout << ans << "\n";
}
