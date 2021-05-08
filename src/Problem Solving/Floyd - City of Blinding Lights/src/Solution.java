import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;



public class Solution {

    public static final int INF = Integer.MAX_VALUE;

    public static int[][] process(List<Integer> roadFrom, List<Integer> roadTo, List<Integer> roadWeight, int roadNodes) {
        int numberOfEdges = roadFrom.size();
        int[][] matrix = new int[roadNodes + 1][roadNodes + 1];

        for (int u = 0; u <= roadNodes; u++) {
            for (int v = 0; v <= roadNodes; v++) {
                if (u != v) {
                    matrix[u][v] = INF;
                }
            }
        }

        for (int i = 0; i < numberOfEdges; i++) {
            matrix[roadFrom.get(i).intValue()][roadTo.get(i).intValue()] = roadWeight.get(i).intValue();
        }

        for (int k = 1; k <= roadNodes; k++) {
            // Pick all vertices as source one by one
            for (int i = 1; i <= roadNodes; i++) {
                // Pick all vertices as destination for the
                // above picked source
                for (int j = 1; j <= roadNodes; j++) {
                    // If vertex k is on the shortest path from
                    // i to j, then update the value of
                    // dist[i][j]
                    if (matrix[i][j] > (matrix[i][k] + matrix[k][j])
                            && (matrix[k][j] != INF
                            && matrix[i][k] != INF))
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }

        return matrix;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        String[] roadNodesEdges = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int roadNodes = Integer.parseInt(roadNodesEdges[0]);
        int roadEdges = Integer.parseInt(roadNodesEdges[1]);
        AtomicInteger nodeHighestValue = new AtomicInteger(0);

        List<Integer> roadFrom = new ArrayList<>();
        List<Integer> roadTo = new ArrayList<>();
        List<Integer> roadWeight = new ArrayList<>();

        IntStream.range(0, roadEdges).forEach(i -> {
            int u, v;

            try {
                String[] roadFromToWeight = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

                roadFrom.add(u = Integer.parseInt(roadFromToWeight[0]));
                roadTo.add(v = Integer.parseInt(roadFromToWeight[1]));
                roadWeight.add(Integer.parseInt(roadFromToWeight[2]));

                nodeHighestValue.set((u > v) ? u : v);
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        int matrix[][] = process(roadFrom, roadTo, roadWeight, roadNodes);

        int q = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, q).forEach(qItr -> {
            try {
                String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

                int x = Integer.parseInt(firstMultipleInput[0]);

                int y = Integer.parseInt(firstMultipleInput[1]);

                System.out.println(matrix[x][y] == INF ? -1 : matrix[x][y]);
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
    }
}
