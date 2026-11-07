package tokoprinter;

public class Product {
    protected String nama;
    protected float harga;

    public Product(String nama, float harga) {
        this.nama = nama;
        this.harga = harga;
    }

    public void displayInfo() {
        System.out.println("===== Detail Produk =====");
        System.out.println("Nama : " + this.nama);
        System.out.println("Harga: " + this.harga);
    }
} 