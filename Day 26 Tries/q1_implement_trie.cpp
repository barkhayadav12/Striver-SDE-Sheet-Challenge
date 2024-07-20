// trie mein 2 data hoga
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

    bool search(string word)
    {
        node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            // if character present na ho toh return false
            if (!temp->containsKey(word[i]))
            {
                return false;
            }
            // if present hai toh move to its reference node
            temp = temp->get(word[i]);
        }
        // if abhi tak jo given word hai uski saare character present ho toh, abhi it must be standing in its reference node, reference node last node hui (matlab flag true hui) toh return true, else agar hum kisi trie pe hai jo ki last node nhi hai toh return false
        return temp->isEnd();
    }

    bool startsWith(string prefix)
    {
        node *temp = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            // if character present na ho toh return false
            if (!temp->containsKey(prefix[i]))
            {
                return false;
            }
            // if present hai toh move to its reference node
            temp = temp->get(prefix[i]);
        }
        return true;
    }
};