public class Main {
    
    public static void main(String[] args) {
        Handphone[] daftarHandphone = new Handphone[2];

        daftarHandphone[0] = new Smartphone(" Sharp", "Aquos Damar");
        daftarHandphone[1] = new FeaturePhone(" Poco", "M6 Bob");

        for (Handphone hp : daftarHandphone) {
            hp.nyalakan();
            hp.telepon(" 081617392767");
            hp.matikan();
            System.out.println();
        }

        for (Handphone hp : daftarHandphone) {
            if (hp instanceof Smartphone) {
                ((Smartphone) hp).aksesInternet();
            } else if (hp instanceof FeaturePhone) {
                ((FeaturePhone) hp).mainGameSnake();
            }
        }
    }
}