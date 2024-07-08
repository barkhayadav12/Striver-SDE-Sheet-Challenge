class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int val;
        node *prev;
        node *next;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    unordered_map<int, node *> mpp;
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    // add the new node next to head
    void addNode(node *newNode)
    {
        node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
        head->next = newNode;
    }
    // delete the node right before tail
    void deleteNode(node *delNode)
    {
        node *delprev = delNode->prev;
        node *delnext = delNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    int get(int key)
    {
        // if key exists, we need to return its value.
        // Steps: Delete that node from the doubly linked list and insert it next to the head,
        // inserting near the head signifies that, that particular value is the most recently added one,
        // and then get its new location and add it to the hashmap
        if (mpp.find(key) != mpp.end())
        {
            // get that node
            node *temp = mpp[key];
            int ans = temp->val;
            // delete it
            mpp.erase(key);
            deleteNode(temp);
            // add it next to head and assign its new location
            addNode(temp);
            mpp[key] = head->next;
            // return the answer
            return ans;
        }
        // if key doesn't exist
        return -1;
    }

    void put(int key, int value)
    {
        // if the already exists, delete it from the hashmap as well as from the doubly linked list
        if (mpp.find(key) != mpp.end())
        {
            node *temp = mpp[key];
            mpp.erase(key);
            deleteNode(temp);
        }
        // if full, delete the least recently used cache(LRU) from the hashmap and from the doubly
        // linked list. LRU cache would be the one right before tail pointer, so delete it
        if (mpp.size() == cap)
        {
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        // if it doesn't exist, add it to the hashmap as well as to the doubly linked list
        addNode(new node(key, value));
        mpp[key] = head->next;
    }
};