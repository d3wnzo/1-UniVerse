package com.papayaseed.controllers.user;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.Label;

public class CheckoutController {

    @FXML
    private ChoiceBox<String> cbPayment;

    @FXML
    private Label lblStatus;

    @FXML
    public void initialize() {
        cbPayment.getItems().addAll(
                "Transfer Bank",
                "E-Wallet",
                "COD"
        );
    }

    @FXML
    public void handlePay(ActionEvent event) {
        String method = cbPayment.getValue();

        if (method == null) {
            lblStatus.setText("Pilih metode pembayaran!");
            return;
        }

        // DUMMY PAYMENT
        lblStatus.setText("Pembayaran berhasil menggunakan " + method);
    }
}
