#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	// sang nguyen to Eratosthenes
	vector<bool> isPrimeNums(n + m + 1, true);
	for (int i = 2; i <= n + m; i++) 
	{
		if (isPrimeNums[i] == true) 
		{
			for (int j = 2 * i; j <= n + m; j += i) 
			{
				isPrimeNums[j] = false;
			}
		}
	}
	cout << "\n";
	int cnt = 0;
	for (int i = 1; i <= m; i++) // dem 2 -> m + 1
	{
		if (isPrimeNums[i + 1])
			cnt++;
	}

	int temp_cnt = cnt;
	for (int i = 2; i <= n; i++) // 2 -> n
	{
		//cout << i + 1 << " & " << m + i << "\n";
		if (isPrimeNums[i])
			temp_cnt--;
		if (isPrimeNums[m + i])
		{
			temp_cnt++;
		}
		cnt += temp_cnt;
	}

	cout << "count = " << cnt;
	cout << "\n";
	system("pause");
	return 0;
}
