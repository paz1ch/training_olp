import java.util.*;

public class fibo{
    public static final long MOD = 1000000007L;

    public static class matrix{
        long[][] arr = new long[2][2];

        matrix(){
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    arr[i][j]=0L;
                }
            }
        }
        matrix multiply(matrix a, matrix b){
            matrix c = new matrix();
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        c.arr[i][j] = (c.arr[i][j] + a.arr[i][k] * b.arr[k][j] % MOD) % MOD;
                    }
                }
            }
            return c;
        }

        matrix pow(matrix u, long n) {
            matrix res = new matrix();
            for (int i = 0; i < 2; i++) res.arr[i][i] = 1L;
            while (n > 0) {
                if (n % 2 == 1) res = multiply(res, u);
                u = multiply(u, u);
                n /= 2;
            }
            return res;
        }
    }
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        if (n == 0) {
            System.out.println(0);
            return;
        }
        matrix u = new matrix();
        u.arr[0][0] = 1; u.arr[0][1] = 1;
        u.arr[1][0] = 1; u.arr[1][1] = 0;
        matrix res = u.pow(u, n - 1);
        System.out.println(res.arr[0][0]);
    }
}