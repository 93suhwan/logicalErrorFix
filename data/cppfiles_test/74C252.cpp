#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int result = power(a, b / 2);
  if (b & 1) return result * result * a;
  return result * result;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    if (a == 0 or b == 0) {
      if (max(a, b) % 2) {
        cout << 2 << "\n";
        cout << max(a, b) / 2 << " " << max(a, b) / 2 + 1 << "\n";
      } else {
        cout << 1 << "\n";
        cout << max(a, b) / 2 << "\n";
      }
    } else {
      long long int gap = abs(a - b);
      if (gap == 1) {
        cout << a + b + 1 << "\n";
        for (long long int i = 0; i <= a + b; i++) {
          cout << i << " ";
        }
        cout << "\n";
      } else if (gap % 2 == 0) {
        vector<long long int> v;
        long long int ans = 0;
        long long int total = (a + b) / 2;
        long long int start = max(a, b) - (a + b) / 2;
        long long int end =
            (a + b) / 2 + ((a + b) / 2 - (max(a, b) - (a + b) / 2));
        for (long long int i = start; i <= end; i += 2) {
          v.push_back(i);
          ans++;
        }
        cout << ans << "\n";
        for (long long int i = 0; i < v.size(); i++) {
          cout << v[i] << " ";
        }
        cout << "\n";
      } else {
        long long int ans1 = 0;
        long long int start = max(a, b) - (a + b) / 2 - 1;
        long long int end = (a + b) / 2 + 1 + (a + b) / 2 - start;
        vector<long long int> v1;
        for (long long int i = start; i <= end; i++) {
          v1.push_back(i);
        }
        cout << v1.size() << "\n";
        for (long long int i = 0; i < v1.size(); i++) {
          cout << v1[i] << " ";
        }
        cout << "\n";
      }
    }
  }
}
