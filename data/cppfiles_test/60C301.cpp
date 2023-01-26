#include <bits/stdc++.h>
using namespace std;
bool check(long long int d1, long long int d2,
           vector<vector<long long int> > &days) {
  long long int n = days.size();
  set<long long int> day1;
  set<long long int> day2;
  set<long long int> intersection;
  for (long long int i = 0; i < n; ++i) {
    bool f1 = false;
    bool f2 = false;
    if (days[i][d1] == 1) {
      f1 = true;
    }
    if (days[i][d2] == 1) {
      f2 = true;
    }
    if ((f1) && (!f2)) {
      day1.insert(i);
    }
    if ((!f1) && (f2)) {
      day2.insert(i);
    }
    if (f1 && f2) {
      intersection.insert(i);
    }
  }
  if (day1.size() >= n / 2 && day2.size() >= n / 2) {
    return true;
  }
  if (day1.size() + day2.size() + intersection.size() == n) {
    if (day1.size() + intersection.size() >= n / 2 &&
        day2.size() + intersection.size() >= n / 2) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int T;
  cin >> T;
  while (T--) {
    long long int n;
    cin >> n;
    vector<double> a(n, 0);
    double sum = 0;
    for (long long int i = 0; i < n; ++i) {
      cin >> a[i];
      sum += a[i];
    }
    double mean = sum / n;
    sort(a.begin(), a.end());
    long long int i = 0;
    long long int j = n - 1;
    long long int ans = 0;
    while (i < j && i <= n - 1 && j >= 0) {
      if (((double)(sum - a[i] - a[j])) / ((double)(n - 2)) == mean) {
        if (a[i] == a[j]) {
          long long int len = j - i + 1;
          ans += (len * (len - 1)) / 2;
          break;
        }
        long long int aage = i;
        long long int piche = j;
        long long int ac = 0;
        long long int pc = 0;
        while (a[aage] == a[i] && aage < j) {
          ac++;
          aage++;
        }
        while (a[piche] == a[j] && piche >= aage) {
          pc++;
          piche--;
        }
        i = aage;
        j = piche;
        ans += (ac * pc);
      } else {
        if (((double)(sum - a[i] - a[j])) / ((double)(n - 2)) > mean) {
          i++;
        } else {
          j--;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
