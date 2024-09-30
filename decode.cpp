#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

// Define startToken globally
const string startToken = "start";

int main()
{
    int s = 0;
    string inputData = {'\0'};
    cin >> inputData; 

    // Check if the inputData starts with startToken
    if (strncmp(inputData.c_str(), startToken.c_str(), startToken.length()) == 0)
    {
        // Input starts with startToken
    }
    else
    {
        cout << "Missing Start Token\n";
        return 0;
    }

    int j = startToken.length(); // Start checking after "start token"

    while (inputData[j])
    {
        if (s == startToken.length()-1)
        {
            s = 0; // Reset s if it reaches length of string-1
        }
        else
        {
            cout << inputData[j]; // Print the current character
        }

        if (inputData[j] == startToken[s])
        {
            s++; // Move to the next character in startToken if the current one matches
        }
        else
        {
            s = (inputData[j] == startToken[0]); // If no match, reset s. If the current character is the beginning of startToken, then set it to 1
        }

        j++;
    }

    if (inputData.substr(startToken.length()).find(startToken) != string::npos)
    {
        cout << "\nError: Start Token appears in payload of Link Level message!";
    }

    return 0;
}
