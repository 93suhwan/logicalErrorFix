#include <bits/stdc++.h>
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
long long getPairsCount(int arr[], int n, long long sum) {
  unordered_map<int, int, custom_hash> m;
  for (int i = 0; i < n; i++) m[arr[i]]++;
  long long twice_count = 0;
  for (int i = 0; i < n; i++) {
    twice_count += m[sum - arr[i]];
    if (sum - arr[i] == arr[i]) twice_count--;
  }
  return twice_count / 2;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ara[n];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> ara[i];
      sum += ara[i];
    }
    sum *= 2;
    if (sum % n) {
      cout << "0\n";
      continue;
    }
    cout << getPairsCount(ara, n, sum / n) << endl;
  }
}
