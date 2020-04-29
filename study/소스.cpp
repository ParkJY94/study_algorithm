#include<iostream>
#include<vector>


using namespace std;

vector<int> getPi(string str)
{
	int len = str.size();
	vector<int> pi(len);

	int j = 0;

	for (int i = 1; i < len; i++)
	{
		if (str[i] == str[j])
		{
			pi[i] = ++j;
		}
		while (j > 0 && str[i] != str[j])
		{
			j = pi[j-1];
		}
	}
	
	return pi;
}
void kmp(string main, string compare)
{
	vector<int> pi = getPi(compare);

	int mainSize = main.size();
	int compareSize = compare.size();
	int j = 0;

	for (int i = 0; i < mainSize ; i++)
	{
		while (j > 0 && main[i] != compare[j])
		{
			j = pi[j - 1];
		}
		if (main[i] == compare[j])
		{
			if (j == compareSize -1 )
			{
				cout << i - compareSize +2 << "번째 에서 찾았습니다." << endl;
			}
			else
				j++;
		}
		
	}
}


int main()
{
	string str = "abaababbac";
	string str1 = "babbac";

	kmp(str, str1);

	return 0;
}