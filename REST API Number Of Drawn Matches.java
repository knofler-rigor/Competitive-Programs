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

import java.net.*;
import javax.script.*;


class Result {


    public static int getNumDraws(int year) throws IOException {
        final String Endpoint= "https://jsonmock.hackerrank.com/api/football_matches?year=" + year;
        final int MaxScore=10;
        int totalNumDraws=0;
        for (int score=0; score <=MaxScore; score++)
            totalNumDraws+=getTotalNumDraws(
                String.format(Endpoint + "&team1goals=%d&team2goals=%d", score, score));
        return totalNumDraws;
        
    }
    private static int getTotalNumDraws(String request) throws IOException { 
        URL url = new URL (request);
        HttpURLConnection httpURLConnection = (HttpURLConnection) url.openConnection();
        httpURLConnection.setRequestMethod("GET");
        httpURLConnection.setConnectTimeout(5000);
        httpURLConnection.setReadTimeout(5000);
        httpURLConnection.addRequestProperty ("Content-Type", "application/json");
        int status= httpURLConnection.getResponseCode();
        InputStream in =(status < 200 || status > 299) ? 
            httpURLConnection.getErrorStream(): httpURLConnection.getInputStream();
        BufferedReader br =new BufferedReader (new InputStreamReader(in));
        String responseLine;
        StringBuffer responseContent =new StringBuffer();
        while ((responseLine= br.readLine()) != null) 
        responseContent.append(responseLine);

br.close();
httpURLConnection.disconnect();
ScriptEngineManager manager = new ScriptEngineManager ();
ScriptEngine engine =manager.getEngineByName("javascript");

String script = "var obj = JSON.parse('" + responseContent.toString() + "');";
script += "var total= obj.total;";
try {
engine.eval(script);
}

catch (ScriptException ex) { 
    ex.printStackTrace();
}
if (engine.get("total") == null)
throw new RuntimeException("Cannot retrieve data from the server."); 
return (int) engine.get("total");
    }
          
        
    }


public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int year = Integer.parseInt(bufferedReader.readLine().trim());

        int result = Result.getNumDraws(year);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
