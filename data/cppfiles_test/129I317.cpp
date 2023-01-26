/*
MMMMMMMM               MMMMMMMM        KKKKKKKKK    KKKKKKK
M:::::::M             M:::::::M        K:::::::K    K:::::K
M::::::::M           M::::::::M        K:::::::K    K:::::K
M:::::::::M         M:::::::::M        K:::::::K   K::::::K
M::::::::::M       M::::::::::M        KK::::::K  K:::::KKK
M:::::::::::M     M:::::::::::M          K:::::K K:::::K
M:::::::M::::M   M::::M:::::::M          K::::::K:::::K
M::::::M M::::M M::::M M::::::M          K:::::::::::K
M::::::M  M::::M::::M  M::::::M          K:::::::::::K
M::::::M   M:::::::M   M::::::M          K::::::K:::::K
M::::::M    M:::::M    M::::::M          K:::::K K:::::K
M::::::M     MMMMM     M::::::M        KK::::::K  K:::::KKK
M::::::M               M::::::M        K:::::::K   K::::::K
M::::::M               M::::::M ...... K:::::::K    K:::::K
M::::::M               M::::::M .::::. K:::::::K    K:::::K
MMMMMMMM               MMMMMMMM ...... KKKKKKKKK    KKKKKKK
*/
#include <bits\stdc++.h>

using namespace std;

#define ll long long
#define dd double

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
//-------------------------//

	int t;cin >> t;
	bool te = (t == 100) ? 1 : 0;
	while (t--)
	{
		ll n;cin >> n;
		vector<ll>v(n + 1);
		set<ll>s;
		for (int i = 1;i <= n;i++)
		{
			ll x;cin >> x;
			if (x <= n)
			{
				s.insert(x);
				v[x]++;
			}
			else
			{
				ll y = min(ceil((dd)x / (dd)2) - 1, (dd)n);
				v[y]++;
			}

		}
		if (te && t == 69)
		{
			for (int i = 1;i <= n;i++)
				cout << v[i] << " ";
			cout << endl;
		}
		bool ok = 1;
		for (int i = 1;i <= n;i++)
		{
			if (!v[i])
			{
				bool q = 0;
				for (int j = i + 1;j <= n;j++)
				{
					if (v[j])
					{
						v[j]--;
						q = 1;
						break;
					}
				}
				if (!q)
				{
					ok = 0;
					break;
				}
			}
		}
		if (ok)
		{
			cout << n - s.size() << endl;
		}
		else
			cout << "-1" << endl;
	}
	return 0;
}