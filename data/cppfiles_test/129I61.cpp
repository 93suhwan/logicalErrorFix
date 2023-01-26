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
	while (t--)
	{
		ll n;cin >> n;
		vector < ll > v(n + 1), ch, x(n + 1);
		ll a = 0, b = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> v[i];
			if (v[i] <= n)
			{
				a++;
				x[v[i]] = 1;
			}
			else
			{
				ch.push_back(v[i]);
			}
		}
		sort(ch.begin(), ch.end());
		for (int i = 1;i <= n;i++)
		{
			if (!x[i])
			{
				auto z = upper_bound(ch.begin(), ch.end(), i * 2);
				if (z == ch.end())
				{
					cout << "-1" << endl;
					goto mk;
				}
				ch.erase(z, z + 1);
			}
		}
		cout << n - a << endl;
	mk:;
	}
	return 0;
}