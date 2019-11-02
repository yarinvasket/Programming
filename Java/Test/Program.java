package Test;

import java.util.List;
import java.util.ArrayList;

class Program {
    public static void main(String[] args) {
        List<Integer> primeNumbers = new ArrayList<Integer>();

        inner: for (int i = 3;; i+=2) {
            for (int e : primeNumbers)
                if (i % e == 0)
                    continue inner;
            primeNumbers.add(i);
        }
    }
}