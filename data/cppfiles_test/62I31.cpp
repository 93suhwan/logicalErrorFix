#include <bits/stdc++.h>
#include <random>

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
#define en "\n"
#define FOR(i, j, n) for(int j = i; j < n; ++j)
#define forn(i, j, n) for(int j = i; j <= n; ++j)
#define nfor(i, j, n) for(int j = n; j >= i; --j)
#define sortv(vv) sort(vv.begin(), vv.end())
#define all(v) v.begin(), v.end()
#define ld long double
#define ull unsigned long long

void file()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
}

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
const int maxn=6e5+10,LOG=20,mod=1e9+7;
ll block = 300, timer = 0;
const ld eps = 1e-9;

#define bt(i) (1 << (i))
#define int ll
const int inf = 1e9;
#define y1 yy
#define pii pair <int, int>

int n, m, q, ans, lef[1010][1010], rig[1010][1010], up[1010][1010], down[1010][1010];
int c[1010][1010];

void diag(int di, int l, int r, int val, char ch)
{
	if(ch == 'l' || ch == 'u')
		forn(l, j, r)
		{
			int i = di + j;
			if(i < 1) continue;
			if(c[i][j] == 1 || i > n) break;
			if(ch == 'l') lef[i][j] += val;
			if(ch == 'r') rig[i][j] += val;
			if(ch == 'u') up[i][j] += val;
			if(ch == 'd') down[i][j] += val;
		}
	else
		nfor(l, j, r)
		{
			int i = di + j;
			if(i > n) continue;
			if(c[i][j] == 1 || i < 1) break;
			if(ch == 'l') lef[i][j] += val;
			if(ch == 'r') rig[i][j] += val;
			if(ch == 'u') up[i][j] += val;
			if(ch == 'd') down[i][j] += val;
		}
}

main()
{
	//start to down
	//start to rig
	//ends from up
	//ends from lef
	cin >> n >> m >> q;
	forn(1, i, n)
	{
		forn(1, j, m)
		{
			down[i][j] = min(n - i, m - j) * 2 + (n - i != min(n - i, m - j)) + 1;
			rig[i][j] = min(n - i, m - j) * 2 + (m - j != min(n - i, m - j)) + 1;
			lef[i][j] = min(i - 1, j - 1) * 2 + (j - 1 != min(i - 1, j - 1)) + 1;
			up[i][j] = min(i - 1, j - 1) * 2 + (i - 1 != min(i - 1, j - 1)) + 1;
			ans += rig[i][j] + down[i][j] - 1;
		}
	}
	/*cout << ans << endl;
	forn(1, i, n)
	{
		forn(1 ,j, m)cout << down[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	forn(1, i, n)
	{
		forn(1 ,j, m)cout << up[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	forn(1, i, n)
	{
		forn(1 ,j, m)cout << lef[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	forn(1, i, n)
	{
		forn(1 ,j, m)cout << rig[i][j] << " ";
		cout << endl;
	}
	cout << endl;*/
	forn(1, iter, q)
	{
		int i, j;
		cin >> i >> j;
		if(!c[i][j])
		{
			int l = lef[i][j];
			int r = rig[i][j];
			int d = down[i][j];
			int u = up[i][j];
			ans -= l * d + r * u - 1;
			diag(i - j, j, m, -l, 'l');
			diag(i - j + 1, j, m, -l, 'u');
			diag(i - j, j, m, -u, 'u');
			diag(i - j - 1, j + 1, m, -u, 'l');
			diag(i - j, 1, j, -d, 'd');
			diag(i - j, 1, j, -r, 'r');
			diag(i - j + 1, 1, j - 1, -d, 'r');
			diag(i - j - 1, 1, j, -r, 'd');
			c[i][j] ^= 1;
			
		}
		else
		{
			c[i][j] ^= 1;
			int l = up[i][j - 1] + 1;
			int r = down[i][j + 1] + 1;
			int d = rig[i + 1][j] + 1;
			int u = lef[i - 1][j] + 1;
			ans += l * d + r * u - 1;
			diag(i - j, j, m, l, 'l');
			diag(i - j + 1, j, m, l, 'u');
			diag(i - j, j, m, u, 'u');
			diag(i - j - 1, j + 1, m, u, 'l');
			diag(i - j, 1, j, d, 'd');
			diag(i - j, 1, j, r, 'r');
			diag(i - j + 1, 1, j - 1, d, 'r');
			diag(i - j - 1, 1, j, r, 'd');
		}
		cout << ans << endl;
		/*forn(1, i2, n)
		{
			forn(1, j2, m) cout << c[i2][j2] << " ";
			cout << endl;
		}
		cout << endl;
		forn(1, i, n)
		{
			forn(1 ,j, m)cout << down[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		forn(1, i, n)
		{
			forn(1 ,j, m)cout << up[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		forn(1, i, n)
		{
			forn(1 ,j, m)cout << lef[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		forn(1, i, n)
		{
			forn(1 ,j, m)cout << rig[i][j] << " ";
			cout << endl;
		}
		cout << endl;*/
	}
}