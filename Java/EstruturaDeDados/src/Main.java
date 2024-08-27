import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) {

        Queue<Candidatos> filaA = new LinkedList<>();
        Queue<Candidatos> filaB = new LinkedList<>();
        Queue<Candidatos> filaQ = new LinkedList<>();

        filaQ.add(new Candidatos("Luis", "B"));
        filaQ.add(new Candidatos("Pedro", "A"));
        filaQ.add(new Candidatos("Luisa", "A"));
        filaQ.add(new Candidatos("Joao", "X"));
        filaQ.add(new Candidatos("Jose", "X"));
        filaQ.add(new Candidatos("Miguel", "B"));

        while (!filaQ.isEmpty()) {
            Candidatos candidato = filaQ.poll();

            switch (candidato.getDepartamento()) {
                case "A" -> filaA.add(candidato);
                case "B" -> filaB.add(candidato);
                case "X" -> {
                    if (filaA.size() == filaB.size()) {
                        filaQ.remove(candidato);
                    } else if (filaA.size() > filaB.size()) {
                        filaB.add(candidato);
                    } else {
                        filaA.add(candidato);
                    }
                }
            }
        }

        Queue<Candidatos> filaA1 = new LinkedList<>();
        Queue<Candidatos> filaB1 = new LinkedList<>();
        Queue<Candidatos> filaQ1 = new LinkedList<>();

        filaQ1.add(new Candidatos("Luis", "B"));
        filaQ1.add(new Candidatos("Pedro", "B"));
        filaQ1.add(new Candidatos("Luisa", "X"));
        filaQ1.add(new Candidatos("Joao", "X"));

        while (!filaQ1.isEmpty()) {
            Candidatos candidato1 = filaQ1.poll();

            switch (candidato1.getDepartamento()) {
                case "B" -> filaB1.add(candidato1);
                case "X" -> {
                    if (candidato1.getDepartamento().equals("X")) {
                        if (filaA1.size() > filaB1.size()) {
                            filaB1.add(candidato1);
                        } else {
                            filaA1.add(candidato1);
                        }
                    }
                }
            }
        }

        System.out.println("Departamento Q - " + filaQ);
        System.out.println("Departamento A - " + filaA);
        System.out.println("Departamento B - " + filaB);
        System.out.println();

        System.out.println("Departamento Q - " + filaQ1);
        System.out.println("Departamento A - " + filaA1);
        System.out.println("Departamento B - " + filaB1);
    }
}