mport java.util.Scanner;
import java.lang.*;

public class SieveOfEratosthenes {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number upto which you need prime numbers");
        int n = scanner.nextInt();
        System.out.println("Prime numbers upto " + n + " are ");
        SievePrime(n);
    }

    private static void SievePrime(int n) {
        Boolean[] arr = new Boolean[n + 1];
        for (int i = 0; i < n; i++) {
            arr[i] = true;
        }

        for (int p = 2; p * p < n; p++) {

            if (arr[p]) {

                for (int i = p * p; i <= n; i += p) {
                    arr[i] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (arr[i]) {
                System.out.print(i + " ");
            }
        }
    }
}