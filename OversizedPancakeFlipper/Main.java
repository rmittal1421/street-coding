import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));

        String line = "";
        line += scan.readLine();

        int questions = Integer.parseInt(line.trim());

        for (int i = 0; i < questions; i++) {
            String[] input = scan.readLine().split(" ");
            String faces = input[0];
            String idealString = "";

            for (int r = 0; r < faces.length(); r++) {
                idealString += "+";
            }

            int size = Integer.parseInt(input[1]);
            List<String> already = new ArrayList<>();
            already.add(faces);

            //Took the result to be 0 and add 1 if we flip something.
            int result = 0;
            boolean notPossible = false;

            while (true) {
                List<Integer> values = new ArrayList<>();

                for (int in = 0; in <= (faces.length() - size); in++) {
                    String s = faces.substring(in, in + size);
                    int x = 0;
                    for (int k = 0; k < s.length(); k++) {
                        x += (s.charAt(k) == '+') ? 1 : -1;
                    }
                    values.add(x);
                }

                int indexOfNewMin = getIndexOfMin(values, faces, size);
                int new_min = values.get(indexOfNewMin);

                if (faces.equals(idealString)) {
                    break;
                }
                faces = "" + faces.substring(0, indexOfNewMin) + flipString(faces.substring(indexOfNewMin, indexOfNewMin + size)) + faces.substring(indexOfNewMin + size);
                if (already.contains(faces) && !faces.equals(idealString)) {
                    notPossible = true;
                    break;
                }
                else {
                    result++;
                    already.add(faces);
                }

            }

            if (notPossible) {
                System.out.println("Case #" + (i + 1) + ": " + "IMPOSSIBLE");
            } else {
                System.out.println("Case #" + (i + 1) + ": " + result);
            }

        }
    }

    private static String flipString(String string) {
        string = string.replace('+', '.');
        string = string.replace('-', '+');
        string = string.replace('.', '-');

        return string;
    }

    public static int getIndexOfMin(List<Integer> data, String faces, int size) {
        int min = Integer.MAX_VALUE;
        int index = -1;
        boolean ch = false;

        for (int i = data.size() - 1; i >= 0; i--) {
            int f = data.get(i);

            if (Integer.compare(f, min) < 0) {
                if (faces.charAt(i+size-1) == '-') {
                    ch = true;
                }
                min = f;
                index = i;
            }
            else if (Integer.compare(f, min) == 0 && !(ch)) {
                if (faces.charAt(i+size-1) == '-') {
                    ch = true;
                    min = f;
                    index = i;
                }
            }
        }
        return index;
    }
}