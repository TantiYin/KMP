#include <iostream>
#include <cstring>

using namespace std;

int gStrLen = 0;

bool strNext(char* sStr, int* pNext)
{
	pNext[0] = -1;
	pNext[1] = 0;
	int iMaxLen = 0;
	for (int i = 2; i < gStrLen; ++i)
	{
		while ((iMaxLen >= 0) && (sStr[i-1] != sStr[iMaxLen]))
		{
			iMaxLen = pNext[iMaxLen];
		}

		iMaxLen++;		
		pNext[i] = iMaxLen;
	}
	return true;

}

void match(char* sStr1,char* sStr2,int* pNext)
{
	int iLen = strlen(sStr1);
	int i = 0, j = 0;
	while ((i < gStrLen) && (j < iLen))
	{
		if (i < 0 || sStr1[j] == sStr2[i])
		{
			i++;
			j++;
		} 
		else
		{
			i = pNext[i];
		}
	}
	if (i == gStrLen)
	{
		cout << "successful" << endl;
		cout << "pos:" << j - i << endl;
	} 
	else
	{
		cout << "failed" << endl;
	}
}

int main(int argc,char** argv)
{
	int * pNext;
	char* sStr = "abcabc";
	char sStr2[100];

	gStrLen = strlen(sStr);
	pNext = new int[gStrLen];
	strNext(sStr, pNext);

	for (int i = 0; i < gStrLen; ++i)
	{
		cout << pNext[i] << " ";
	}
	cout << endl;

	cin >> sStr2;
	match(sStr2, sStr, pNext);

	system("pause");
	return 0;
}
