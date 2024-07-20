struct node
{
    node *links[26]; // considering only lower case letters
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
};
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    node *root = new node();
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        node *temp = root;
        // har substring nikal rhe
        for (int j = i; j < s.length(); j++)
        {
            // if character is not present, create a new trie and increase the count
            if (!temp->containsKey(s[j]))
            {
                cnt++;
                temp->put(s[j], new node());
            }
            // move to next reference node
            temp = temp->get(s[j]);
        }
    }
    return cnt + 1;
}