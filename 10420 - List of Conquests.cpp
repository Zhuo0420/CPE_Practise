/*
In Act I, Leporello is telling Donna Elvira about his master’s long list of conquests:
“This is the list of the beauties my master has loved, a list I’ve made out myself: take
a look, read it with me. In Italy six hundred and forty, in Germany two hundred and
thirty-one, a hundred in France, ninety-one in Turkey; but in Spain already a thousand and
three! Among them are country girls, waiting-maids, city beauties; there are countesses,
baronesses, marchionesses, princesses: women of every rank, of every size, of every age.”
(Madamina, il catalogo questo)
As Leporello records all the “beauties” Don Giovanni “loved” in chronological order, it is very
troublesome for him to present his master’s conquest to others because he needs to count the number
of “beauties” by their nationality each time. You are to help Leporello to count.

Input
The input consists of at most 2000 lines. The first line contains a number n, indicating that there will
be n more lines. Each following line, with at most 75 characters, contains a country (the first word)
and the name of a woman (the rest of the words in the line) Giovanni loved. You may assume that the
name of all countries consist of only one word.

Output
The output consists of lines in alphabetical order. Each line starts with the name of a country, followed
by the total number of women Giovanni loved in that country, separated by a space.

Sample Input
3
Spain Donna Elvira
England Jane Doe
Spain Donna Anna

Sample Output
England 1
Spain 2
}*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;
void sortstr(char a[2000][76], int n) {
	char tmp[76];
	for (int j = 0; j < n-1; j++) {
		for (int i = n-2; i >= j ; i--) {
			if (strcmp(a[i], a[i+1]) > 0) {
				strcpy_s(tmp, a[i]);
				strcpy_s(a[i], a[i + 1]);
				strcpy_s(a[i + 1], tmp);
			}
		}
	
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	char a[2000][76];
	int i = 0, j = 0;
	cin >> n;
	cin.get();
	for (i = 0; i < n; i++) {
		cin >> a[i];
		char na[76];
		cin.getline(na, 75);
	}
	int c = 0;
	sortstr(a, n);
	bool F = 0;	//F為1 = 此國家與下一行國家不一樣(c++) 輸出此國名及c,else c繼續累加
	i = 0;
	while (i<n) {
		if (!F) {
			cout << a[i] << " ";
			c++;
			F = 1;
		}
		else if (F) {
			if (strcmp(a[i], a[i + 1]) == 0) {		//a[i]==a[i+1] -> return 0
				c++;
			}	
			else {
				cout << c << endl;
				c = 0;
				F = 0;
			}
			i++;
		}
	}
	return 0;
}
