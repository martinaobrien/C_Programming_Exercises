public class PersonApp {
//when two folders are in the same folder they can refer to each other
//have to go through the mutator method
//you can access the private methods
        public static void main (String[] args){
        Person a = new Person ("John", 23);
        Person b = new Person ("Paul", 51);
        System.out.println(a);
        //a.age = -1; //error age has private access in Person - show encapsulation or data hiding
        a.setAge(-1);
        System.out.println(a);
        System.out.println(b);
    }

}