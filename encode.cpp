#include <iostream>
#include <string>

using namespace std;

// Define startToken globally
const string startToken = "start";
const char stuffing = startToken[startToken.length()-1]-1;

int main()
{
    int s = 0;
    char inputData[256] = {'\0'};

    cin >> inputData;

    int j = 0;

    cout << startToken; // Output "start"

    while (inputData[j])
    {
        if (s == startToken.length()-1)
        {
            cout << stuffing; // Print 'r' when s reaches length of string-1
            s = 0; // Reset s to 0
        }

        if (inputData[j] == startToken[s])
        {
            s++; // Move to the next character in startToken
        }
        else
        {
            s = (inputData[j] == startToken[0]); // Reset s if input doesn't match
        }

        cout << inputData[j]; // Output the current character from inputData

        j++;
    }

    return 0;
}
