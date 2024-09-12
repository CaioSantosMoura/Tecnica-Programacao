import java.util.List;
public class ListUtils {

    public ListUtils() {
    }
    public void addToList(List<String> list, String item){
        list.add(item);
    }
    public void removeFromList(List<String> list, String item){
        list.remove(item);
    }
    public boolean findInList(List<String> list, String item){
        return list.contains(item);
    }
}
