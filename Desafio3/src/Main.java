import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {

        Stack<Tasks> equipeA = new Stack<Tasks>();
        Stack<Tasks> equipeB = new Stack<Tasks>();
        Stack<Tasks> operacaoX = new Stack<Tasks>();

        operacaoX.add(new Tasks("Feature1", "B"));
        operacaoX.add(new Tasks("Bugfix1", "A"));
        operacaoX.add(new Tasks("Feature2", "A"));
        operacaoX.add(new Tasks("Refactor1", "X"));
        operacaoX.add(new Tasks("Optimization1", "X"));
        operacaoX.add(new Tasks("Feature3", "B"));
        
        while (!operacaoX.empty()){
            Tasks tasks = operacaoX.pop();

           switch (tasks.getEquipe()){
               case "B" -> equipeA.add(tasks);
               case "A" -> equipeB.add(tasks);
               case "X" -> {
                   if(equipeA.size() == equipeB.size()){
                       operacaoX.remove(tasks);
                   } else if (equipeA.size() > equipeB.size()) {
                       equipeB.add(tasks);
                   } else {
                       equipeA.add(tasks);
                   }
               }
           }
        }

        System.out.println("Equipe A - " + equipeA);
        System.out.println("Equipe B - " + equipeB);
        System.out.println("Operação X - " + operacaoX);
    }


}