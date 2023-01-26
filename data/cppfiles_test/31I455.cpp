#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 5;
typedef pair<int, int> pii;
vector<int> p, ans;
void fun() {
    int n = p.size();
    for (int i = 0; i + 1 < n; i += 2) {
        ans.push_back(p[i + 1]);
        ans.push_back(-p[i]);
    }
}
int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        p.clear();
        ans.clear();
        for (int i = 1, x; i <= n; i++) {
            cin >> x;
            p.push_back(x);
        }
        if (n % 2) {
            int x = p.back();
            p.pop_back();
            int y = p.back();
            p.pop_back();
            int z = p.back();
            p.pop_back();
            fun();
            int g = __gcd(abs(x), abs(y));
            int c;
            for (c = 1; c <= 10000; c++) {
                if (c * z % g == 0) {
                    break;
                }
            }
            for (int a = -10000; a <= 10000; a++) {
                if ((a * x + c * z) % y == 0) {
                    int b = (-a * x - c * z) / y;
                    if (abs(b) <= 10000) {
                        ans.push_back(c);
                        ans.push_back(b);
                        ans.push_back(a);
                        break;
                    }
                }
            }
        } else {
            fun();
        }
        for (auto v : ans) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}