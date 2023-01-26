#include <bits/stdc++.h>
using namespace std;

struct RMQ {
    vector<int> a;
    vector<vector<int>> sparseMax, sparseMin;
    int n;
    RMQ(vector<int> arr) {
        a = arr;
        n = arr.size();
        sparseMax.resize(n);
        sparseMin.resize(n);
        for (int i = 0; i < n; i++) {
            sparseMax[i].resize(__lg(n) + 1);
            sparseMax[i][0] = a[i];

            sparseMin[i].resize(__lg(n) + 1);
            sparseMin[i][0] = a[i];
        }

        for (int len = 1; len < __lg(n) + 1; len++) {
            for (int i = 0; i + (1 << (len - 1)) < n; i++) {
                sparseMax[i][len] = max(sparseMax[i][len - 1], sparseMax[(1 << (len - 1)) + i][len - 1]);
                sparseMin[i][len] = min(sparseMin[i][len - 1], sparseMin[(1 << (len - 1)) + i][len - 1]);
            }
        }
    }

    int queryMax(int l, int r) {
        if (l > r) return 0;
        int k = __lg(r - l + 1);
        return max(sparseMax[l][k], sparseMax[r - (1 << k) + 1][k]);
    }

    int queryMin(int l, int r) {
        int k = __lg(r - l + 1);
        return min(sparseMin[l][k], sparseMin[r - (1 << k) + 1][k]);
    }

    // find Max, Min, Gcd
};

struct Number {
    int a, b, idx;

    bool operator < (const Number &x) {
        return a < x.a;
    }
};

Number x[100005];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); 
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> x[i].a;
        }
        for (int i = 1; i <= n; i++) {
            cin >> x[i].b;
            x[i].idx = i;
        }

        string s;
        for (int i= 1; i <= n; i++) s += '0';

        sort(x + 1, x + n + 1);

        vector<int> y(n + 1);
        for (int i = 1; i <= n; i++) {
            y[i] = x[i].b;
        }

        RMQ rmq(y);

        s[x[n].idx - 1] = '1';
        for (int i = 1; i < n; i++) {
            int max1 = rmq.queryMax(1, i);
            int max2 = rmq.queryMax(i + 1, n);

            if (max1 > max2) {
                s[x[i].idx - 1] = '1';
            }
        }

        for (int i = 1; i <= n; i++) {
            swap(x[i].a, x[i].b);
        }

        sort(x + 1, x + n + 1);

        for (int i = 1; i <= n; i++) {
            y[i] = x[i].b;
        }

        RMQ rmq2(y);

        s[x[n].idx - 1] = '1';
        for (int i = 1; i < n; i++) {
            int max1 = rmq2.queryMax(1, i);
            int max2 = rmq2.queryMax(i + 1, n);

            if (max1 > max2) {
                s[x[i].idx - 1] = '1';
            }
        }

        cout << s << "\n";
    }

    return 0;
}