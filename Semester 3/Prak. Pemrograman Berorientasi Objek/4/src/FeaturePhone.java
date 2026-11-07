public class FeaturePhone extends Handphone {
    public FeaturePhone (String merk, String model) {
        super (merk, model);
    }

    @Override
    public void nyalakan () {
        System.out.println("Feature Phone" + merk + " " + model + " Dinyalakan.");
    }

    @Override
    public void matikan () {
        System.out.println("Feature Phone" + merk + " " + model + " Dimatikan.");
    }

    @Override
    public void telepon (String nomor) {
        System.out.println("Melakukan panggilan suara ke nomor" + nomor);
    }

    public void mainGameSnake() {
        System.out.println("Mainkan game Snake.");
    }
}