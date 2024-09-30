using namespace std;

#include "iostream"

int main()
{
    char startToken[] = "start";
    int s = 0;

    char inputData[1024] = {'\0'};
    cin >> inputData;

    if (inputData[0] == 's' &&
        inputData[1] == 't' &&
        inputData[2] == 'a' &&
        inputData[3] == 'r' &&
        inputData[4] == 't')
    { }
    else
    {
        cout << "Missing Start Token\n";
        return 1;
    }

    int j = 5;

    while (inputData[j])
    {
        if (s == 4)
        {
            s = 0;
        }
        else
        {
            cout << inputData[j];
        }

        if (inputData[j] == startToken[s])
        {
            s++;
        }
        else
        {
            s = inputData[j] == startToken[0];
        }

        j++;

    }
}