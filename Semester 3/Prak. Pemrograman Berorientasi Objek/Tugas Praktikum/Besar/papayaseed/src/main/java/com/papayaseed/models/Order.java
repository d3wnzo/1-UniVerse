package com.papayaseed.models;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class Order {
    private int id;
    private Customer customer;
    private LocalDateTime date;
    private List<OrderItem> items;

    public Order() {
        items = new ArrayList<>();
        date = LocalDateTime.now();
    }

    public Order(int id, Customer customer) {
        this.id = id;
        this.customer = customer;
        this.date = LocalDateTime.now();
        this.items = new ArrayList<>();
    }

    public int getId() { return id; }
    public void setId(int id) { this.id = id; }

    public Customer getCustomer() { return customer; }
    public void setCustomer(Customer customer) { this.customer = customer; }

    public LocalDateTime getDate() { return date; }
    public void setDate(LocalDateTime date) { this.date = date; }

    public List<OrderItem> getItems() { return items; }

    public void addItem(OrderItem item) {
        this.items.add(item);
    }

    public double getTotal() {
        return items.stream().mapToDouble(OrderItem::getSubtotal).sum();
    }
}
