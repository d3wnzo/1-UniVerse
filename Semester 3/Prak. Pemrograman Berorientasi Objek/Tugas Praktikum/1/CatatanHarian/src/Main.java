import data.Catatan;
import data.Pengguna;
import java.util.Scanner;
import logic.CatatanManager;
import logic.ValidasiManager;

public class Main {
    public static void main(String[] args) {
        try (Scanner input = new Scanner(System.in)) {
            Pengguna user = new Pengguna("krisna", "12345");

            ValidasiManager validator = new ValidasiManager();

            System.out.print("Masukkan username: ");
            String username = input.nextLine();

            System.out.print("Masukkan password: ");
            String password = input.nextLine();

            boolean isValid = validator.validasiLogin(user, username, password);

            if (isValid) {
                Catatan c1 = new Catatan("5 Oktober 2025", "Hari ini belajar validasi Java.");
                CatatanManager manager = new CatatanManager();
                manager.tampilkan(c1);
            }

            input.close();
        }
    }
}