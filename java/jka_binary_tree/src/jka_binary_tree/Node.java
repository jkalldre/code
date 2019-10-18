/**
 * 
 */
package jka_binary_tree;

/**
 * @author YZFFVR
 *
 */
public class Node {
//  Public variables
	public Integer value;
	public Node left;
	public Node right;

	/**
	 * 
	 */
	Node(int value) {
		this.value = value;
		this.left = null;
		this.right = null;
	}

	public Integer numChild() {
		Integer count = 0;

		count = this.left != null ? count + 1 : count;
		count = this.right != null ? count + 1 : count;
		
		return count;
	}
}
