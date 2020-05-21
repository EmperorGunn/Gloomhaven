#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAXBUFSIZE 32

int main(void)
{

	int i = 0, j = 0, row = 0, col = 0, rowFirst, rowSecond, colFirst, colSecond;
	char letter, charTmp, letterSign;
	char key[5][5];
	bool boolDuplicate[26];
	string strInput, strKey;
	vector<char> plainText;

	while (getline(cin, strInput))
	{
		getline(cin, strKey);
		for (i = 0; i < 26; i++)
		{
			boolDuplicate[i] = false;
		}
		for (row = 0; row < 5; row++)
		{
			for (col = 0; col < 5; col++)
			{
				key[row][col] = ' ';
			}
		}
		i = 0;
		row = 0;
		col = 0;
		while (i < strKey.length())
		{
			if (strKey[i] != 'i' && strKey[i] != 'j' && boolDuplicate[strKey[i] - 97] == false)
			{
				boolDuplicate[strKey[i] - 97] = true;
				key[row][col] = strKey[i];
				if (col == 4)
				{
					col = 0;
					row++;
				}
				else
				{
					col++;
				}
			}
			else if (strKey[i] == 'i' && boolDuplicate[strKey[i] - 97] == false && boolDuplicate[strKey[i] + 1 - 97] == false)
			{
				boolDuplicate[strKey[i] - 97] = true;
				boolDuplicate[strKey[i] + 1 - 97] = true;
				key[row][col] = strKey[i];
				if (col == 4)
				{
					col = 0;
					row++;
				}
				else
				{
					col++;
				}
			}
			else if (strKey[i] == 'j' && boolDuplicate[strKey[i] - 97] == false && boolDuplicate[strKey[i] - 1 - 97] == false)
			{
				boolDuplicate[strKey[i] - 97] = true;
				boolDuplicate[strKey[i] - 1 - 97] = true;
				key[row][col] = strKey[i];
				if (col == 4)
				{
					col = 0;
					row++;
				}
				else
				{
					col++;
				}
			}
			i++;
		}
		for (letter = 97; letter <= 122; letter++)
		{
			if (boolDuplicate[letter - 97] == false)
			{
				key[row][col] = letter;
				if (col == 4)
				{
					col = 0;
					row++;
				}
				else
				{
					col++;
				}
			}
		}
		//debug
		for (i = 0; i < 26; i++)
		{
			cout << boolDuplicate[i] << ' ';
		}
		cout << endl;
		for (row = 0; row < 5; row++)
		{
			for (col = 0; col < 5; col++)
			{
				cout << key[row][col] << ' ';
			}
			cout << endl;
		}
		//
		for (row = 0; row < 5; row++)
		{
			for (col = 0; col < 5; col++)
			{
				if (key[row][col] == 'i')
				{
					letterSign = 'i';
				}
				else if (key[row][col] == 'j')
				{
					letterSign = 'j';
				}
			}
		}
		for (i = 0; i < strInput.length(); i++)
		{
			plainText.push_back(strInput[i]);
		}
		for (i = 0; i < plainText.size(); i = i + 2)
		{
			if (plainText[i] == plainText[i + 1])
			{
				charTmp = plainText[i + 1];
				plainText[i + 1] = 'x';
				plainText.insert(plainText.begin() + (i + 2), charTmp);
			}
			if (plainText.size() % 2 == 1)
			{
				plainText.push_back('0');
			}
		}
		while (plainText.back() == '0')
		{
			plainText.pop_back();
		}
		if (plainText.size() % 2 == 1)
		{
			plainText.push_back('x');
		}
		//debug
		for (i = 0; i < plainText.size(); i++)
		{
			cout << plainText[i];
			if (i % 2 == 1)
			{
				cout << ' ';
			}
		}
		cout << endl;
		//
		if (letterSign == 'i')
		{
			for (i = 0; i < plainText.size(); i++)
			{
				if (plainText[i] == 'j')
				{
					plainText[i] = 'i';
				}
			}
		}
		else if (letterSign == 'j')
		{
			for (i = 0; i < plainText.size(); i++)
			{
				if (plainText[i] == 'i')
				{
					plainText[i] = 'j';
				}
			}
		}
		for (i = 0; i < plainText.size(); i = i + 2)
		{
			for (row = 0; row < 5; row++)
			{
				for (col = 0; col < 5; col++)
				{
					if (plainText[i] == key[row][col])
					{
						rowFirst = row;
						colFirst = col;
					}
				}
			}
			for (row = 0; row < 5; row++)
			{
				for (col = 0; col < 5; col++)
				{
					if (plainText[i + 1] == key[row][col])
					{
						rowSecond = row;
						colSecond = col;
					}
				}
			}
			if (rowFirst == rowSecond)
			{
				if (colFirst != 4)
				{
					plainText[i] = key[rowFirst][colFirst + 1];
				}
				else
				{
					plainText[i] = key[rowFirst][0];
				}
				if (colSecond != 4)
				{
					plainText[i + 1] = key[rowSecond][colSecond + 1];
				}
				else
				{
					plainText[i + 1] = key[rowSecond][0];
				}
			}
			else if (colFirst == colSecond)
			{
				if (rowFirst != 4)
				{
					plainText[i] = key[rowFirst + 1][colFirst];
				}
				else
				{
					plainText[i] = key[0][colFirst];
				}
				if (rowSecond != 4)
				{
					plainText[i + 1] = key[rowSecond + 1][colSecond];
				}
				else
				{
					plainText[i + 1] = key[0][colSecond];
				}
			}
			else
			{
				plainText[i] = key[rowFirst][colSecond];
				plainText[i + 1] = key[rowSecond][colFirst];
			}
		}
		for (i = 0; i < plainText.size(); i++)
		{
			cout << plainText[i];
		}
		cout << endl;
		plainText.clear();
	}

	return 0;
}