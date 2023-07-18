class Node{
public:
    int key;
    int val;
    Node *next;
    Node * prev;
    Node(int x,int y)
    {
        key=x;
        val=y;
        next=NULL;
        prev=NULL;
    }
};

class LRUCache {
public:
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    unordered_map<int,Node*> mp;
    int sz=0;
    LRUCache(int capacity) {
        sz=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addnode(Node * recentnode)
    {
        Node *temp=head->next;
        head->next=recentnode;
        recentnode->prev=head;
        recentnode->next=temp;
        temp->prev=recentnode;
    }

    void delnode(Node *dnode)
    {
        Node *curr1=dnode->prev;
        Node *curr2=dnode->next;
        curr1->next=curr2;
        curr2->prev=curr1;
    }
    
    int get(int key) {
        if (mp.find(key)!=mp.end())
        {
            Node *pos=mp[key];
            int res=pos->val;
            mp.erase(key);
            delnode(pos);
            addnode(new Node(key,res));
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key)!=mp.end())
        {
            Node *pos=mp[key];
            mp.erase(key);
            delnode(pos);
        }
        if (mp.size()==sz)
        {
            Node *pos=tail->prev;
            mp.erase(pos->key);
            delnode(pos);
        }
        addnode(new Node(key,value));
        mp[key]=head->next;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */