package com.papayaseed.controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;

public class PaymentController {

    @FXML
    private TextField txtFullName;

    @FXML
    private TextArea txtAddress;

    @FXML
    private ComboBox<String> cbPaymentMethod;

    @FXML
    private Label lblTotalPrice;

    @FXML
    private Label lblStatus;

    @FXML
    private VBox containerSummary;

    private double totalPrice = 0;

    // Method untuk set total harga dari halaman Cart
    public void setTotalPrice(double total) {
        this.totalPrice = total;
        lblTotalPrice.setText("Rp " + String.format("%,.0f", total));
    }

    @FXML
    public void initialize() {
        cbPaymentMethod.getItems().addAll(
                "Transfer Bank",
                "E-Wallet (Dana, OVO, Gopay)",
                "COD (Bayar di Tempat)"
        );
    }

    @FXML
    private void handleConfirmPayment(ActionEvent event) {
        String name = txtFullName.getText().trim();
        String address = txtAddress.getText().trim();
        String method = cbPaymentMethod.getValue();

        if (name.isEmpty() || address.isEmpty() || method == null) {
            lblStatus.setText("Semua data harus diisi!");
            return;
        }

        if (totalPrice <= 0) {
            lblStatus.setText("Keranjang kosong!");
            return;
        }

        // Belum pakai DB → jadi cuma simulasi sukses
        lblStatus.setText("Pembayaran Berhasil! Pesanan sedang diproses.");
        clearFields();
    }

    private void clearFields() {
        txtFullName.clear();
        txtAddress.clear();
        cbPaymentMethod.setValue(null);
    }
}
