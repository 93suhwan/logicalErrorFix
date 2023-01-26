#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
long long int modmul(long long int a, long long int b) {
  return ((a % 1000000007) * (b % 1000000007)) % 1000000007;
}
long long int modadd(long long int a, long long int b) {
  return (((a % 1000000007) + (b % 1000000007))) % 1000000007;
}
long long modExpo(long long a, long long b, long long m) {
  long long result = 1;
  a = a % m;
  while (b > 0) {
    if (b % 2) {
      result = modmul(result, a);
      b--;
    } else {
      a = modmul(a, a);
      b /= 2;
    }
  }
  return result % m;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
class comp {
 public:
  bool operator()(int a, int b) const { return a > b; }
};
bool compa(pair<long long int, long long int> a,
           pair<long long int, long long int> b) {
  return a.first > b.first;
}
void answerNikalBc(long long int t1) {
  long long int n;
  cin >> n;
  vector<long long int> arr(n);
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  string s;
  cin >> s;
  map<pair<long long int, long long int>, long long int> mp;
  vector<pair<long long int, long long int>> rng;
  bool ok = true;
  for (long long int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      if (arr[i] > n) {
        ok = false;
        break;
      } else {
        rng.push_back({max((long long int)1, arr[i]), n});
      }
    } else {
      if (arr[i] < 1) {
        ok = false;
        break;
      } else {
        rng.push_back({1, min(arr[i], n)});
      }
    }
  }
  if (!ok) {
    cout << "NO\n";
    return;
  }
  sort(rng.begin(), rng.end());
  for (long long int i = n - 1; i >= 0; i--) {
    if (!(i + 1 <= rng[i].second && i + 1 >= rng[i].first)) {
      ok = false;
      break;
    }
  }
  ok ? cout << "YES\n" : cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    answerNikalBc(t);
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
