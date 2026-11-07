package tokoprinter.app;

import tokoprinter.InkjetPrinter;
import tokoprinter.LaserPrinter;

public class Main {
    public static void main(String[] args) {
        System.out.println("===== MEMBUAT OBJEK INKJET PRINTER =====");
        InkjetPrinter printer1 = new InkjetPrinter(
            "Epson L3210", 
            2300000f, 
            "Epson", 
            "Ink Tank", 
            4
        );

        printer1.displayInfo();
        System.out.println("\n--- Memanggil displayInfo() ---");
        // <-- PANGGIL METHOD BARU (OVERLOADING & OVERRIDING) -->
        System.out.println("\n--- Uji Coba Polimorfisme pada Inkjet Printer ---");
        printer1.setDocuments("Laporan Praktikum.pdf"); // Panggil overloading 1
        printer1.printDocuments(); // Panggil method overriding punya InkjetPrinter

        printer1.setDocuments(new String[]{"Tugas Akhir.docx", "Revisi Bab 1.docx", "Presentasi.pptx"}); // Panggil overloading 2
        printer1.printDocuments(); // Panggil method overriding punya InkjetPrinter


        System.out.println("\n========================================\n");
        System.out.println("\n--- Memanggil displayPrinterDetails() ---");
        printer1.displayPrinterDetails();
        
        System.out.println("\n--- Memanggil showInkDetails() ---");
        printer1.showInkDetails();

        System.out.println("\n========================================\n");

        System.out.println("===== MEMBUAT OBJEK LASER PRINTER =====");
        LaserPrinter printer2 = new LaserPrinter(
            "HP LaserJet M111w", 
            2150000f, 
            "HP", 
            "Monochrome Laser", 
            22
        );

        printer2.displayInfo();
        System.out.println("\n--- Memanggil displayInfo() ---");
        // <-- PANGGIL METHOD BARU (OVERLOADING & OVERRIDING) -->
        System.out.println("\n--- Uji Coba Polimorfisme pada Laser Printer ---");
        printer2.setDocuments("Surat Lamaran Kerja.pdf"); // Panggil overloading 1
        printer2.printDocuments(); // Panggil method overriding punya LaserPrinter
        
        System.out.println("\n--- Memanggil displayPrinterDetails() ---");
        printer2.displayPrinterDetails();
        
        System.out.println("\n--- Memanggil showLaserDetails() ---");
        printer2.showLaserDetails();
    }
}