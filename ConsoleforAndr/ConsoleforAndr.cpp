#include<iostream>
#include <string>

using namespace std;

class Bracket
{
    struct Node
    {
        char bracket;
        Node* pNext;
    };
    int count;
    Node* pHead;

public:
    Bracket()
    {
        pHead = nullptr;
        count = 0;
    }

    Bracket(char obj)
    {
        Node* pCur = new Node;
        pCur->bracket = obj;
    }

    bool addBracket(char obj)
    {

        Node* pNew = new Node;
        if (pNew)
        {
            if (count == 0)
            {
                pHead = nullptr;
            }
            pNew->bracket = obj;
            pNew->pNext = pHead;
            pHead = pNew;
            count++;
            return true;
        }
        return false;
    }

    bool checkBrakets(char example)
    {
        if (count == 0 || pHead->bracket != example)
        {
            return false;
        }
        Node* pDel = new Node;
        pDel = pHead;
        pHead = pHead->pNext;
        delete pDel;
        pDel = nullptr;
        count--;
        return true;
    }
};

void main()
{
    string some_text;
    cout << "Enter your brackets : ";
    getline(cin, some_text);
    Bracket obj;
    for (int i = 0; i < some_text.length(); ++i)
    {
        if (some_text[i] == '(' || some_text[i] == '[' || some_text[i] == '{')
        {
            obj.addBracket(some_text[i]);
        }
        if (some_text[i] == ')' || some_text[i] == ']' || some_text[i] == '}')
        {
            char tmp;
            some_text[i] == ')' ? tmp = '(' : some_text[i] == ']' ? tmp = '[' : tmp = '{';
            if (obj.checkBrakets(tmp))
            {
                cout << "Brackets confirmed" << endl;
            }
            else
            {
                cout << "Brackets do not meet each other!" << endl;
                break;
            }
        }
    }
    system("pause");
}