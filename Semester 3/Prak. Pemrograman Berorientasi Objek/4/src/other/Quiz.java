public class Quiz {
    public static void main(String[] args) {
        Hewan h1 = new Burung();
        Hewan h2 = new Anjing();

        h1.suara();
        h2.suara();
    }
}

class Hewan {
    public void suara() {
        System.out.println("Hewan Bersuara Umum");
    }
}

class Burung extends Hewan {
    public void suara() {
        System.out.println("Burung Berkicau");
    }
}

class Anjing extends Hewan {
    public void suara() {
        System.out.println("Anjing Menggonggong");
    }
}