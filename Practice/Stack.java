import java.util.ArrayList;

class Stack {
    final static int MAX_SIZE = 20;
    static ArrayList<Integer> stack = new ArrayList<>(MAX_SIZE);
    public static boolean isFull() {
        if (stack.size() >= MAX_SIZE) {
            return true;
        }
        else {
            return false;
        }
    }
    public static boolean isEmpty() {
        if (stack.size() == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    public static void push(int num) {
        stack.add(num);
    }
    public static int pop() {
        if (!isEmpty()) {
            int save = top();
            stack.remove(stack.size()-1);
            return save;
        }
        else {
            return 0;
        }
    }
    public static Integer top() {
        if (!isEmpty()) {
            //return stack[stack.size()];
            return stack.get(stack.size()-1);
        }
        else {
            return 0;
        }
    }
    public static void main(String[] args) {
        System.out.println(isFull());
        System.out.println(isEmpty());
        push(4);
        push(5);
        System.out.println(top());
        System.out.println(pop());
        System.out.println(top());
    }
}