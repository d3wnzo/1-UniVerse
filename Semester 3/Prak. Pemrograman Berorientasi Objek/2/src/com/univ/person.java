package com.univ;
public class person {
    private String name;
    private int age;
    private final String address;

    public person(String name, int age, String address) {
        this.name = name;
        this.age = age;
        this.address = address;
    }

    public void displayInfo () {
        System.out.println("Name:" + this.name);
        System.out.println("age:" + this.age);
        System.out.println("address:" + this.address);
        System.out.println();
    }

    public void setname(String name) {
        this.name = name;
    }

    public String getname() {
        return this.name;
    }

    public void setage(int age) {
        this.age = age;
    }

    public int getage(int age) {
        return this.age;
    }
}