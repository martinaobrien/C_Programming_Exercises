public class Student extends Person { // which means that Person is the Superclass of student
    private String[] classes;

    public Student(String n, int a, String[] c){
        super(n,a);
        this.classes = c;
    }

    public String toString(){
        String repr = super.toString() + "\n CLASSES: \n" ;//using the old method but adding in information
        for (int i = 0; i< classes.length; i++){ //for loops are the same as in C
            repr += classes[i] + "\n";
        }
        return repr; //returns the string representation
    }

    public static void main (String[] args){
        String[] classes = new String[] {"Introduction to Maths", "Management for Computing", "Programming 1"};
        Student s = new Student("Pramod", 50, classes);
        s.setAge(59);
        System.out.println(s);
    }//student has inherited classes, the constructer to handle the name and age
}  