package Test;

import java.util.List;
import java.util.ArrayList;

class Program {
    public static void main(String[] args) {
        List<Integer> primeNumbers = new ArrayList<Integer>();
        primeNumbers.add(2);

        inner: for (int i = 3;; i++) {
            for (int e : primeNumbers)
                if (i % e == 0)
                    continue inner;
            primeNumbers.add(i);
        }
    }
}