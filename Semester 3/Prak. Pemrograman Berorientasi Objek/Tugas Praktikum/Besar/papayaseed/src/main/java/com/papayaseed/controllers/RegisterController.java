package com.papayaseed.controllers.user;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;

public class RegisterController {

    @FXML
    private TextField txtUsername;

    @FXML
    private TextField txtEmail;

    @FXML
    private PasswordField txtPassword;

    @FXML
    private PasswordField txtConfirm;

    @FXML
    private Label lblStatus;

    @FXML
    public void handleRegister(ActionEvent event) {
        String username = txtUsername.getText();
        String email = txtEmail.getText();
        String pass = txtPassword.getText();
        String confirm = txtConfirm.getText();

        if (username.isEmpty() || email.isEmpty() || pass.isEmpty() || confirm.isEmpty()) {
            lblStatus.setText("Semua field wajib diisi!");
            return;
        }

        if (!pass.equals(confirm)) {
            lblStatus.setText("Password tidak sama!");
            return;
        }

        // DUMMY REGISTER (DB NYUSUL)
        lblStatus.setText("Registrasi berhasil! Silakan login.");

        clearField();
    }

    private void clearField() {
        txtUsername.clear();
        txtEmail.clear();
        txtPassword.clear();
        txtConfirm.clear();
    }
}
