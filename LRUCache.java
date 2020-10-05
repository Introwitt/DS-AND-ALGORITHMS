import java.util.*;

class LRUCache {
    
    DLL h,t;
    int cap;
    int cur;
    HashMap<Integer,DLL> hm;
    
    public void removeFirst(){
        if(h.next.next == t){
            h.next = t;
            t.pre = h;
        } else {
            h.next = h.next.next;
            h.next.pre = h;
        }
    }
    
    public void remove(DLL node){
        node.pre.next = node.next;
        node.next.pre = node.pre;
    }
    
    public void addLast(DLL node){
        if(t.pre == h){
            h.next = node;
            node.pre = h;
            t.pre = node;
            node.next = t;
        } else {
            node.pre = t.pre;
            node.next = t;
            t.pre.next = node;
            t.pre = node;
        }
    }

    public LRUCache(int capacity) {
        cap = capacity;
        t = new DLL(-2,0);
        h = new DLL(-2,0);
        h.next = t;
        t.pre = h;
        hm = new HashMap<>();
        cur = 0;
    }
    
    public int get(int key) {
        if(hm.containsKey(key)){
            DLL rem = hm.get(key);
            hm.put(key,new DLL(key,rem.val));
            remove(rem);
            addLast(hm.get(key));
            return hm.get(key).val;
        } else {
            return -1;
        }
    }
    
    public void put(int key, int value) {
        
        if(hm.containsKey(key)){
            DLL rem = hm.get(key);
            remove(rem);
            hm.put(key,new DLL(key,value));
            addLast(hm.get(key));
        } else {
            hm.put(key,new DLL(key,value));
            addLast(hm.get(key));
            cur++;
        }
        if(cur > cap) {
            int r = h.next.key;
            hm.remove(r);
            removeFirst();
            cur--;
        }
    }
    
    class DLL {
        int val;
        DLL next;
        DLL pre;
        int key;
        DLL (int k,int v) {
            key = k;
            val = v;
        }
    }
    
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */