package logic;

import data.Catatan;

public class CatatanManager {
    public void tampilkan(Catatan catatan) {
        System.out.println("===== Catatan Harian =====");
        catatan.tampilkanCatatan();
        System.out.println("==========================");
    }
}
