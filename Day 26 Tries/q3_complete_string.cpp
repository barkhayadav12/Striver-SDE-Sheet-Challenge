#include <bits/stdc++.h>
struct node
{
    node *links[26]; // considering only lower case letters
    bool flag = false;
    // checks if the character is present in the trie or not
    bool containsKey(char ch)
    {
        node *temp = links[ch - 'a'];
        // character present nhi hogi toh null value store hongi waha, agar null hai toh character present nhi hai
        if (temp == NULL)
        {
            return false;
        }
        return true;
    }

    // agar koi character present na ho, toh insert karo, toh jo new address pass kr rhe usmein character ko daldo uski location mein
    void put(char ch, node *temp)
    {
        links[ch - 'a'] = temp;
    }
    // new reference trie return krdi
    node *get(char ch)
    {
        return links[ch - 'a'];
    }
    // words over ho gaye aur hum last reference node pe khade hai toh flag ko true mein convert krdo, this marks ki word end ho gayi hai
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    node *root;

public:
    Trie()
    {
        root = new node();
    }

    void insert(string word)
    {
        node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            // check karo pehle ki woh character exists krti hai ya nhi humare trie mein
            if (!temp->containsKey(word[i]))
            {
                temp->put(word[i], new node());
            }
            // move to new reference trie
            temp = temp->get(word[i]);
        }
        // When we have reached the end, hum last reference node pe khade hai toh uski flag ko true mein change krdo, this means ki word end ho gayi hai
        temp->setEnd();
    }
    bool checkPrefix(string word)
    {
        node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!temp->containsKey(word[i]))
            {
                return false;
            }
            temp = temp->get(word[i]);
            if (temp->isEnd() == false)
            {
                return false;
            }
        }
        return true;
    }
};
string completeString(int n, vector<string> &a)
{
    // Write your code here.
    Trie t;
    // insert all the strings
    for (auto it : a)
    {
        t.insert(it);
    }
    string longest = "";
    for (auto it : a)
    {
        if (t.checkPrefix(it))
        {
            // check if it is the longest
            if (it.length() > longest.length())
            {
                longest = it;
            }
            else if (it.length() == longest.length() && it < longest) // if it is of the same length, we need to return the lexicographically smallest string so the 2nd condn checks if the present string is lexicographically smaller, if it is, we replace the longest with the current longest, else we don't do anything
            {
                longest = it;
            }
        }
    }
    if (longest == "")
    {
        return "None";
    }
    return longest;
}