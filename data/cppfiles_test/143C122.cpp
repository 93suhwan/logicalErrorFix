#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int long long, int long long> &a,
          const pair<int long long, int long long> &b) {
  int long long val1 = a.first - a.second;
  int long long val2 = b.first - b.second;
  if (val1 > val2) {
    return true;
  } else {
    return false;
  }
}
int long long gcd(int long long a, int long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int long long binpow(int long long a, int long long b, int long long m) {
  if (b == 0) return 1;
  int long long res = binpow(a, b / 2, m);
  if (b % 2)
    return (res % m * res % m * a % m) % m;
  else
    return (res % m * res % m) % m;
}
int long long be_rec(int long long x, int long long n) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return be_rec((x * x), n / 2);
  }
  return x * be_rec(x * x, (n - 1) / 2);
}
int long long lcm(int long long a, int long long b) {
  return ((a / gcd(a, b)) * b);
}
int long long modInv(int long long i, int long long m) {
  return binpow(i, m - 2, m);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int long long tt;
  cin >> tt;
  for (int ic = 1; ic <= tt; ic++) {
    int long long num;
    cin >> num;
    int long long arr[num];
    map<int long long, int long long> m;
    for (int i = 0; i < num; i++) {
      cin >> arr[i];
      m[arr[i]]++;
    }
    sort(arr, arr + num);
    vector<int long long> form(num, 2147483647);
    multiset<int long long> s;
    for (int i = 0; i < num; i++) {
      s.insert(-1 * arr[i]);
    }
    for (int i = 0; i < num; i++) {
      auto it = s.find(-1 * i);
      if (it != s.end()) {
        s.erase(it);
        form[i] = 0;
      }
    }
    int long long mex = num;
    for (int i = 0; i < num; i++) {
      if (form[i] == 2147483647) {
        mex = i;
        break;
      }
    }
    for (int i = 0; i < num; i++) {
      if (form[i] == 2147483647) {
        auto it = s.lower_bound(-i);
        if (it == s.end()) {
          break;
        } else {
          form[i] = abs(i + (*it));
          s.erase(it);
        }
      }
    }
    vector<int long long> presum(num, 2147483647);
    int long long sum = 0;
    for (int i = 0; i < num; i++) {
      if (form[i] == 2147483647) {
        break;
      } else {
        sum = sum + form[i];
        presum[i] = sum;
      }
    }
    vector<int long long> ans(num + 1, -1);
    for (int i = 0; i < num + 1; i++) {
      if (i == 0 && i != mex) {
        if (form[0] == 2147483647) {
          ans[0] = -1;
        } else {
          ans[0] = m[arr[i]];
        }
        continue;
      }
      if (i == mex) {
        ans[i] = 0;
      } else if (presum[i - 1] == 2147483647) {
        ans[i] = -1;
      } else {
        ans[i] = m[i] + presum[i - 1];
      }
    }
    for (int i = 0; i < num + 1; i++) {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}
