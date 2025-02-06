import dsa.cw2324.WikiFetcher;
import java.io.IOException;
import java.util.*;
class wikiCoursework {
    public static void main(String[] args) throws IOException   {
        TreeMap<String, Map<String, Integer>> outermap = new TreeMap<>();
        for (int i=0; i<10; ++i){
            WikiFetcher wf = new WikiFetcher();
            String[] words = wf.getWords();
            String url = wf.getUrl();
            TreeMap<String, Integer> frequencymap = new TreeMap<>();

            for (String word: words){
                if (!frequencymap.containsKey(word)){
                    frequencymap.put(word, 1);
                }else {
                    Integer new_num = frequencymap.get(word) + 1;
                    frequencymap.put(word, new_num);
                }
                TreeMap<String, Integer> thefrequencymap = new TreeMap<>();
                for (String j : frequencymap.keySet()){
                    if (frequencymap.get(j)>9){
                        thefrequencymap.put(j, frequencymap.get(j));
                    }
                }
                outermap.put(url, thefrequencymap);
            }
        }
        WikiFetcher.deepPrint(outermap);
    }
}

