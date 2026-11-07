package com.papayaseed.controllers;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class ProfileController {

    @FXML
    private TextField txtUsername;

    @FXML
    private TextField txtEmail;

    @FXML
    private Label lblStatus;

    @FXML
    public void initialize() {
        // Simulasi data user (belum pakai database)
        txtUsername.setText("user_papaya");
        txtEmail.setText("user@gmail.com");
    }

    @FXML
    private void handleUpdateProfile() {
        String username = txtUsername.getText().trim();
        String email = txtEmail.getText().trim();

        if (username.isEmpty() || email.isEmpty()) {
            lblStatus.setText("Field tidak boleh kosong!");
            return;
        }

        // Simulasi update
        lblStatus.setText("Profil berhasil diperbarui!");
    }
}
