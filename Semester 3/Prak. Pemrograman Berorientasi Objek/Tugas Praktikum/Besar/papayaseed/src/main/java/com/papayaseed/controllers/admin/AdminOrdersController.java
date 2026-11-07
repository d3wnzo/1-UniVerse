package com.papayaseed.controllers;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;

public class AdminOrdersController {

    @FXML
    private ListView<String> listOrders;

    @FXML
    private Label lblStatus;

    @FXML
    public void initialize() {
        listOrders.getItems().addAll(
                "Order #001 - user1@gmail.com - Menunggu Konfirmasi",
                "Order #002 - user2@gmail.com - Diproses",
                "Order #003 - user3@gmail.com - Dikirim"
        );
    }

    @FXML
    private void handleUpdateStatus() {
        String selected = listOrders.getSelectionModel().getSelectedItem();

        if (selected == null) {
            lblStatus.setText("Pilih order terlebih dahulu!");
            return;
        }

        lblStatus.setText("Status pesanan diperbarui!");
    }
}
