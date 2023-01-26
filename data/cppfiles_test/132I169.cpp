#include <bits/stdc++.h>
using namespace std;
const long long INF = 1ll << 32;
void fast_stream() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fast_stream();
  int t;
  cin >> t;
  while (t--) {
    map<int, int> make_pair;
    int A[7];
    for (int i = 0; i < 7; i++) {
      cin >> A[i];
      make_pair[A[i]] = 1;
    }
    int i, j, k, flag = 0;
    if (!flag) {
      for (i = 0; i < 7; i++) {
        for (j = i + 1; j < 7; j++) {
          for (k = j + 1; k < 7; k++) {
            int x, y, z;
            x = A[i];
            y = A[j];
            z = A[k];
            if (make_pair[x + y] == 1 && make_pair[x + z] == 1 &&
                make_pair[y + z] == 1 && make_pair[x + y + z] == 1 &&
                flag == 0) {
              flag = 1;
              cout << x << " " << y << " " << z << " " << endl;
            }
          }
        }
      }
    }
  }
  return 0;
}
