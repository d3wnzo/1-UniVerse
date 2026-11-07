package com.papayaseed.controllers;

import javafx.fxml.FXML;
import javafx.scene.control.*;

public class AdminChatController {

    @FXML
    private ListView<String> listChats;

    @FXML
    private TextArea txtReply;

    @FXML
    private Label lblStatus;

    @FXML
    public void initialize() {
        listChats.getItems().addAll(
                "user1: Kak stok pepaya california masih ada?",
                "user2: Bibit ini bisa COD ga?",
                "user3: Harga per pak isi berapa?"
        );
    }

    @FXML
    private void handleReply() {
        if (listChats.getSelectionModel().getSelectedItem() == null) {
            lblStatus.setText("Pilih chat yang mau dibalas!");
            return;
        }

        if (txtReply.getText().trim().isEmpty()) {
            lblStatus.setText("Isi dulu pesan balasan!");
            return;
        }

        lblStatus.setText("Balasan terkirim!");
        txtReply.clear();
    }
}
