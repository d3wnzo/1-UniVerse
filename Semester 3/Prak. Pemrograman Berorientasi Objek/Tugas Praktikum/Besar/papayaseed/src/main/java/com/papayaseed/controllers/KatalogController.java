package com.papayaseed.controllers;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import com.papayaseed.controllers.CartController;


public class KatalogController {

    @FXML
    private VBox productList;

    @FXML
    public void initialize() {
        loadProducts();
    }

    private void loadProducts() {
        // Contoh: data produk hardcode dulu
        addProduct("Pepaya California", "Bibit unggul cepat panen", 15000);
        addProduct("Pepaya Bangkok", "Ukuran besar cocok untuk budidaya", 20000);
        addProduct("Pepaya Red Lady", "Cepat berbuah, daging merah", 18000);
    }

    private void addProduct(String name, String desc, int price) {
        Label lblName = new Label(name);
        lblName.setStyle("-fx-font-size: 18; -fx-font-weight: bold;");

        Label lblDesc = new Label(desc);
        lblDesc.setStyle("-fx-font-size: 14;");

        Label lblPrice = new Label("Rp " + price);
        lblPrice.setStyle("-fx-font-size: 16; -fx-text-fill: #e6952f; -fx-font-weight: bold;");

        Button btnAdd = new Button("Tambah ke Keranjang");
        btnAdd.setStyle("-fx-background-color: #e6952f; -fx-text-fill: white; -fx-padding: 8 15;");
        btnAdd.setOnAction(e -> {
    CartController.addToCart(name, price);
    System.out.println(name + " ditambah ke keranjang!");
});

        VBox container = new VBox(lblName, lblDesc, lblPrice, btnAdd);
        container.setSpacing(5);
        container.setStyle("-fx-padding: 15; -fx-border-color: #e6952f; -fx-border-radius: 10;");
        
        productList.getChildren().add(container);
    }
}
