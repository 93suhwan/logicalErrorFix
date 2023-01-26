#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int INF = 1e9;
const long long mod = 1e9 + 7;
bool prime[N];
int k, counter[N];
string s;
void precompute() {
  memset(prime, true, sizeof(prime));
  prime[1] = 0;
  for (long long i = 2; i <= 100000; i++) {
    if (prime[i] == false) continue;
    for (long long j = i * i; j <= 100000; j += i) {
      prime[j] = 0;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  precompute();
  int t;
  cin >> t;
  while (t--) {
    cin >> k;
    cin >> s;
    bool g = 0;
    int idx = 0;
    for (int i = 0; i <= 9; i++) counter[i] = 0;
    for (int i = 0; i < k; i++) {
      int x = s[i] - '0';
      counter[x]++;
      if (prime[x] == false) {
        idx = i;
        g = 1;
        break;
      }
    }
    if (g) {
      cout << 1 << '\n';
      cout << s[idx] << '\n';
    } else {
      if (counter[2] > 1) {
        cout << 2 << '\n';
        cout << "22" << '\n';
      } else if (counter[3] > 1) {
        cout << 2 << '\n';
        cout << "33" << '\n';
      } else if (counter[5] > 1) {
        cout << 2 << '\n';
        cout << "55" << '\n';
      } else if (counter[7] > 1) {
        cout << 2 << '\n';
        cout << "77" << '\n';
      } else {
        int full = (1 << k);
        int mini = 1e9;
        int jawaban = 0;
        for (int i = 1; i < full; i++) {
          int byk = 0, z = 0;
          for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
              int x = s[j] - '0';
              byk++;
              z = z * 10 + x;
            }
          }
          if (byk <= mini && prime[z] == false) {
            mini = byk;
            jawaban = z;
          }
        }
        cout << mini << '\n';
        cout << jawaban << '\n';
      }
    }
  }
}
