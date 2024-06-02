#include <iostream>
#include <string.h>
using namespace std;

int getLength(char name[])
{
    int length = 0;
    int i = 0;
    while (name[i] != '\0')
    {
        length++;
        i++;
    }
    return length;
    ;
}

void reverseCharArray(char name[])
{
    int i = 0;
    int n = getLength(name);
    int j = n - 1;

    while (i <= j)
    {
        swap(name[i], name[j]);
        i++, j--;
    }
}

void replaceSpaces(char sentence[])
{
    int i = 0;
    int n = strlen(sentence);
    for (int i = 0; i < n; i++)
    {
        if (sentence[i] == ' ')
        {
            sentence[i] = '0';
        }
    }
}

bool checkpalindrone(char word[])
{
    int i = 0;
    int n = strlen(word);
    int j = n - 1;
    while (i <= j)
    {
        if (word[i] != word[j])
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

void convertToUpperCase(char arr[])
{
    int n = getLength(arr);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 'a' && arr[i] <= 'z')
        {
            arr[i] = arr[i] - 'a' + 'A';
        }
    }
}

int main()
{
    // char name[100];
    // cout << "Enter you name" << endl;

    // cin >> name;
    // cout << "Apka name :" << name << " hai " << endl;

    // char ch[100];
    // ch[0] = 'a';
    // ch[1] = 'b';
    // ch[2] = 'a';

    // cin >> ch[3];

    // cout << ch[0] << ch[1] << ch[2] << ch[3] << endl;

    // char name[100];
    // cin >> name;

    // for (int i = 0; i < 9; i++)
    // {
    //     cout << "Index " << i << " value :" << name[i] << endl;
    // }

    // int value = (int)name[8];
    // cout << "value is :" << value << endl;

    // char don[10];
    // cin >> don;
    // cout << don;

    // Find length

    // char name[100];
    // cin >> name;
    // cout << "length is :" << getLength(name) << endl;
    // cout << "length is :" << strlen(name) << endl;

    // Reverse string

    // char name[100];
    // cin >> name;

    // cout << "Initially: " << name << endl;
    // reverseCharArray(name);
    // cout << "After reversing process : " << name << endl;

    // Replace space
    //  char sentence[100];
    //  cin.getline(sentence, 100);

    // replaceSpaces(sentence);

    // cout << "After Repalcing spaces :" << sentence << endl;

    // Palindrone

    // char arr[100];
    // cin >> arr;
    // cout << "Palinedrone check :" << checkpalindrone(arr);

    char name[100];
    cin >> name;
    convertToUpperCase(name);
    cout << "After converting to upper case :" << name << endl;

    return 0;
}