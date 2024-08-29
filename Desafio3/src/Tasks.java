public class Tasks {

    private String nomeTarefa;
    private String equipe;

    public Tasks(String nomeTarefa, String equipe) {
        this.nomeTarefa = nomeTarefa;
        this.equipe = equipe;
    }

    public String getNomeTarefa() {
        return nomeTarefa;
    }

    public void setNomeTarefa(String nomeTarefa) {
        this.nomeTarefa = nomeTarefa;
    }

    public String getEquipe() {
        return equipe;
    }

    public void setEquipe(String equipe) {
        this.equipe = equipe;
    }

    @Override
    public String toString() {
        return getNomeTarefa();
    }
}
