class Node{
    public:
    int key;
    int val;
    Node*prev;
    Node*next;

    Node(int k, int v){
        key=k;
        val=v;
        prev=NULL;
        next=NULL;
    }
};

class LRUCache {
public:
    unordered_map<int,Node*>mp;
    Node* head = new Node(-1,-1);
    Node*tail = new Node(-1,-1);
    int size;

    void deleteNode(Node*node){
        mp.erase(node->key);
        Node*delNext=node->next;
        Node*delPrev= node->prev;
        delPrev->next=delNext;
        delNext->prev=delPrev;
    }

    void insertNode(Node*node){
        mp[node->key]=node;
        Node*headNext=head->next;
        node->next=headNext;
        head->next=node;
        node->prev=head;
        headNext->prev=node;
    }

    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node*node=mp[key];
            deleteNode(node);
            insertNode(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()){
            Node*node=mp[key];
            deleteNode(node);
        }
        if(mp.size()>=size){
            deleteNode(tail->prev);
        }

        insertNode(new Node(key,value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */