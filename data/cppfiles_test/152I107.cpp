#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

const int inf = 1e9;
const ll inf64 = 1e18;

struct output {
    int can = 0;
    vector<int> res;

    void print() {
        if (can) {
            cout << "YES\n";
            for (auto x : res)
                cout << x << " ";
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }

    bool operator == (const output& o) const {
        throw;
    }
};

struct input {
    int n;
    vector<int> p;

    input() = default;

    void read() {
        cin >> n;
        p.resize(n);
        for (auto& x : p)
            cin >> x;
    }

    void print() {

    }

    void gen() {
        // use static
    }

    output fast() {
        int lb = -inf, last = -p[0];
        vector<int> res = {last};
        for (int i = 1; i < n; i++) {
            if (-p[i] > last) {
                last = -p[i];
            } else if (p[i] > last) {
                last = p[i];
            } else if (-p[i] > lb) {
                lb = -p[i];
                last = -p[i];
            } else if (p[i] > lb) {
                lb = p[i];
                last = p[i];
            } else {
                return output{0, {}};
            }
            res.push_back(last);
        }
        return output{1, res};
    }

    output slow() {
        return output();
    }
};

void test_case() {
    input in;
    in.read();
    output res = in.fast();
    res.print();
}

void work() {
    int t;
    cin >> t;
    while (t--)
        test_case();
}

void test() {
    for (int t = 1;;t++) {
        input in;
        in.gen();
        input in_fs = in;
        input in_sl = in;
        output fs = in_fs.fast();
        output sl = in_sl.slow();
        if (fs == sl) {
            cout << "OK" << endl;
            fs.print();
            cout << "\n=========" << endl;
        } else {
            cout << "WA " << t << "\n";
            cout << "exp\n";
            sl.print();
            cout << "\n=========\n";
            cout << "fnd\n";
            fs.print();
            cout << "\n=========\n";
            in.print();
            break;
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}
