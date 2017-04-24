interface Guard {
    public void alarm();
    public String fangdao = "fang dao 10 nian";
}

abstract class Door {
    abstract public void open();
    abstract public void close();
}

class AlarmGuardDoor extends Door implements Guard {
    public void open() {
        System.out.println("Open the door!");
    }

    public void close() {
        System.out.println("Close the door");
    }

    public void alarm() {
        System.out.println(fangdao);
    }
}

public class InterfaceDemo {
    public static void main(String[] args) {
        AlarmGuardDoor a = new AlarmGuardDoor();
        a.open();
        a.close();
        a.alarm();
    }
}