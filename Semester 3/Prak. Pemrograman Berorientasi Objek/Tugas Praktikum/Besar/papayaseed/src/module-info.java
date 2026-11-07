module PapayaSeed {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;

    opens com.papayaseed.controllers to javafx.fxml;
    opens com.papayaseed.models to javafx.base;

    exports com.papayaseed;
}
