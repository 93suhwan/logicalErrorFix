#include <bits/stdc++.h>
using namespace std;
const long long int INF = (long long int)1e18;
const long long int MOD = (long long int)1e9 + 7;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long int GCD(long long int a, long long int b) {
  if (b == 0) {
    return a;
  }
  return GCD(b, a % b);
}
long long int LCM(long long int a, long long int b) {
  return (a * b) / GCD(a, b);
}
vector<bool> sieveOfErato(long long int n) {
  vector<bool> isPrime(n + 1, true);
  isPrime[1] = false;
  isPrime[0] = false;
  for (long long int i = 2; i * i <= n; i++) {
    for (long long int j = 2 * i; j <= n; j += i) {
      isPrime[j] = false;
    }
  }
  return isPrime;
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> arr(n);
  for (long long int i = 0; i < n; i++) cin >> arr[i];
  if (arr[0]) {
    cout << n + 1 << " ";
    for (long long int i = 1; i <= n; i++) {
      cout << i << " ";
    }
  } else if (arr[n - 1] != 1) {
    for (long long int i = 1; i <= n + 1; i++) {
      cout << i << " ";
    }
  } else {
    long long int ok = -1;
    for (long long int i = 0; i < n - 1; i++) {
      if (arr[i] == 0 && arr[i + 1] == 1) {
        ok = i + 1;
        break;
      }
    }
    if (ok == -1) {
      cout << -1;
    } else {
      for (long long int i = 1; i <= ok; i++) {
        cout << i << " ";
      }
      cout << n + 1 << " ";
      for (long long int i = ok + 1; i <= n; i++) {
        cout << i << " ";
      }
    }
  }
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs"
       << "\n";
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
