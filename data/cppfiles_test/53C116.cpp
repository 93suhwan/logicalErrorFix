#include <bits/stdc++.h>
using namespace std;
long long int pw(long long int a, long long int b, long long int m) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return ans % m;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool comp(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.second != b.second) {
    return a.second > b.second;
  } else {
    return a.first > b.first;
  }
}
double rnd(double var) {
  double value = (long long int)(var * 100 + .5);
  return (double)value / 100;
}
long long int const N = (1e6 + 9);
long long int primes[N + 1];
void sieve(vector<long long int>& ans) {
  memset(primes, 0, sizeof(primes));
  primes[2] = 1;
  for (long long int i = 3; i <= N; i += 2) primes[i] = 1;
  for (long long int i = 3; i <= N; i += 2) {
    if (primes[i] == 1) {
      for (long long int j = i * i; j <= N; j += i) {
        primes[j] = 0;
      }
    }
  }
  for (long long int i = 2; i <= N; i++) {
    if (primes[i] == 1) {
      ans.push_back(i);
    }
  }
}
long long int binarysearch(vector<long long int>& arr, long long int p) {
  long long int l = 0, r = arr.size() - 1;
  long long int mid = 0;
  while (l < r) {
    mid = l + (r - l) / 2;
    if (arr[mid] * arr[mid] == p) {
      return mid;
    } else if (arr[mid] * arr[mid] > p) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return -1;
}
void dfs(long long int i, map<long long int, vector<long long int>>& hash,
         vector<long long int>& visited, vector<long long int>& temp) {
  visited[i] = 1;
  temp.push_back(i);
  for (auto x : hash[i]) {
    if (visited[x] == 0) {
      dfs(x, hash, visited, temp);
    }
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    vector<pair<long long int, long long int>> v;
    for (long long int i = 1; i <= n; i++) {
      long long int p;
      cin >> p;
      v.push_back({p, i});
    }
    sort(v.begin(), v.end());
    long long int min_k = 1;
    for (long long int i = 0; i < n - 1; i++) {
      if (v[i + 1].second != 1 + v[i].second) {
        min_k++;
      }
    }
    if (min_k <= k) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
