package data;

public class Catatan {
    private String tanggal;
    private String isi;

    public Catatan() {
        this.tanggal = "Belum diisi";
        this.isi = "Belum ada catatan";
    }

    public Catatan(String tanggal, String isi) {
        this.tanggal = tanggal;
        this.isi = isi;
    }

    public String getTanggal() {
        return tanggal;
    }

    public String getIsi() {
        return isi;
    }

    public void setTanggal(String tanggal) {
        this.tanggal = tanggal;
    }

    public void setIsi(String isi) {
        this.isi = isi;
    }

    public void tampilkanCatatan() {
        System.out.println("Tanggal: " + tanggal);
        System.out.println("Isi: " + isi);
    }
}