import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;


class Result {

    public static long minTime(List<Integer> files, int numCores, int limit) {
        if(numCores == 1)
        {
            long total=0;
            for(int i=0;i<files.size();i++)
                total += files.get(i);
           return total;
        }
        Collections.sort(files);
        long total=0;
        for(int i=files.size()-1;i>=0;i--)
        {
            if(limit!=0 && files.get(i) % numCores == 0)
            {
                total +=files.get(i)/numCores;
                limit--;
            } else{
                total += files.get(i);
            }
        }
        return total;

    }

}
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int filesCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> files = IntStream.range(0, filesCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine().replaceAll("\\s+$", "");
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .map(String::trim)
            .map(Integer::parseInt)
            .collect(toList());

        int numCores = Integer.parseInt(bufferedReader.readLine().trim());

        int limit = Integer.parseInt(bufferedReader.readLine().trim());

        long result = Result.minTime(files, numCores, limit);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
