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
		vector < ll > v(n + 1), ch(n + 1);
		for (int i = 1;i <= n;i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		ll ans = n;
		for (int i = 1;i <= n;i++)
		{
			if (v[i] == i)
			{
				ans--;
			}
			else
				break;
		}
		for (int i = n - ans + 1;i <= n;i++)
		{
			ll x = min(n, v[i] / 2);
			ch[x]++;
		}
		ll cnt = 0;
		bool ok = 1;
		for (int i = n - ans + 1;i <= n;i++)
		{
			cnt += ch[i];
			if (ch[i])
				ok = 1;
			else
				ok = 0;
		}
		if (cnt+(n-ans)==n&&ok)
		{
			cout << ans << endl;
		}
		else
			cout << "-1" << endl;
	}
	return 0;
}