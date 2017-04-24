abstract class Fruit {
    protected String brand;

    abstract public void show();
}

class Apple extends Fruit {
    public Apple() {
        brand = "hong fu shi";
    }

    public void show() {
        System.out.println(brand);
    }
}

class Banane extends Fruit {
    public Banane() {
        brand = "hai nan";
    }

    public void show() {
        System.out.println(brand);
    }
}

class Pear extends Fruit {
    public Pear() {
        brand = "li zi";
    }

    public void show() {
        System.out.println(brand);
    }
}


public class DynamicBind {
    public static void main(String[] args) {
        Fruit a;
        a = new Apple();
        a.show();
        a = new Banane();
        a.show();
        a =new Pear();
        a.show();
    }
}