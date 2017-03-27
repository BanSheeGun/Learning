public class A {
    int  age;

    public A (String E) {
        System.out.println(E);
    }

    public void changeA(int a) {
        age = a;
    }

    public static void main(String []args) {
        A a = new A("CCC");
        A b = new A("CCC");
        a.age = 1;
        System.out.println(a.age);
        a.changeA(2);
        System.out.println(a.age);
        b.changeA(1);
        System.out.println(a.age);
    }
}