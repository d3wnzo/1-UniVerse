package com.univ;

public class main {
    public static void main(String[] args) {
        person person1 = new person("otnay", 24, "Jl. jalan");
        person1.displayInfo();

        person1.setname(" otnay");
        person1.setage(24);

        System.out.println("Informasi Baru: ");
        person1.displayInfo();
    }
}