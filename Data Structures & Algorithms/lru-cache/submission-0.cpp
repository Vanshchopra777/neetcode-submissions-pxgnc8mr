
class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = NULL;
    }
};

class LRUCache {
public:
     int cap;
     unordered_map<int,Node*>mpp;
     Node* head;
     Node* tail;

    LRUCache(int capacity) {
        cap=capacity;
       head = new Node(-1,-1);
       tail = new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        
        
    }
    void addnode(Node* node){
        node->next=head->next;
        node->prev=head;
        node->next->prev=node;
        head->next=node;



    }
    void delnode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;

    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
             Node* newnode=mpp[key];
             int val=newnode->value;
             delnode(mpp[key]);
             addnode(newnode);
             return val;

        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
             Node* lru=mpp[key];
             delnode(lru);
             mpp.erase(key);

        }
        if(mpp.size()==cap){
            Node* last=tail->prev;
            delnode(last);
            mpp.erase(last->key);

        }
        Node* node = new Node(key, value);
        addnode(node);
        mpp[key] = node;
        
    }
};
