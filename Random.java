class Random {

    class Node {
        Node random;
        Node next;
        int val;
        Node(int v) {
            val = v;
        }
    }

    public Node copyRandomList(Node head) {
            Node temp = head;
        if(head == null) return null;
        while(temp != null){
            Node t = new Node(temp.val);
            t.next = temp.next;
            temp.next = t;
            temp = t.next;
        }
        temp = head;
        while(temp != null){
            if(temp.random != null){
                temp.next.random = temp.random.next;
            }
            temp = temp.next.next;
        }
        Node res = head.next;
        temp = head;
        Node output = res;
        while(res != null && temp != null){
            temp.next = temp.next.next;
            if(res.next == null) break;
            res.next = res.next.next;
            res = res.next;
            temp = temp.next;
        }
        return output;
     } 
 }