#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<bool> isPrime(100, true);
void simpleSeive(int range, vector<int> &prime) {
  isPrime[0] = isPrime[1] = false;
  for (int n = 2; n * n <= range; n++) {
    if (isPrime[n] == true) {
      for (int i = n * n; i <= range; i += n) isPrime[i] = false;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  vector<int> prime;
  simpleSeive(100, prime);
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    int k, val = 0;
    cin >> k;
    string n;
    cin >> n;
    int flag = 0;
    for (int i = 0; i < k; i++) {
      if (!isPrime[n[i] - '0']) {
        cout << "1" << '\n' << n[i] << '\n';
        break;
      }
      for (int j = i + 1; j < k; j++) {
        if (!isPrime[(n[i] - '0') * 10 + (n[j] - '0')]) {
          cout << "2" << '\n' << n[i] << n[j] << '\n';
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
  }
  return 0;
}
