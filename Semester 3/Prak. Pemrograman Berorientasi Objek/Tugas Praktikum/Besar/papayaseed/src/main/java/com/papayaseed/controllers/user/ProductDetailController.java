package com.papayaseed.controllers.user;

import javafx.fxml.FXML;
import javafx.scene.control.Label;

public class ProductDetailController {

    @FXML
    private Label lblProductName;

    @FXML
    private Label lblPrice;

    @FXML
    private Label lblDescription;

    @FXML
    public void initialize() {
        // DATA DUMMY
        lblProductName.setText("Bibit Pepaya California");
        lblPrice.setText("Harga: Rp 15.000");
        lblDescription.setText(
                "Bibit pepaya unggulan dengan pertumbuhan cepat, " +
                "buah besar, dan cocok ditanam di iklim tropis."
        );
    }
}
