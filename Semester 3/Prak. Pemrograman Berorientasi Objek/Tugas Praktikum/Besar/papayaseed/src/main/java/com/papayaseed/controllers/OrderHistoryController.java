package com.papayaseed.controllers;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;

public class OrderHistoryController {

    @FXML
    private ListView<String> listOrderHistory;

    @FXML
    private Label lblStatus;

    @FXML
    public void initialize() {
        // Simulasi data history sementara
        listOrderHistory.getItems().addAll(
                "Order #001 - Rp 35.000 - Selesai",
                "Order #002 - Rp 75.000 - Dikirim",
                "Order #003 - Rp 120.000 - Diproses"
        );
    }
}
