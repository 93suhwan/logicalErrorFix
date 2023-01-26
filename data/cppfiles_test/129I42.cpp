#include <bits/stdc++.h>
using namespace std;
bool prime(long long int a) {
  if (a == 1) {
    return false;
  } else {
    for (long long int i = 2; i * i <= a; i++) {
      if (a % i == 0) {
        return false;
      }
    }
    return true;
  }
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n];
    map<long long int, long long int> mp;
    map<long long int, long long int> m;
    for (long long int i = 1; i <= n; i++) {
      m[i]++;
    }
    map<long long int, long long int> mop;
    vector<long long int> v;
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
      if (m.find(arr[i]) != m.end()) {
        mop[arr[i]]++;
        m.erase(arr[i]);
      } else {
        v.push_back(arr[i]);
      }
    }
    vector<long long int> vec;
    for (auto &x : m) {
      vec.push_back(x.first);
    }
    if (v.size() == 0) {
      cout << "0" << endl;
    } else {
      sort(v.begin(), v.end());
      if (v[0] == '1') {
        cout << "-1" << endl;
      } else {
        long long int d = 0;
        int flag = 0;
        for (long long int i = 0; i < v.size(); i++) {
          long long int g = v[i] - vec[i];
          if (v[i] > vec[i] && v[i] % g != 0) {
            d++;
          } else {
            flag = 1;
          }
        }
        if (flag == 0) {
          cout << d << endl;
        } else {
          cout << "-1" << endl;
        }
      }
    }
  }
  return 0;
}
