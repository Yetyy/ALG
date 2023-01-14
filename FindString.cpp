#include <iostream>
#include <string>
using namespace std;

int search(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            return i;
    }
    return -1;
}

int main()
{
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern to search for: ";
    getline(cin, pattern);
    int index = search(text, pattern);
    if (index == -1)
        cout << "Pattern not found." << endl;
    else
        cout << "Pattern found at index " << index << endl;
    return 0;
}
