package com.papayaseed.controllers.user;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;

public class CartController {

    @FXML
    private ListView<String> listCart;

    @FXML
    private Label lblTotal;

    private ObservableList<String> cartItems = FXCollections.observableArrayList();

    @FXML
    public void initialize() {
        // DATA DUMMY KERANJANG
        cartItems.add("Bibit Pepaya California - Rp 15.000");
        cartItems.add("Bibit Pepaya Hawai - Rp 18.000");

        listCart.setItems(cartItems);

        updateTotal();
    }

    private void updateTotal() {
        // TOTAL DUMMY
        lblTotal.setText("Total: Rp 33.000");
    }
}
