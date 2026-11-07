package tokoprinter;

public class InkjetPrinter extends Printer { // <-- extends Printer
    private int jumlahWarna;

    public InkjetPrinter(String nama, float harga, String merk, String tipe, int jumlahWarna) {
        super(nama, harga, merk, tipe); // <-- SUPER
        this.jumlahWarna = jumlahWarna;
    }

    //  KONSEP OVERRIDING (METHOD ANAK) -->
    @Override
    public void printDocuments() {
        if (super.documents == null || super.documents.length == 0) {
            System.out.println("!! Tidak ada dokumen yang disiapkan untuk printer Inkjet.");
            return;
        }
        System.out.println("\n===== Printer Inkjet Mulai Mencetak =====");
        System.out.println("Mencetak dokumen berwarna dengan " + this.jumlahWarna + " tinta...");
        for (String doc : super.documents) {
            System.out.println("- Mencetak '" + doc + "'...");
        }
        System.out.println("=======================================");
    }

    public void showInkDetails() {
        System.out.println("Jumlah Warna Tinta: " + this.jumlahWarna);
    }

    @Override // <-- OVERRIDE
    public void displayPrinterDetails() {
        super.displayPrinterDetails(); // <-- SUPER
        this.showInkDetails();
    }
}