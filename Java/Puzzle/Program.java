package Puzzle;

import java.util.Map;
import java.util.HashMap;

public class Program {
    public static void main(String[] args) {
        
    }

    public static int[] puzzle(int people, int freq, int surivors) {
        Map<Integer, Boolean> nums = new HashMap<Integer, Boolean>();

        for (int i = 0; i < people; i++) {
            nums.put(i, false);
        }

        int res;

        for (res = 0; !nums.isEmpty(); res += freq) {
            if (res >= people) {
                res %= people;
            }
            nums.remove(res);
        }
        if (res >= people) {
            res %= people;
        }
        System.out.println(res);
        return null;
    }
}