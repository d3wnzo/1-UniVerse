package tokoprinter;

public class LaserPrinter extends Printer { // <-- extends 
    private int kecepatanCetak;

    public LaserPrinter(String nama, float harga, String merk, String tipe, int kecepatanCetak) {
        super(nama, harga, merk, tipe); // <-- SUPER
        this.kecepatanCetak = kecepatanCetak;
    }

// <-- TAMBAHAN: KONSEP OVERRIDING (METHOD ANAK) -->
    @Override
    public void printDocuments() {
        if (super.documents == null || super.documents.length == 0) {
            System.out.println("!! Tidak ada dokumen yang disiapkan untuk printer Laser.");
            return;
        }
        System.out.println("\n===== Printer Laser Mulai Mencetak =====");
        System.out.println("Mencetak dokumen dengan kecepatan " + this.kecepatanCetak + " ppm...");
        for (String doc : super.documents) {
            System.out.println("- Mencetak '" + doc + "'...");
        }
        System.out.println("======================================");
    }
    public void showLaserDetails() {
        System.out.println("Kecepatan Cetak: " + this.kecepatanCetak + " ppm");
    }

    @Override // <-- HIGHLIGHT ANOTASI INI
    public void displayPrinterDetails() {
        super.displayPrinterDetails(); // <-- SUPER
        this.showLaserDetails();
    }
}