using namespace std;

#include "iostream"

int main()
{
    char startToken[] = "start";

    int s = 0;

    char inputData[256] = {'\0'};

    cin >> inputData;

    int j = 0;

    cout << "start";

    while (inputData[j])
    {
        if (s == 4)
        {
            cout << 'r';
            s = 0;
        }

        if (inputData[j] == startToken[s])
        {
            s++;
        }
        else
        {
            s = inputData[j] == startToken[0];
        }

        cout << inputData[j];

        j++;

    }

    return 0;
}