package Recursive;

public class Program {
    public static void main(String[] args) {
        System.out.println(calcAvg(25252525));
    }

    public static float calcAvg(int num) {
        return calcAvg(num, 1);
    }

    private static float calcAvg(int num, int i) {
        if (num < 10) {
            return (float) num / i;
        }

        int digit = num % 10;
        float prevAvg = calcAvg(num / 10, i + 1);
        int digits = (int) Math.floor(Math.log10(num));
        float out = prevAvg + (float) digit / (i + digits);

        return out;
    }
}