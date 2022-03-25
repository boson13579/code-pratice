package Java.P;

class Student {
    // do something here
    private String name;
    private int score;

    Student(String NAME, int SCORE) {
        this.name = NAME;
        this.score = SCORE;
    }

    public String getName() {
        return name;
    }

    public int getScore() {
        return score;
    }

    public void changeScore(int new_score) {
        this.score = new_score;
    }
}

public class P3_110502529 {
    
        public static void main(String[] args){
        // 以下不要改
        Student putin = new Student("Putin", 59);
        System.out.println(putin.getName() + " before: " + putin.getScore());
        putin.changeScore(40);
        System.out.println(putin.getName() + " after: " + putin.getScore());
//        putin.score = 100;
    }
    }