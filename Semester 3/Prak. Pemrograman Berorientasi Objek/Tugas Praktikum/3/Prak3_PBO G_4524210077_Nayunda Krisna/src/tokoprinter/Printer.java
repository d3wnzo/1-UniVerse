package tokoprinter;
import java.util.Arrays;

public class Printer extends Product { // <--extends Product
    protected String merk;
    protected String tipe;
    protected String[] documents; // <-- TAMBAHAN untuk menyimpan dokumen

    public Printer(String nama, float harga, String merk, String tipe) {
        super(nama, harga); // <-- SUPER
        this.merk = merk;
        this.tipe = tipe;
    }

    //  KONSEP OVERLOADING 1
    public void setDocuments(String document) {
        this.documents = new String[]{document};
        System.out.println(">> Dokumen '" + document + "' telah disiapkan.");
    }

    // KONSEP OVERLOADING 2
    // Method dengan nama sama tapi parameter berbeda (array)
    public void setDocuments(String[] documents) {
        this.documents = documents;
        System.out.println(">> " + documents.length + " dokumen telah disiapkan: " + Arrays.toString(documents));
    }

    // KONSEP OVERRIDING (METHOD INDUK)
    // Method ini akan ditimpa oleh child class
    public void printDocuments() {
        if (this.documents == null || this.documents.length == 0) {
            System.out.println("!! Tidak ada dokumen yang disiapkan untuk dicetak.");
            return;
        }
        System.out.println("Mencetak dokumen standar...");
        for (String doc : this.documents) {
            System.out.println("- " + doc);
        }
    }
    
    public void displayPrinterDetails() {
        System.out.println("Merk : " + this.merk);
        System.out.println("Tipe : " + this.tipe);
    }

    @Override // <-- OVERRIDE
    public void displayInfo() {
        super.displayInfo(); // <-- SUPER
        this.displayPrinterDetails();
    }
}