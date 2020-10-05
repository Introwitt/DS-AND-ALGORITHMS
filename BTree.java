import java.util.*;

class BTree {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        TreeNode p = root;
        Stack<TreeNode> st = new Stack<>();
        if(p == null) return res;
        st.push(p);
        while(st.size() > 0 ){
            p = st.pop();
            res.add(p.val);
            if(p.right != null){
                st.push(p.right);
            } 
            if(p.left != null){
                st.push(p.left);
            }
        }
        
        return res;
        
    }
}
