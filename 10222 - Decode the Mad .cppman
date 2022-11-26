/*
* 10222 - Decode the Mad man
Once in BUET, an old professor had gone completely mad. He started talking with some peculiar
words. Nobody could realize his speech and lectures. Finally the BUET authority fall in great trouble.
There was no way left to keep that man working in university. Suddenly a student (definitely he was
a registered author at UVA ACM Chapter and hold a good rank on 24 hour-Online Judge) created
a program that was able to decode that professor’s speech. After his invention, everyone got comfort
again and that old teacher started his everyday works as before.
So, if you ever visit BUET and see a teacher talking with a microphone, which is connected to a
IBM computer equipped with a voice recognition software and students are taking their lecture from
the computer screen, don’t get thundered! Because now your job is to write the same program which
can decode that mad teacher’s speech!
Input
The input file will contain only one test case i.e. the encoded message.
The test case consists of one or more words.
Output
For the given test case, print a line containing the decoded words. However, it is not so hard task to
replace each letter or punctuation symbol by the two immediately to its left alphabet on your standard
keyboard.

Sample Input
k[r dyt I[o

Sample Output
how are you
*/
#include <iostream>
#include <string.h>
using namespace std;

char ToUpper(char a) {
    return a - 'A' + 'a';
}
int main()
{
    char in[9999999];
    char a[] = "234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    char b[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,";
    int n = strlen(a);
    int i, j;
    cin.getline(in,9999998);
    int m = strlen(in);
    for (i = 0; i < m; i++) {
        if (in[i] >= 'A' && in[i] <= 'Z') {
            in[i] = ToUpper(in[i]);
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (in[i] == ' ') {
                cout << " ";
                break;
            }
            else if (in[i] == a[j]) {
                cout << b[j];
                break;
            }
        }
    }
    cout << endl;
    return 0;
}
