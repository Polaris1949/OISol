import java.io.*;
import java.util.*;
public class marathonS {
  
  static int[] x, y;
  
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new FileReader("marathon.in"));
    PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("marathon.out")));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int n = Integer.parseInt(st.nextToken());
    int k = Integer.parseInt(st.nextToken());
    x = new int[n];
    y = new int[n];
    for(int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      x[i] = Integer.parseInt(st.nextToken());
      y[i] = Integer.parseInt(st.nextToken());
    }
    int[][] dp = new int[k+1][n];
    for(int i = 0; i < dp.length; i++) {
      Arrays.fill(dp[i], 1 << 30);
    }
    dp[0][0] = 0;
    for(int i = 0; i <= k; i++) {
      for(int j = 0; j < n; j++) {
        for(int l = j+1; l < n && i + l-j-1 <= k; l++) {
          int nextI = i + (l-j-1);
          int nextJ = l;
          dp[nextI][nextJ] = Math.min(dp[nextI][nextJ], dp[i][j] + distBetween(j, l));
        }
      }
    }
    pw.println(dp[k][n-1]);
    pw.close();
  }
  
  public static int distBetween(int i, int j) {
    return dist(x[i], y[i], x[j], y[j]);  
  }

  public static int dist(int x1, int y1, int x2, int y2) {
    int x = x1-x2;
    int y = y1-y2;
    return Math.abs(x) + Math.abs(y);
  }

}
