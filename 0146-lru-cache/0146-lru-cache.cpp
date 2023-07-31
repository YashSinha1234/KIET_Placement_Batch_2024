class LRUCache {
public:
    
    struct node{
        int key;
        int val;
        node* next;
        node* prev;
        node(int k, int v){
            key=k;
            val=v;
            prev=NULL;
            next=NULL;
        }
    };
    
    struct node *head = new node(-1,-1);
    struct node *tail = new node(-1,-1);
    
    int size;
    unordered_map<int,node*> mp; // to store address of node against its key
    
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    // insertion will be done just after head
    void addNode(node *newnode){
        struct node *add_next = head->next;
        
        // linking newnode & 2nd node
        newnode->next = add_next;
        add_next->prev = newnode;
        
        // linking newnode & head
        head->next=newnode;
        newnode->prev=head;
    }
    
    // deletion will be done for node just previous to tail
    void deleteNode(node *node){
        struct node *del_next = node->next;
        struct node *del_prev = node->prev;
        
        del_prev->next = del_next;
        del_next->prev = del_prev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node *resnode=mp[key];
            int res=resnode->val;
            
            // since this node is accessed, it becomes Recently used, deleted from current address & added next to head
            mp.erase(key); 
            deleteNode(resnode);
            addNode(resnode);
            
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // since this node is accessed, it becomes Recently used, deleted from current address & added next to head
        if(mp.find(key)!=mp.end()){
            node *existingnode = mp[key];
            mp.erase(key);
            deleteNode(existingnode);
        }
        
        // if we are adding new node & cache size = capacity, so we need to delete node previous to tail
        if(mp.size()==size){
            node *dnode = tail->prev;
            mp.erase(dnode->key);
            deleteNode(dnode);
        }
        
        addNode(new node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */