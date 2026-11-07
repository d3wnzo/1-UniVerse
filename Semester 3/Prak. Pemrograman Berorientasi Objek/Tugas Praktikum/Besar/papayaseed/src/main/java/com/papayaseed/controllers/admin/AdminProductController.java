package com.papayaseed.controllers;

import javafx.fxml.FXML;
import javafx.scene.control.*;

public class AdminProductController {

    @FXML
    private TextField txtName;

    @FXML
    private TextField txtPrice;

    @FXML
    private TextField txtStock;

    @FXML
    private ListView<String> listProducts;

    @FXML
    private Label lblStatus;

    @FXML
    public void initialize() {
        // Contoh produk awal
        listProducts.getItems().addAll(
                "Pepaya California - Rp 10.000 - Stok: 50",
                "Pepaya Seed Premium - Rp 20.000 - Stok: 30"
        );
    }

    @FXML
    private void handleAddProduct() {
        String name = txtName.getText().trim();
        String price = txtPrice.getText().trim();
        String stock = txtStock.getText().trim();

        if (name.isEmpty() || price.isEmpty() || stock.isEmpty()) {
            lblStatus.setText("Semua field harus diisi!");
            return;
        }

        listProducts.getItems().add(name + " - Rp " + price + " - Stok: " + stock);
        lblStatus.setText("Produk berhasil ditambahkan!");
        clearFields();
    }

    @FXML
    private void handleDeleteProduct() {
        String selected = listProducts.getSelectionModel().getSelectedItem();
        if (selected == null) {
            lblStatus.setText("Pilih produk yang ingin dihapus!");
            return;
        }

        listProducts.getItems().remove(selected);
        lblStatus.setText("Produk berhasil dihapus!");
    }

    private void clearFields() {
        txtName.clear();
        txtPrice.clear();
        txtStock.clear();
    }
}
