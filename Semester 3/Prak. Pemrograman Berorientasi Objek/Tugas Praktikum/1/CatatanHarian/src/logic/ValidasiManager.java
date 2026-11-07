package logic;

import data.Pengguna;

public class ValidasiManager {

    public boolean validasiLogin(Pengguna pengguna, String inputUser, String inputPass) {
        if (pengguna.getUsername().equals(inputUser) && pengguna.getPassword().equals(inputPass)) {
            System.out.println("✅ Login berhasil! Selamat datang, " + inputUser);
            return true;
        } else {
            System.out.println("❌ Login gagal! Username atau password salah.");
            return false;
        }
    }
}