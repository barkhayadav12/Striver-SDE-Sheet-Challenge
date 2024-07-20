#include <bits/stdc++.h>
struct node
{
    node *links[26];
    int endsWith = 0;
    int countPrefix = 0;
    // checks if the given character is present in the trie or not
    bool containsKey(char ch)
    {
        node *temp = links[ch - 'a'];
        if (temp == NULL)
        {
            return false;
        }
        return true;
    }
    // get the reference node
    node *get(char ch)
    {
        return links[ch - 'a'];
    }
    // if character is not present, insert karo jo given address hai uspe
    void put(char ch, node *temp)
    {
        links[ch - 'a'] = temp;
    }
    // increase no. of words
    void increaseEnd()
    {
        endsWith++;
    }
    // increase prefix
    void increasePrefix()
    {
        countPrefix++;
    }
    // delete end
    void deleteEnd()
    {
        endsWith--;
    }
    // reduce prefix
    void reducePrefix()
    {
        countPrefix--;
    }
    // get words count when we have reached the end
    int getEnd()
    {
        return endsWith;
    }
    // get prefix length
    int getPrefix()
    {
        return countPrefix;
    }
};
class Trie
{
private:
    node *root;

public:
    Trie()
    {
        // Write your code here.
        root = new node();
    }

    void insert(string &word)
    {
        // Write your code here.
        node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            // if character is not present
            if (!temp->containsKey(word[i]))
            {
                temp->put(word[i], new node());
            }
            // move to its reference node
            temp = temp->get(word[i]);
            // increase the prefix count
            temp->increasePrefix();
        }
        // when you have reached the end, increase the no. of words count
        temp->increaseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!temp->containsKey(word[i]))
            {
                return 0;
            }
            // move to its reference node if present
            temp = temp->get(word[i]);
        }
        return temp->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!temp->containsKey(word[i]))
            {
                return 0;
            }
            temp = temp->get(word[i]);
        }
        return temp->getPrefix();
    }

    void erase(string &word)
    {
        // Write your code here.
        node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (temp->containsKey(word[i]))
            {
                temp = temp->get(word[i]);
                temp->reducePrefix();
            }
            else
            {
                return;
            }
        }
        temp->deleteEnd();
    }
};
