#include <bits/stdc++.h>
using namespace std;
const long long modd = (1000LL * 1000LL * 1000LL + 7LL);
bool is_possible(vector<int> a, int shift, int m) {
  for (auto& x : a) {
    x -= shift;
    if (x < 0) {
      x += a.size();
    }
  }
  set<int> done;
  int a2 = 0;
  for (int i = (0); i < (0) + (a.size()); ++i) {
    if ((done.find((i)) != done.end())) {
      continue;
    }
    done.insert(i);
    int curr = a[i], ct = 0;
    while (curr != i) {
      done.insert(curr);
      curr = a[curr];
      ++ct;
    }
    a2 += ct;
  }
  return a2 <= m;
}
int main(int argc, char* argv[]) {
  mt19937 rang(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> rand_gen(0, modd);
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(12);
  int test_cases;
  cin >> test_cases;
  for (int t = (1); t < (1) + (test_cases); ++t) {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> p;
    for (int i = (0); i < (0) + (n); ++i) {
      int aa;
      cin >> aa;
      p.push_back(aa - 1);
    }
    vector<int> ans;
    if (n < 30) {
      for (int shift = (0); shift < (0) + (n); ++shift) {
        if (is_possible(p, shift, m)) {
          ans.push_back(shift);
        }
      }
    } else {
      map<int, int> freq;
      for (int i = (0); i < (0) + (p.size()); ++i) {
        int shift = p[i] - i;
        if (shift < 0) {
          shift += n;
        }
        shift %= n;
        ++freq[shift];
      }
      set<int> candidates;
      auto it = freq.begin();
      int cc = 0;
      while ((it != freq.end()) && (cc < 5)) {
        ++cc;
        candidates.insert(it->first);
        candidates.insert((n - it->first) % n);
        ++it;
      }
      for (auto x : candidates) {
        if (is_possible(p, x, m)) {
          ans.push_back(x);
        }
      }
    }
    for (auto& x : ans) {
      x = (n - x) % n;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << " ";
    for (auto x : ans) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
