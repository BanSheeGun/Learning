interface Guard {
    public void guard();
    public String fangdao = "fang dao 10 nian";
}

interface Alarm {
    public void alarm();
}

abstract class Door {
    abstract public void open();
    abstract public void close();
}

class AlarmGuardDoor extends Door implements Guard, Alarm {
    public void open() {
        System.out.println("Open the door!");
    }

    public void close() {
        System.out.println("Close the door");
    }

    public void guard() {
        System.out.println(fangdao);
    }

    public void alarm() {
        System.out.println("BAO JING!");
    }
}

public class InterfaceDemo {
    public static void main(String[] args) {
        AlarmGuardDoor a = new AlarmGuardDoor();
        a.open();
        a.close();
        a.alarm();
        a.guard();
    }
}