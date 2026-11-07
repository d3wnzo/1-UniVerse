package com.papayaseed.controllers.user;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

public class LoginController {

    @FXML
    private TextField txtUsername;

    @FXML
    private PasswordField txtPassword;

    @FXML
    private Label lblStatus;

    @FXML
    public void handleLogin(ActionEvent event) {
        String username = txtUsername.getText();
        String password = txtPassword.getText();

        if (username.isEmpty() || password.isEmpty()) {
            lblStatus.setText("Username dan password wajib diisi!");
            return;
        }

        // LOGIN SEMENTARA (dummy)
        if (username.equals("user") && password.equals("123")) {
            lblStatus.setText("Login berhasil!");
            openHome();
        } else {
            lblStatus.setText("Username atau password salah!");
        }
    }

    private void openHome() {
        try {
            FXMLLoader loader = new FXMLLoader(
                    getClass().getResource("/com/papayaseed/fxml/user/Home.fxml")
            );
            Stage stage = new Stage();
            stage.setScene(new Scene(loader.load()));
            stage.setTitle("PapayaSeed - Home");
            stage.show();

            // tutup halaman login
            txtUsername.getScene().getWindow().hide();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
