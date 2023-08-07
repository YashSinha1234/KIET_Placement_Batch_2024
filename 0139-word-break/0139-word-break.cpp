class Solution {
public:
		vector<string> v;
		int help(string s, int n, vector<string> &word,vector<int> &dp)
		{
			if(dp[n]!=-1)
				return dp[n];
            long long cnt = 0;
			for (int i = 1; i <= n; i++)
			{
				string ss = s.substr(0, i);
				int l = word.size();
				bool flag = false;

				for (int j = 0; j < l; j++)
					if (word[j] == ss)
						flag = true;

				if (flag)
				{
					if (i == n)
					{
						return 1;
					}
					cnt+=help(s.substr(i, n), n - i, word,dp);
				}
			}
			return dp[n]=cnt;
		}

		bool wordBreak(string s, vector<string> &dictionary)
		{
			vector<int> dp(s.length()+1,-1);
			return help(s, s.size(), dictionary,dp);
		}
};