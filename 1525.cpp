#include <cstdio>
#include <string>
#include <queue>
#include <set>
using namespace std;
int d_zero[4] = {1, -1, 3, -3};
int d_row[4] = {0, 0, 1, -1};
int d_col[4] = {1, -1, 0, 0};

int main()
{
	string start_state = "";
	string dest_state = "123456780";
	int n, ans = 0;
	for(int i = 0 ; i < 9; ++i)
	{
		scanf("%d", &n);
		start_state += n + '0';
	}
	set<string> check;
	check.insert(start_state);
	queue<string> q;
	q.push(start_state);

	while(!q.empty())
	{
		int q_size = q.size();
		for(int i = 0 ; i < q_size; ++i)
		{
			string curr_state = q.front();
			q.pop();
			if(curr_state == dest_state)
			{
				printf("%d\n", ans);
				return 0;
			}
			
			int pos0 = 0;
			for(; curr_state[pos0] != '0'; pos0++)
				;
			int curr_row = pos0/3;
			int curr_col = pos0%3;

			for(int j = 0; j < 4; ++j)
			{
				int next_row = curr_row + d_row[j];
				int next_col = curr_col + d_col[j];
				if(next_row < 0 || next_col < 0 || next_row >= 3 || next_col >= 3)
					continue;
				string next_state = curr_state;
				swap(next_state[pos0], next_state[pos0 + d_zero[j]]);

				if(check.find(next_state) == check.end())
				{
					check.insert(next_state);
					q.push(next_state);
				}
			}
		}
		ans++;
	}
	printf("-1\n");
	return 0;
}