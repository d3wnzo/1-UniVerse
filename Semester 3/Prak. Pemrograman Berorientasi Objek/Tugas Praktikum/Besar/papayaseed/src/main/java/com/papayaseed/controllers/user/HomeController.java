package com.papayaseed.controllers.user;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;

import java.util.ArrayList;
import java.util.List;

public class HomeController {

    @FXML
    private Label lblWelcome;

    @FXML
    private ListView<String> listProducts;

    @FXML
    public void initialize() {
        lblWelcome.setText("Selamat Datang di PapayaSeed 🌱");

        // DATA DUMMY (karena DB belum dipakai)
        List<String> products = new ArrayList<>();
        products.add("Bibit Pepaya California - Rp 15.000");
        products.add("Bibit Pepaya Hawai - Rp 18.000");
        products.add("Bibit Pepaya Thailand - Rp 20.000");

        listProducts.getItems().addAll(products);
    }
}
